#pragma once

#include <audio/Context.h>
#include <audio/ChannelBank.h>
#include <audio/SoundParams.h>

namespace audio
{

class Playable;
class Sound;

/*!
 * \brief The SoundSystem class centralizes all responsibilities for audio
 * playback, in particular:
 *      * Context creation
 *      * Channel management
 *      * Streaming thread handling
 */
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
