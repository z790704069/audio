#pragma once

#include <audio/Sound.h>

namespace audio
{

struct SoundParams;
class Buffer;

/*! A sound that was played from a Buffer
 */
class BufferedSound : public Sound
{
public:
    BufferedSound(Channel* channel, const SoundParams& params, const Buffer& buffer);

protected:
    void setBuffer(const Buffer& buffer);
};

}
