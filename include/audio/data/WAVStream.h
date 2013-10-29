#pragma once

#include <audio/data/Stream.h>

#include <cstddef>

namespace audio
{
namespace data
{

class WAVStream : public Stream
{
public:
    /*! Reads data from the stream and stores it in memory
     *  \param count number of bytes to read
     *  \param s     destination address to write data to
     */
    virtual std::size_t read(std::size_t _count, char* _s) = 0;

protected:
    WAVStream(const Format& _format);
    virtual ~WAVStream() {}

    Format format_;
};

}
}
