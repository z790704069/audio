#include <audio/SoundSystem.h>
#include <audio/Playable.h>
#include <audio/Sound.h>

#include <cassert>

namespace audio
{

SoundSystem::SoundSystem() :
    context_{},
    channelBank_{}
{
}

std::shared_ptr<Sound> SoundSystem::play(Playable& _playable, const SoundParams& _params)
{
    Channel* freeChannel = channelBank_.getFreeChannel();
    if(freeChannel)
    {
        return freeChannel->play(_playable, _params);
    }
    else
    {
        assert(false); // TODO: error handling
        return std::shared_ptr<Sound>{};
    }
}

bool SoundSystem::isBusy()
{
    return channelBank_.getNumFreeChannels() != channelBank_.getNumChannels();
}

}
