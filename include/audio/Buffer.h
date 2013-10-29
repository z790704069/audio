#pragma once

#include <audio/Playable.h>

#include <AL/al.h>

#include <string>
#include <memory>

namespace audio
{

/*! A playable chunk of audio data which is loaded entirely into memory
 */
class Buffer : public Playable
{
public:
    Buffer();
    virtual ~Buffer();

    void loadFromWAV(const std::string& _filename); // TODO: move to audio::data::WAVStream

    virtual std::unique_ptr<Sound> play(Channel& _channel, const SoundParams& _params);

    inline ALuint getName() const { return buffer_; } // TODO: hide?

private:
    ALuint buffer_;
};

}
