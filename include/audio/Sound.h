#pragma once

namespace audio
{

class Channel;
struct SoundParams;

/*! \brief A handle to something that is currently playing on a Channel
 */
class Sound
{
    friend class Channel;

protected:
    Sound(Channel* channel, const SoundParams& params); // only callable by class Playable

public:
    void setParams(const SoundParams& params);

    void setGain(float gain);
    void setPitch(float pitch);
    void setTimeOffset(float timeOffset);
    void setLooping(bool looping);
    void setRelative(bool relative);
    void setMinGain(float minGain);
    void setMaxGain(float maxGain);
    void setReferenceDistance(float referenceDistance);
    void setRolloffFactor(float rolloffFactor);
    void setMaxDistance(float maxDistance);
    void setConeInnerAngle(float coneInnerAngle);
    void setConeOuterAngle(float coneOuterAngle);
    void setConeOuterGain(float coneOuterGain);
    void setPosition(float x, float y, float z);
    void setVelocity(float x, float y, float z);
    void setDirection(float x, float y, float z);

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

protected:
    Channel* channel_;
    unsigned int pauseCounter_;
};

} // namespace audio
