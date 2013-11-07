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
    auto setParams(const SoundParams& _params) -> void;

    auto setGain(float _gain) -> void;
    auto setPitch(float _pitch) -> void;
    auto setTimeOffset(float _timeOffset) -> void;
    auto setLooping(bool _looping) -> void;
    auto setRelative(bool _relative) -> void;
    auto setMinGain(float _minGain) -> void;
    auto setMaxGain(float _maxGain) -> void;
    auto setReferenceDistance(float _referenceDistance) -> void;
    auto setRolloffFactor(float _rolloffFactor) -> void;
    auto setMaxDistance(float _maxDistance) -> void;
    auto setConeInnerAngle(float _coneInnerAngle) -> void;
    auto setConeOuterAngle(float _coneOuterAngle) -> void;
    auto setConeOuterGain(float _coneOuterGain) -> void;
    auto setPosition(float _x, float _y, float _z) -> void;
    auto setVelocity(float _x, float _y, float _z) -> void;
    auto setDirection(float _x, float _y, float _z) -> void;

    /*!
     * \brief Pauses the Sound.
     * \note When calling pause multiple times, resume must be called the same
     * number of times in order to actually resume playback.
     * \note
     */
    auto pause() -> void;
    auto resume() -> void;

    //! \brief Whether the handle is still actively controlling its Channel
    auto isValid() const -> bool;

protected:
    //! \brief Invalidates the source so it no longer controls a Channel. All
    //! future calls that would normally manipulate playback will become no-ops.
    auto invalidate() -> void;

    //! \brief Starts playing
    auto play() -> void;

    //! \brief Sets the currently playing buffer
    auto setBuffer(const Buffer& _buffer) -> void;

private:
    Channel* channel_;
    unsigned int pauseCounter_;
};

} // namespace audio
