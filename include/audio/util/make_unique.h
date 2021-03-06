#pragma once

#include <memory>

// Helper method for exception-safe construction of unique_ptrs,
// cf. http://herbsutter.com/gotw/_102/
// An implementation will likely be included in C++14, making this obsolete

template<typename T, typename... Args>
auto make_unique(Args&&... _args) -> std::unique_ptr<T>
{
    return std::unique_ptr<T>{new T{std::forward<Args>(_args)...}};
}
