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
    Format(Bitrate _bitrate, Channels _channels, unsigned int _frequency) :
        bitrate_(_bitrate),
        channels_(_channels),
        frequency_(_frequency)
    {
    }

    Bitrate bitrate_;
    Channels channels_;
    unsigned int frequency_;
};

}
}
