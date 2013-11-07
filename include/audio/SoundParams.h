#pragma once

namespace audio
{

struct SoundParams
{
    SoundParams();

    // named-parameter setters
    inline auto gain             (float _gain)              -> SoundParams& {  gain_ = _gain;                           return *this; }
    inline auto pitch            (float _pitch)             -> SoundParams& {  pitch_ = _pitch;                         return *this; }
    inline auto timeOffset       (float _timeOffset)        -> SoundParams& {  timeOffset_ = _timeOffset;               return *this; }
    inline auto looping          (bool _looping)            -> SoundParams& {  looping_ = _looping;                     return *this; }
    inline auto relative         (bool _relative)           -> SoundParams& {  relative_ = _relative;                   return *this; }
    inline auto minGain          (float _minGain)           -> SoundParams& {  minGain_ = _minGain;                     return *this; }
    inline auto maxGain          (float _maxGain)           -> SoundParams& {  maxGain_ = _maxGain;                     return *this; }
    inline auto referenceDistance(float _referenceDistance) -> SoundParams& {  referenceDistance_ = _referenceDistance; return *this; }
    inline auto rolloffFactor    (float _rolloffFactor)     -> SoundParams& {  rolloffFactor_ = _rolloffFactor;         return *this; }
    inline auto maxDistance      (float _maxDistance)       -> SoundParams& {  maxDistance_ = _maxDistance;             return *this; }
    inline auto coneInnerAngle   (float _coneInnerAngle)    -> SoundParams& {  coneInnerAngle_ = _coneInnerAngle;       return *this; }
    inline auto coneOuterAngle   (float _coneOuterAngle)    -> SoundParams& {  coneOuterAngle_ = _coneOuterAngle;       return *this; }
    inline auto coneOuterGain    (float _coneOuterGain)     -> SoundParams& {  coneOuterGain_ = _coneOuterGain;         return *this; }

    inline auto position (float _x, float _y, float _z) -> SoundParams& {  positionX_  = _x; positionY_  = _y; positionZ_  = _z; return *this; }
    inline auto velocity (float _x, float _y, float _z) -> SoundParams& {  velocityX_  = _x; velocityY_  = _y; velocityZ_  = _z; return *this; }
    inline auto direction(float _x, float _y, float _z) -> SoundParams& {  directionX_ = _x; directionY_ = _y; directionZ_ = _z; return *this; }

    // playback
    float gain_;
    float pitch_;
    float timeOffset_; // in seconds
    bool looping_;

    // positioning
    bool relative_;
    float positionX_, positionY_, positionZ_;
    float velocityX_, velocityY_, velocityZ_;

    // distance falloff
    float minGain_, maxGain_;
    float referenceDistance_;
    float rolloffFactor_;
    float maxDistance_;

    // directional cone sources
    float directionX_, directionY_, directionZ_;
    float coneInnerAngle_, coneOuterAngle_;
    float coneOuterGain_;
};

}
