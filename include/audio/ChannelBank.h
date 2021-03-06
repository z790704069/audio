#pragma once

#include <audio/Channel.h>

#include <vector>

namespace audio
{

/*!
 * \brief Manages a set of Channel%s
 */
class ChannelBank
{
public:
    ChannelBank(size_t _numChannels = 64);

    //! Returns the total number of Channel%s
    inline auto getNumChannels() const -> size_t { return channels_.size(); }

    //! Returns a pointer to a currently empty Channel or \c nullptr if there are no free channels
    auto getFreeChannel() -> Channel*; // TODO: also add a const alternative?

    //! Returns the number of currently free Channel%s
    auto getNumFreeChannels() const -> unsigned int;

private:
    std::vector<Channel> channels_;
};

}
