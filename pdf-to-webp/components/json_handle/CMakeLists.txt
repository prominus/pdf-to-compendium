# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    json_handle
    VERSION 0.0.1
    LANGUAGES CXX
)
add_library(json_handle json_handle.cpp)
target_link_directories(json_handle PRIVATE /usr/include/jsoncpp/)
target_link_libraries(json_handle jsoncpp)