#pragma once

#include <audio/Sound.h>

namespace audio
{

struct SoundParams;
class Buffer;

/*!
 * \brief A sound that was played from a Buffer
 */
class BufferedSound : public Sound
{
public:
    BufferedSound(Channel* _channel, const SoundParams& _params, const Buffer& _buffer);
};

}
