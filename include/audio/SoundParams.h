#pragma once

namespace audio
{

struct SoundParams
{
    SoundParams();

    // named-parameter setters
    inline SoundParams& gain             (float _gain)              { gain_ = _gain;                           return *this; }
    inline SoundParams& pitch            (float _pitch)             { pitch_ = _pitch;                         return *this; }
    inline SoundParams& timeOffset       (float _timeOffset)        { timeOffset_ = _timeOffset;               return *this; }
    inline SoundParams& looping          (bool _looping)            { looping_ = _looping;                     return *this; }
    inline SoundParams& relative         (bool _relative)           { relative_ = _relative;                   return *this; }
    inline SoundParams& minGain          (float _minGain)           { minGain_ = _minGain;                     return *this; }
    inline SoundParams& maxGain          (float _maxGain)           { maxGain_ = _maxGain;                     return *this; }
    inline SoundParams& referenceDistance(float _referenceDistance) { referenceDistance_ = _referenceDistance; return *this; }
    inline SoundParams& rolloffFactor    (float _rolloffFactor)     { rolloffFactor_ = _rolloffFactor;         return *this; }
    inline SoundParams& maxDistance      (float _maxDistance)       { maxDistance_ = _maxDistance;             return *this; }
    inline SoundParams& coneInnerAngle   (float _coneInnerAngle)    { coneInnerAngle_ = _coneInnerAngle;       return *this; }
    inline SoundParams& coneOuterAngle   (float _coneOuterAngle)    { coneOuterAngle_ = _coneOuterAngle;       return *this; }
    inline SoundParams& coneOuterGain    (float _coneOuterGain)     { coneOuterGain_ = _coneOuterGain;         return *this; }

    inline SoundParams& position (float _x, float _y, float _z) { positionX_  = _x; positionY_  = _y; positionZ_  = _z; return *this; }
    inline SoundParams& velocity (float _x, float _y, float _z) { velocityX_  = _x; velocityY_  = _y; velocityZ_  = _z; return *this; }
    inline SoundParams& direction(float _x, float _y, float _z) { directionX_ = _x; directionY_ = _y; directionZ_ = _z; return *this; }

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
