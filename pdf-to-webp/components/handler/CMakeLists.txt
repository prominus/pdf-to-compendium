# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    handler
    VERSION 0.0.1
    LANGUAGES CXX
)

find_package(jsoncpp QUIET)
if (NOT jsoncpp_FOUND)
    message("jsoncpp not found, initializing git submodule")
    execute_process(
        COMMAND git submodule update --init -- external/jsoncpp
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
    add_subdirectory(external/jsoncpp)
endif()