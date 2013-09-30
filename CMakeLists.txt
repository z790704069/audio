project(audio)

# Project Files
file(GLOB_RECURSE AUDIO_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE AUDIO_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -Wall -Wpedantic -Werror")

set(AUDIO_LIBRARIES ${AUDIO_LIBRARIES} "-framework OpenAL")

add_library(audio ${AUDIO_SOURCE_FILES} ${AUDIO_HEADER_FILES})
target_link_libraries(audio ${AUDIO_LIBRARIES})
