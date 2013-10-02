project(audio)

# Project Files
file(GLOB_RECURSE AUDIO_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE AUDIO_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # using Clang
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -Wall -Wpedantic -Werror")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # using GCC
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic -Werror")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    # using Intel C++
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # using Visual Studio C++
endif()

if(APPLE)
    # OSX or iOS
    set(AUDIO_LIBRARIES ${AUDIO_LIBRARIES} "-framework OpenAL")
elseif(WIN32)
    # Windows
elseif(UNIX)
    # Unix
    set(AUDIO_LIBRARIES ${AUDIO_LIBRARIES} openal)
endif()

add_library(audio ${AUDIO_SOURCE_FILES} ${AUDIO_HEADER_FILES})
target_link_libraries(audio ${AUDIO_LIBRARIES})
