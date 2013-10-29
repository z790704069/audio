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

Channel::Channel(Channel&& _other) noexcept :
    sourceAllocated_{false},
    sound_{nullptr}
{
    *this = std::forward<Channel>(_other); // call move assignment
}

Channel& Channel::operator=(Channel&& _other) noexcept
{
    deallocateSource();

    source_ = _other.source_;
    sourceAllocated_ = _other.sourceAllocated_;
    sound_ = std::move(_other.sound_);

    _other.sourceAllocated_ = false;

    return *this;
}

Channel::~Channel()
{
    resetSound();
    deallocateSource();
}

bool Channel::isOccupied() const
{
    updateSound();
    return sound_ != nullptr;
}

std::shared_ptr<Sound> Channel::getSound() const
{
    updateSound();
    return sound_;
}

std::shared_ptr<Sound> Channel::play(Playable& _playable, const SoundParams& _params)
{
    resetSound(_playable.play(*this, _params).release());
    return sound_;
}

void Channel::updateSound() const
{
    if(sound_)
    {
        // Check whether registered source is still playing on this channel
        ALint state;
        alGetSourcei(source_, AL_SOURCE_STATE, &state);
        if(state == AL_INITIAL || state == AL_STOPPED)
            resetSound();
    }
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

void Channel::resetSound(Sound* _sound) const
{
    if(sound_.get() && sound_.get() != _sound)
        sound_->invalidate();
    sound_.reset(_sound);
}

}
