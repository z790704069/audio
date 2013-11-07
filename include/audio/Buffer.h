#pragma once

#include <audio/Playable.h>

#include <AL/al.h> // TODO: try to not expose this header

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

    auto loadFromWAV(const std::string& _filename) -> void; // TODO: move to audio::data::WAVStream

    virtual auto play(Channel& _channel, const SoundParams& _params) -> std::unique_ptr<Sound> override;

    inline auto getName() const -> ALuint { return buffer_; } // TODO: hide?

private:
    ALuint buffer_;
};

}
