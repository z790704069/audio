#pragma once

#include <AL/alc.h>
#include <string>

namespace audio
{

/*! \brief A handle to a currently opened OpenAL context.
 */
class Context
{
public:
    Context();                                    // ctor
    Context(const Context&) = delete;             // no copy ctor
    Context(Context&& other) noexcept;            // move ctor

    Context& operator=(const Context&) = delete;  // no copy-assignment
    Context& operator=(Context&& other) noexcept; // move assignment

    ~Context();                                   // dtor

    //! The name of the currently used output device
    std::string getDeviceSpecifier() const;
    //! The major version number of the current OpenAL context
    int getMajorVersion() const;
    //! The minor version number of the current OpenAL context
    int getMinorVersion() const;

private:
    void open();
    void close();

    ALCdevice* device_;
    ALCcontext* context_;
};

}
