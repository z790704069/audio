#include <audio/Context.h>
#include <iostream>
#include <utility>
#include <stdexcept>

namespace audio
{

Context::Context() :
    device_{nullptr},
    context_{nullptr}
{
    open();
}

Context::Context(Context&& other) noexcept :
    device_{nullptr},
    context_{nullptr}
{
    *this = std::forward<Context>(other); // call move assignment
}

Context& Context::operator=(Context&& other) noexcept
{
    close();
    device_ = other.device_;
    context_ = other.context_;
    other.device_ = nullptr;
    other.context_ = nullptr;
    return *this;
}

Context::~Context()
{
    close();
}

std::string Context::getDeviceSpecifier() const
{
    return std::string{alcGetString(device_, ALC_DEVICE_SPECIFIER)};
}

int Context::getMajorVersion() const
{
    ALCint result;
    alcGetIntegerv(device_, ALC_MAJOR_VERSION, 1, &result);
    return static_cast<int>(result);
}

int Context::getMinorVersion() const
{
    ALCint result;
    alcGetIntegerv(device_, ALC_MINOR_VERSION, 1, &result);
    return static_cast<int>(result);
}

void Context::open()
{
    // Initialize the OpenAL Driver
    device_ = alcOpenDevice(nullptr);
    if(!device_)
        throw std::runtime_error{"Could not open OpenAL device"};

    context_ = alcCreateContext(device_, nullptr);
    if(!context_)
        throw std::runtime_error{"Could not create OpenAL context"};

    alcMakeContextCurrent(context_);

    if(alcGetError(device_))
        throw std::runtime_error{"Error during device initialization"};
}

void Context::close()
{
    if(context_)
    {
        alcMakeContextCurrent(nullptr);
        alcDestroyContext(context_);
        context_ = nullptr;
    }
    if(device_)
    {
        alcCloseDevice(device_);
        device_ = nullptr;
    }
}

}
