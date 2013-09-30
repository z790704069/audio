#include <audio/BufferedSound.h>
#include <audio/Buffer.h>
#include <audio/Channel.h>

#include <AL/al.h>

namespace audio
{

BufferedSound::BufferedSound(Channel* channel, const SoundParams& params, const Buffer& buffer) :
    Sound{channel, params}
{
    setBuffer(buffer);
    play();
}

void BufferedSound::setBuffer(const Buffer& buffer)
{
    if(isValid())
        alSourcei(channel_->getSource(), AL_BUFFER, buffer.getName());
}

}