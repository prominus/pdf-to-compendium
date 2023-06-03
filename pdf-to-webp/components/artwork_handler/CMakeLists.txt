# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    artwork_handler
    VERSION 0.0.1
    LANGUAGES CXX
)
add_library(artwork_handler artwork_handler.cpp)