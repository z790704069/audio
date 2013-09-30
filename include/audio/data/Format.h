#pragma once

namespace audio
{
namespace data
{

enum Bitrate
{
    BITRATE_8 = 8,
    BITRATE_16 = 16
};

enum Channels
{
    CHANNELS_MONO = 1,
    CHANNELS_STEREO = 2
};

struct Format
{
    Format(Bitrate bitrate, Channels channels, unsigned int frequency) :
        bitrate_(bitrate),
        channels_(channels),
        frequency_(frequency)
    {
    }

    Bitrate bitrate_;
    Channels channels_;
    unsigned int frequency_;
};

}
}
