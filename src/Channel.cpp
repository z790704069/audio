#include <audio/Channel.h>
#include <audio/Playable.h>
#include <utility>

namespace audio
{

Channel::Channel() :
    sourceAllocated_{false},
    sound_{nullptr}
{
    allocateSource();
}

Channel::Channel(Channel&& other) noexcept :
    sourceAllocated_{false},
    sound_{nullptr}
{
    *this = std::forward<Channel>(other); // call move assignment
}

Channel& Channel::operator=(Channel&& other) noexcept
{
    deallocateSource();

    source_ = other.source_;
    sourceAllocated_ = other.sourceAllocated_;
    sound_ = std::move(other.sound_);

    other.sourceAllocated_ = false;

    return *this;
}

Channel::~Channel()
{
    resetSound();
    deallocateSource();
}

bool Channel::isOccupied()
{
    if(sound_)
    {
        // Check whether registered source is still playing on this channel
        ALint state;
        alGetSourcei(source_, AL_SOURCE_STATE, &state);
        if(state == AL_INITIAL || state == AL_STOPPED)
        {
            resetSound();
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

std::shared_ptr<Sound> Channel::play(Playable& playable, const SoundParams& params)
{
    resetSound(playable.play(*this, params).release());
    return sound_;
}

void Channel::allocateSource()
{
    if(!sourceAllocated_)
    {
        alGenSources(1, &source_);
        sourceAllocated_ = true;
    }
}

void Channel::deallocateSource()
{
    if(sourceAllocated_)
    {
        alDeleteSources(1, &source_);
        sourceAllocated_ = false;
    }
}

void Channel::resetSound(Sound* sound)
{
    if(sound_.get() && sound_.get() != sound)
        sound_->invalidate();
    sound_.reset(sound);
}

}
