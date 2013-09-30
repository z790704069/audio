#include <audio/Buffer.h>
#include <audio/BufferedSound.h>
#include <audio/util/make_unique.h>

#include <AL/al.h>

#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstdlib>

namespace audio
{

Buffer::Buffer()
{
    alGenBuffers(1, &buffer_);

    // DEBUG: upload some data
    /*
    std::vector<uint16_t> data(1 * 44100);
    std::generate(data.begin(), data.end(), std::rand);
    alBufferData(buffer_, AL_FORMAT_MONO16, data.data(), data.size() * sizeof(uint16_t), 44100);
    */
}

Buffer::~Buffer()
{
    alDeleteBuffers(1, &buffer_);
}

void Buffer::loadFromWAV(const std::string& filename)
{
    auto fileStream = std::ifstream(filename.c_str(), std::ios::in | std::ios::binary);

    if(fileStream.is_open() && fileStream.good())
    {
        uint8_t identifier[4];
        uint16_t formatTag, channels, blockAlign, bitsPerSample;
        uint32_t fileSize, formatLength, sampleRate, bytesPerSecond, dataSize;

        fileStream.read((char*)identifier, 4); // "RIFF"
        if(strncmp((char*)identifier, "RIFF", 4))
        {
            std::cerr << filename << " is not a RIFF file" << std::endl;
        }

        fileStream.read((char*)&fileSize, 4);

        fileStream.read((char*)identifier, 4); // "WAVE"
        if(strncmp((char*)identifier, "WAVE", 4))
        {
            std::cerr << filename << " contains no WAVE section" << std::endl;
        }

        fileStream.read((char*)identifier, 4); // "fmt "
        if(strncmp((char*)identifier, "fmt ", 4))
        {
            std::cerr << filename << ": expected fmt chunk not found" << std::endl;
        }

        fileStream.read((char*)&formatLength, 4);
        fileStream.read((char*)&formatTag, 2);
        fileStream.read((char*)&channels, 2);
        fileStream.read((char*)&sampleRate, 4);
        fileStream.read((char*)&bytesPerSecond, 4);
        fileStream.read((char*)&blockAlign, 2);
        fileStream.read((char*)&bitsPerSample, 2);

        // skip ahead if there is additional fmt header information (default length: 16)
        if(formatLength - 16u > 0)
        {
            fileStream.ignore(formatLength - 16u);
        }

        // skip over any additional chunks until we find the "data" chunk
        fileStream.read((char*)identifier, 4);
        while(strncmp((char*)identifier, "data", 4))
        {
            // no "data" chunk, read the size and skip ahead
            uint32_t chunkSize;
            fileStream.read((char*)&chunkSize, 4);
            fileStream.ignore(chunkSize);

            // read the next chunk identifier
            if(!fileStream.good())
            {
                std::cerr << filename << ": reachend end of file without finding data chunk" << std::endl;
            }
            else
            {
                fileStream.read((char*)identifier, 4);
            }
        }
        // we are now in the data chunk

        fileStream.read((char*)&dataSize, 4);

        if(formatTag != 1)
        {
            std::cerr << filename << " contains non-PCM WAVE data" << std::endl;
        }

        ALenum alFormat = 0;
        if(bitsPerSample ==  8 && channels == 1) alFormat = AL_FORMAT_MONO8;
        if(bitsPerSample ==  8 && channels == 2) alFormat = AL_FORMAT_STEREO8;
        if(bitsPerSample == 16 && channels == 1) alFormat = AL_FORMAT_MONO16;
        if(bitsPerSample == 16 && channels == 2) alFormat = AL_FORMAT_STEREO16;
        if(alFormat == 0)
        {
            std::cerr << filename << ": audio format not supported by OpenAL: " << bitsPerSample << " bits/sample, " << channels << " channel(s)" << std::endl;
        }

        // Read the raw audio data and upload it to the OpenAL buffer
        auto waveData = std::vector<char>(dataSize);
        fileStream.read(waveData.data(), dataSize);

        alBufferData(buffer_, alFormat, waveData.data(), dataSize, sampleRate);

        /*
        ACGL::Utils::debug() << "formatTag: " << formatTag << std::endl;
        ACGL::Utils::debug() << "channels: " << channels << std::endl;
        ACGL::Utils::debug() << "blockAlign: " << blockAlign << std::endl;
        ACGL::Utils::debug() << "bitsPerSample: " << bitsPerSample << std::endl;
        ACGL::Utils::debug() << "fileSize: " << fileSize << std::endl;
        ACGL::Utils::debug() << "formatLength: " << formatLength << std::endl;
        ACGL::Utils::debug() << "sampleRate: " << sampleRate << std::endl;
        ACGL::Utils::debug() << "bytesPerSecond: " << bytesPerSecond << std::endl;
        ACGL::Utils::debug() << "dataSize: " << dataSize << std::endl;
        */
    }
    else
    {
        std::cerr << "Could not open " << filename << std::endl;
    }
}

std::unique_ptr<Sound> Buffer::play(Channel& channel, const SoundParams& params)
{
    return make_unique<BufferedSound>(&channel, params, *this);
}

}
