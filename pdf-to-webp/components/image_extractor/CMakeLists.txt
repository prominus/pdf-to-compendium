# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    image_extractor
    VERSION 0.0.1
    LANGUAGES CXX
)
add_library(image_extractor image_extractor.cpp)
target_link_directories(image_extractor PRIVATE /usr/include/qpdf/)
target_link_libraries(image_extractor qpdf)