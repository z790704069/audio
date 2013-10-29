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
 * playback.
 *
 * These responsibilities are, in particular:
 *      - Context creation
 *      - Channel management
 *      - Streaming thread handling
 */
class SoundSystem
{
public:
    SoundSystem();

    /*!
     * \brief           Plays something Playable on this SoundSystem.
     * \param _playable Playable instance from which a Sound will be created
     * \param _params   optional initial parameters for the newly created Sound
     * \return          a shared Sound handle. If you want to manipulate the
     *                  Sound while it is playing, you should hold on to this
     *                  handle. Otherwise, you can just throw it away.
     */
    std::shared_ptr<Sound> play(Playable& _playable, const SoundParams& _params = SoundParams{});

    /*!
     * \brief   Whether any Sound is currently playing.
     * \return  true iff there is at least one Sound currently playing on this
     *          SoundSystem.
     */
    bool isBusy(); // TODO: debug feature ... remove this

private:
    Context context_;
    ChannelBank channelBank_;
};

}
