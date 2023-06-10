# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    pdftowebp_export
    VERSION 0.0.1
    LANGUAGES CXX
)

add_library(pdftowebp_export STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/entrypoint.h
)

target_include_directories(pdftowebp_export
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src      
        /workspaces/pdf-images-to-foundry_dev/pdf-to-webp/components/private/include 
)

target_sources(pdftowebp_export PRIVATE src/entrypoint.cpp)

target_link_directories(pdftowebp_export
    PRIVATE
    /workspaces/pdf-images-to-foundry_dev/pdf-to-webp/components/private/build
)


