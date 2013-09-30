#pragma once

#include <audio/data/Format.h>

#include <cstddef>

namespace audio
{
namespace data
{

class Stream
{
public:
    virtual ~Stream() = default;

    /*! Reads data from the stream and stores it in memory
     *  \param count number of bytes to read
     *  \param s     destination address to write data to
     */
    virtual std::size_t read(std::size_t count, char* s) = 0;

protected:
    Stream(const Format& format);

    Format format_;
};

}
}
