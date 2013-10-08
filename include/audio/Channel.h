#pragma once

#include <audio/Sound.h>
#include <AL/al.h>
#include <memory>

namespace audio
{

class Playable;
struct SoundParams;

/*!
 * \brief A single channel of a ChannelBank which is implemented using one
 *  OpenAL source. There may be a Sound currently playing on this channel.
 */
class Channel
{
    friend class Sound;

public:
    Channel();                                    // ctor
    Channel(const Channel&) = delete;             // no copy ctor
    Channel(Channel&& other) noexcept;            // move ctor

    Channel& operator=(const Channel&) = delete;  // no copy-assignment
    Channel& operator=(Channel&& other) noexcept; // move assignment

    ~Channel();                                   // dtor

    //! Whether a sound is currently registered for this channel
    bool isOccupied(); // TODO: should this be made const?

    //! The sound currently registered for this channel
    std::shared_ptr<Sound> getSound() { return sound_; }

    //! Starts playing a Playable object on this channel
    std::shared_ptr<Sound> play(Playable& playable, const SoundParams& params);

private:
    //! The name of the OpenAL source used by this channel
    ALuint getSource() const { return source_; }

    void allocateSource();
    void deallocateSource();

    //! Resets sound_ to a new target and invalidates the previous target
    void resetSound(Sound* sound = nullptr);

private:
    ALuint source_;
    bool sourceAllocated_; // TODO: use std::optional<ALuint> source_; instead?

    //! A pointer to the sound currently playing on this Channel. This pointer
    //! is shared with clients who want to manipulate the currently playing
    //! sound.
    std::shared_ptr<Sound> sound_;
};

}
