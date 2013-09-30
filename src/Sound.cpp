#include <audio/Sound.h>
#include <audio/SoundParams.h>
#include <audio/Channel.h>

#include <AL/al.h>

#include <cassert>

namespace audio
{

Sound::Sound(Channel* channel, const SoundParams& params) :
    channel_{channel},
    pauseCounter_{0}
{
    setParams(params);
}

void Sound::setParams(const SoundParams& params)
{
    if(isValid())
    {
        auto source = channel_->getSource();

        alSourcef(source, AL_GAIN,               params.gain_);
        alSourcef(source, AL_PITCH,              params.pitch_);
        alSourcef(source, AL_SEC_OFFSET,         params.timeOffset_);
        alSourcef(source, AL_MIN_GAIN,           params.minGain_);
        alSourcef(source, AL_MAX_GAIN,           params.maxGain_);
        alSourcef(source, AL_REFERENCE_DISTANCE, params.referenceDistance_);
        alSourcef(source, AL_ROLLOFF_FACTOR,     params.rolloffFactor_);
        alSourcef(source, AL_MAX_DISTANCE,       params.maxDistance_);
        alSourcef(source, AL_CONE_INNER_ANGLE,   params.coneInnerAngle_);
        alSourcef(source, AL_CONE_OUTER_ANGLE,   params.coneOuterAngle_);
        alSourcef(source, AL_CONE_OUTER_GAIN,    params.coneOuterGain_);

        alSourcei(source, AL_LOOPING,            params.looping_ ? AL_TRUE : AL_FALSE);
        alSourcei(source, AL_SOURCE_RELATIVE,    params.relative_ ? AL_TRUE : AL_FALSE);

        alSource3f(source, AL_POSITION,  params.positionX_,  params.positionY_,  params.positionZ_);
        alSource3f(source, AL_VELOCITY,  params.velocityX_,  params.velocityY_,  params.velocityZ_);
        alSource3f(source, AL_DIRECTION, params.directionX_, params.directionY_, params.directionZ_);
    }
}

void Sound::setGain(float gain)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_GAIN, gain);
}

void Sound::setPitch(float pitch)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_PITCH, pitch);
}

void Sound::setTimeOffset(float timeOffset)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_SEC_OFFSET, timeOffset);
}

void Sound::setLooping(bool looping)
{
    if(isValid())
        alSourcei(channel_->getSource(), AL_LOOPING, looping ? AL_TRUE : AL_FALSE);
}

void Sound::setRelative(bool relative)
{
    if(isValid())
        alSourcei(channel_->getSource(), AL_SOURCE_RELATIVE, relative ? AL_TRUE : AL_FALSE);
}

void Sound::setMinGain(float minGain)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_MIN_GAIN, minGain);
}

void Sound::setMaxGain(float maxGain)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_MAX_GAIN, maxGain);
}

void Sound::setReferenceDistance(float referenceDistance)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_REFERENCE_DISTANCE, referenceDistance);
}

void Sound::setRolloffFactor(float rolloffFactor)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_ROLLOFF_FACTOR, rolloffFactor);
}

void Sound::setMaxDistance(float maxDistance)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_MAX_DISTANCE, maxDistance);
}

void Sound::setConeInnerAngle(float coneInnerAngle)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_CONE_INNER_ANGLE, coneInnerAngle);
}

void Sound::setConeOuterAngle(float coneOuterAngle)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_CONE_OUTER_ANGLE, coneOuterAngle);
}

void Sound::setConeOuterGain(float coneOuterGain)
{
    if(isValid())
        alSourcef(channel_->getSource(), AL_CONE_OUTER_GAIN, coneOuterGain);
}

void Sound::setPosition(float x, float y, float z)
{
    if(isValid())
        alSource3f(channel_->getSource(), AL_POSITION, x, y, z);
}

void Sound::setVelocity(float x, float y, float z)
{
    if(isValid())
        alSource3f(channel_->getSource(), AL_VELOCITY, x, y, z);
}

void Sound::setDirection(float x, float y, float z)
{
    if(isValid())
        alSource3f(channel_->getSource(), AL_DIRECTION, x, y, z);
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
    return static_cast<bool>(channel_);
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
