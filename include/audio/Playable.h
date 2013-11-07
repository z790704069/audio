#pragma once

#include <memory>

namespace audio
{

class Sound;
class Channel;
struct SoundParams;

/*! Something that can be played.
 */
class Playable
{
public:
    virtual ~Playable() {}

    virtual auto play(Channel& _channel, const SoundParams& _state) -> std::unique_ptr<Sound> = 0;
};

}
