#include <audio/Sound.h>
#include <audio/Buffer.h>
#include <audio/Channel.h>
#include <audio/SoundParams.h>

#include <AL/al.h>

#include <cassert>

namespace audio
{

Sound::Sound(Channel* _channel, const SoundParams& _params) :
    channel_{_channel},
    pauseCounter_{0}
{
    setParams(_params);
}

void Sound::setParams(const SoundParams& _params)
{
    if(isValid())
    {
        auto source = channel_->getSource();

        alSourcef(source, AL_GAIN,               _params.gain_);
        alSourcef(source, AL_PITCH,              _params.pitch_);
        alSourcef(source, AL_SEC_OFFSET,         _params.timeOffset_);
        alSourcef(source, AL_MIN_GAIN,           _params.minGain_);
        alSourcef(source, AL_MAX_GAIN,           _params.maxGain_);
        alSourcef(source, AL_REFERENCE_DISTANCE, _params.referenceDistance_);
        alSourcef(source, AL_ROLLOFF_FACTOR,     _params.rolloffFactor_);
        alSourcef(source, AL_MAX_DISTANCE,       _params.maxDistance_);
        alSourcef(source, AL_CONE_INNER_ANGLE,   _params.coneInnerAngle_);
        alSourcef(source, AL_CONE_OUTER_ANGLE,   _params.coneOuterAngle_);
        alSourcef(source, AL_CONE_OUTER_GAIN,    _params.coneOuterGain_);

        alSourcei(source, AL_LOOPING,            _params.looping_ ? AL_TRUE : AL_FALSE);
        alSourcei(source, AL_SOURCE_RELATIVE,    _params.relative_ ? AL_TRUE : AL_FALSE);

        alSource3f(source, AL_POSITION,  _params.positionX_,  _params.positionY_,  _params.positionZ_);
        alSource3f(source, AL_VELOCITY,  _params.velocityX_,  _params.velocityY_,  _params.velocityZ_);
        alSource3f(source, AL_DIRECTION, _params.directionX_, _params.directionY_, _params.directionZ_);
    }
}

void Sound::setGain(float _gain)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_GAIN, _gain);
}

void Sound::setPitch(float _pitch)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_PITCH, _pitch);
}

void Sound::setTimeOffset(float _timeOffset)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_SEC_OFFSET, _timeOffset);
}

void Sound::setLooping(bool _looping)
{
    if(isValid())
        alSourcei(channel_->getSource(), AL_LOOPING, _looping ? AL_TRUE : AL_FALSE);
}

void Sound::setRelative(bool _relative)
{
    if(isValid())
        alSourcei(channel_->getSource(), AL_SOURCE_RELATIVE, _relative ? AL_TRUE : AL_FALSE);
}

void Sound::setMinGain(float _minGain)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_MIN_GAIN, _minGain);
}

void Sound::setMaxGain(float _maxGain)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_MAX_GAIN, _maxGain);
}

void Sound::setReferenceDistance(float _referenceDistance)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_REFERENCE_DISTANCE, _referenceDistance);
}

void Sound::setRolloffFactor(float _rolloffFactor)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_ROLLOFF_FACTOR, _rolloffFactor);
}

void Sound::setMaxDistance(float _maxDistance)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_MAX_DISTANCE, _maxDistance);
}

void Sound::setConeInnerAngle(float _coneInnerAngle)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_CONE_INNER_ANGLE, _coneInnerAngle);
}

void Sound::setConeOuterAngle(float _coneOuterAngle)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_CONE_OUTER_ANGLE, _coneOuterAngle);
}

void Sound::setConeOuterGain(float _coneOuterGain)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_CONE_OUTER_GAIN, _coneOuterGain);
}

void Sound::setPosition(float _x, float _y, float _z)
{
    if(isValid())
        alSource3f(channel_->getSource(), AL_POSITION, _x, _y, _z);
}

void Sound::setVelocity(float _x, float _y, float _z)
{
    if(isValid())
        alSource3f(channel_->getSource(), AL_VELOCITY, _x, _y, _z);
}

void Sound::setDirection(float _x, float _y, float _z)
{
    if(isValid())
        alSource3f(channel_->getSource(), AL_DIRECTION, _x, _y, _z);
}


void Sound::setBuffer(const Buffer& _buffer)
{
    if(isValid())
        alSourcei(channel_->getSource(), AL_BUFFER, _buffer.getName());
}

void Sound::pause()
{
    pauseCounter_++;
    if(pauseCounter_ > 0)
        if(isValid())
            alSourcePause(channel_->getSource());
}

void Sound::resume()
{
    if(pauseCounter_ > 0)
        pauseCounter_--;
    if(pauseCounter_ == 0)
        if(isValid())
            alSourcePlay(channel_->getSource());
}

bool Sound::isValid() const
{
    return channel_ != nullptr;
}

void Sound::invalidate()
{
    channel_ = nullptr;
}

void Sound::play()
{
    if(pauseCounter_ == 0)
        if(isValid())
            alSourcePlay(channel_->getSource());
}

} // namespace audio
