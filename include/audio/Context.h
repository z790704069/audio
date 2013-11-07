#pragma once

#include <AL/alc.h> // TODO: try to not expose this header
#include <string>

namespace audio
{

/*! \brief A handle to a currently opened OpenAL context.
 */
class Context
{
public:
    Context();                                     // ctor
    Context(const Context&) = delete;              // no copy ctor
    Context(Context&& _other) noexcept;            // move ctor

    Context& operator=(const Context&) = delete;   // no copy-assignment
    Context& operator=(Context&& _other) noexcept; // move assignment

    ~Context();                                    // dtor

    //! The name of the currently used output device
    auto getDeviceSpecifier() const -> std::string;
    //! The major version number of the current OpenAL context
    auto getMajorVersion() const -> int;
    //! The minor version number of the current OpenAL context
    auto getMinorVersion() const -> int;

private:
    void open();
    void close();

    ALCdevice* device_;
    ALCcontext* context_;
};

}
