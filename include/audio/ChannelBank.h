#pragma once

#include <audio/Channel.h>

#include <vector>

namespace audio
{

class ChannelBank
{
public:
    ChannelBank(size_t numChannels = 64);

    //! Returns the total number of channels
    inline size_t getNumChannels() const { return channels_.size(); }

    //! Returns a pointer to a currently empty Channel or nullptr if there are no free channels
    Channel* getFreeChannel();

    //! Returns the number of currently free channels
    unsigned int getNumFreeChannels();

private:
    std::vector<Channel> channels_;
};

}
