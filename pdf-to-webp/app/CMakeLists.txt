# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    pdf_to_webp_application
    VERSION 0.0.1
    LANGUAGES CXX
)

add_executable(pdf_to_webp_application main.cpp)
target_link_directories(
    pdf_to_webp_application PRIVATE ${CMAKE_SOURCE_DIR}/../components/json_handle/build/
    pdf_to_webp_application PRIVATE ${CMAKE_SOURCE_DIR}/../components/shared_array/build/
    pdf_to_webp_application PRIVATE ${CMAKE_SOURCE_DIR}/../components/image_extractor/build/
    pdf_to_webp_application PRIVATE ${CMAKE_SOURCE_DIR}/../external/argparse/build/
    )
target_link_libraries(pdf_to_webp_application json_handle shared_array image_extractor argparse)
