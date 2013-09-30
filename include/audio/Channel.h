#pragma once

#include <audio/Sound.h>
#include <AL/al.h>
#include <memory>

namespace audio
{

class Playable;
struct SoundParams;

/*! \brief A single channel of a ChannelBank which is implemented using one
 *  OpenAL source. There may be a Sound currently playing on this channel.
 */
class Channel
{
public:
    Channel();                                    // ctor
    Channel(const Channel&) = delete;             // no copy ctor
    Channel(Channel&& other) noexcept;            // move ctor

    Channel& operator=(const Channel&) = delete;  // no copy-assignment
    Channel& operator=(Channel&& other) noexcept; // move assignment

    ~Channel();                                   // dtor

    //! The name of the OpenAL source used by this channel
    ALuint getSource() const { return source_; }

    //! Whether a sound is currently registered for this channel
    bool isOccupied(); // TODO: should this be made const?

    //! The sound currently registered for this channel
    std::shared_ptr<Sound> getSound() { return sound_; }

    std::shared_ptr<Sound> play(Playable& playable, const SoundParams& state);

private:
    void allocateSource();
    void deallocateSource();
    void resetSound(Sound* sound = nullptr);

    ALuint source_;
    bool sourceAllocated_;
    std::shared_ptr<Sound> sound_;
};

}
