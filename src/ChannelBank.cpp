#include <audio/ChannelBank.h>
#include <algorithm>

namespace audio
{

// Functor for picking out free channels
bool isFree(const Channel& channel)
{
    return !channel.isOccupied();
}

ChannelBank::ChannelBank(size_t _numChannels) :
    channels_{_numChannels}
{
}

Channel* ChannelBank::getFreeChannel()
{
    auto it = std::find_if(std::begin(channels_), std::end(channels_), isFree);
    if(it == std::end(channels_))
        return nullptr;
    else
        return &(*it);
}

unsigned int ChannelBank::getNumFreeChannels() const
{
    return std::count_if(std::begin(channels_), std::end(channels_), isFree);
}

}
