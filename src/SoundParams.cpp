#include <audio/SoundParams.h>
#include <limits>

namespace audio
{

SoundParams::SoundParams() :
    gain_{1},
    pitch_{1},
    timeOffset_{0},
    looping_{false},
    relative_{false},
    positionX_{0}, positionY_{0}, positionZ_{0},
    velocityX_{0}, velocityY_{0}, velocityZ_{0},
    minGain_{0}, maxGain_{1},
    referenceDistance_{1},
    rolloffFactor_{1},
    maxDistance_{std::numeric_limits<float>::max()},
    directionX_{0}, directionY_{0}, directionZ_{0},
    coneInnerAngle_{360}, coneOuterAngle_{360},
    coneOuterGain_{0}
{
}

}
