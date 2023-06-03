# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    shared_array
    VERSION 0.0.1
    LANGUAGES CXX
)
add_library(shared_array shared_array.cpp)