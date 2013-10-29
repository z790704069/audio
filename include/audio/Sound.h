#pragma once

namespace audio
{

class Buffer;
class Channel;
struct SoundParams;

/*! \brief A handle to something that is currently playing on a Channel
 */
class Sound
{
    friend class Channel;

protected:
    Sound(Channel* _channel, const SoundParams& _params); // only callable by class Playable

public:
    void setParams(const SoundParams& _params);

    void setGain(float _gain);
    void setPitch(float _pitch);
    void setTimeOffset(float _timeOffset);
    void setLooping(bool _looping);
    void setRelative(bool _relative);
    void setMinGain(float _minGain);
    void setMaxGain(float _maxGain);
    void setReferenceDistance(float _referenceDistance);
    void setRolloffFactor(float _rolloffFactor);
    void setMaxDistance(float _maxDistance);
    void setConeInnerAngle(float _coneInnerAngle);
    void setConeOuterAngle(float _coneOuterAngle);
    void setConeOuterGain(float _coneOuterGain);
    void setPosition(float _x, float _y, float _z);
    void setVelocity(float _x, float _y, float _z);
    void setDirection(float _x, float _y, float _z);

    void pause();
    void resume();

    //! Whether the handle is still actively controlling its Channel
    bool isValid() const;

protected:
    //! Invalidates the source so it no longer controls a Channel. All future
    //! calls that normally manipulate playback will become no-ops.
    void invalidate();

    //! Starts playing
    void play();

    //! Sets the currently playing buffer
    void setBuffer(const Buffer& _buffer);

private:
    Channel* channel_;
    unsigned int pauseCounter_;
};

} // namespace audio
