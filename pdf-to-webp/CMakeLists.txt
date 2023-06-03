# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    pdf_to_webp
    VERSION 0.0.1
    LANGUAGES CXX
)
add_subdirectory(components)
add_subdirectory(app)