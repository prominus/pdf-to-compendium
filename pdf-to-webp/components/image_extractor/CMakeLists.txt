# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    image_extractor
    VERSION 0.0.1
    LANGUAGES CXX
)
add_library(imaged_extractor image_extractor.cpp)