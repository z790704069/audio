#include <audio/BufferedSound.h>
#include <audio/Buffer.h>
#include <audio/Channel.h>

#include <AL/al.h>

namespace audio
{

BufferedSound::BufferedSound(Channel* _channel, const SoundParams& _params, const Buffer& _buffer) :
    Sound{_channel, _params}
{
    setBuffer(_buffer);
    play();
}

}
