#pragma once

namespace audio
{

struct SoundParams
{
    SoundParams();

    // named-parameter setters
    inline SoundParams& gain             (float gain)              { gain_ = gain;                           return *this; }
    inline SoundParams& pitch            (float pitch)             { pitch_ = pitch;                         return *this; }
    inline SoundParams& timeOffset       (float timeOffset)        { timeOffset_ = timeOffset;               return *this; }
    inline SoundParams& looping          (bool looping)            { looping_ = looping;                     return *this; }
    inline SoundParams& relative         (bool relative)           { relative_ = relative;                   return *this; }
    inline SoundParams& minGain          (float minGain)           { minGain_ = minGain;                     return *this; }
    inline SoundParams& maxGain          (float maxGain)           { maxGain_ = maxGain;                     return *this; }
    inline SoundParams& referenceDistance(float referenceDistance) { referenceDistance_ = referenceDistance; return *this; }
    inline SoundParams& rolloffFactor    (float rolloffFactor)     { rolloffFactor_ = rolloffFactor;         return *this; }
    inline SoundParams& maxDistance      (float maxDistance)       { maxDistance_ = maxDistance;             return *this; }
    inline SoundParams& coneInnerAngle   (float coneInnerAngle)    { coneInnerAngle_ = coneInnerAngle;       return *this; }
    inline SoundParams& coneOuterAngle   (float coneOuterAngle)    { coneOuterAngle_ = coneOuterAngle;       return *this; }
    inline SoundParams& coneOuterGain    (float coneOuterGain)     { coneOuterGain_ = coneOuterGain;         return *this; }

    inline SoundParams& position (float x, float y, float z) { positionX_ = x;  positionY_ = y;  positionZ_ = z;  return *this; }
    inline SoundParams& velocity (float x, float y, float z) { velocityX_ = x;  velocityY_ = y;  velocityZ_ = z;  return *this; }
    inline SoundParams& direction(float x, float y, float z) { directionX_ = x; directionY_ = y; directionZ_ = z; return *this; }

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
