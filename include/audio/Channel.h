#pragma once

#include <audio/Sound.h>
#include <AL/al.h> // TODO: try to not expose this header
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
    Channel();                                     // ctor
    Channel(const Channel&) = delete;              // no copy ctor
    Channel(Channel&& _other) noexcept;            // move ctor
    ~Channel();                                    // dtor

    auto operator=(const Channel&) -> Channel& = delete;   // no copy-assignment
    auto operator=(Channel&& _other) noexcept -> Channel&; // move assignment

    //! Whether a sound is currently registered for this channel
    auto isOccupied() const -> bool;

    //! The sound currently registered for this channel
    auto getSound() const -> std::shared_ptr<Sound>;

    //! Starts playing a Playable object on this channel
    auto play(Playable& _playable, const SoundParams& _params) -> std::shared_ptr<Sound>;

private:
    //! The name of the OpenAL source used by this channel
    auto getSource() const -> ALuint { return source_; }

    auto updateSound() const -> void;

    auto allocateSource() -> void;
    auto deallocateSource() -> void;

    //! Resets sound_ to a new target and invalidates the previous target
    auto resetSound(Sound* _sound = nullptr) const -> void;

private:
    ALuint source_;
    bool sourceAllocated_; // TODO: use std::optional<ALuint> source_; instead?

    //! A pointer to the sound currently playing on this Channel. This pointer
    //! is shared with clients who want to manipulate the currently playing
    //! sound.
    mutable std::shared_ptr<Sound> sound_;
};

}
