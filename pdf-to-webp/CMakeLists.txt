# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    pdf_to_webp
    VERSION 0.0.1
    LANGUAGES CXX
)
include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# fetch latest argparse
include(FetchContent)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

add_subdirectory(components)
add_subdirectory(app)