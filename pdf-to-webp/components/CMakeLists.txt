# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    pdf_to_webp_components
    VERSION 0.0.1
    LANGUAGES CXX
)

# find_package(jsoncpp QUIET)
# if (NOT jsoncpp_FOUND)
#     message(STATUS "jsoncpp not found, initializing git submodule")
#     execute_process(
#         COMMAND git submodule update --init -- external/jsoncpp
#         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#     )
#     message(STATUS "Adding json subdirectorj")
    add_subdirectory(external/jsoncpp)
# endif()

add_subdirectory(artwork_handler)
add_subdirectory(external)
add_subdirectory(handler)
add_subdirectory(image)
add_subdirectory(image_extractor)
add_subdirectory(json_handle)
add_subdirectory(test_doctest)
add_subdirectory(tsqueue)