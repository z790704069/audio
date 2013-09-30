#pragma once

#include <audio/Context.h>
#include <audio/ChannelBank.h>
#include <audio/SoundParams.h>

namespace audio
{

class Playable;
class Sound;

class SoundSystem
{
public:
    SoundSystem();

    std::shared_ptr<Sound> play(Playable& playable, const SoundParams& params = SoundParams());

    bool isBusy(); // TODO: debug feature ... remove this

private:
    Context context_;
    ChannelBank channelBank_;
};

}
