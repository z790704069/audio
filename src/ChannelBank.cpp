#include <audio/ChannelBank.h>
#include <algorithm>

namespace audio
{

// Functor for picking out free channels
bool isFree(Channel& channel)
{
    return !channel.isOccupied();
}

ChannelBank::ChannelBank(size_t numChannels) :
    channels_{numChannels}
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

unsigned int ChannelBank::getNumFreeChannels()
{
    return std::count_if(std::begin(channels_), std::end(channels_), isFree);
}

}
