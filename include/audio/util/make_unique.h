#pragma once

#include <memory>

// Helper method for exception-safe construction of unique_ptrs,
// cf. http://herbsutter.com/gotw/_102/
// An implementation will likely be included in C++14, making this obsolete

template<typename T, typename ...Args>
std::unique_ptr<T> make_unique(Args&& ...args)
{
    return std::unique_ptr<T>{new T{std::forward<Args>(args)...}};
}
