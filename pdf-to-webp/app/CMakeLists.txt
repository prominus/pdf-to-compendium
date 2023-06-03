# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    pdf_to_webp_application
    VERSION 0.0.1
    LANGUAGES CXX
)

# set(SOURCES main.cpp shared_array.cpp)
add_executable(pdf_to_webp_application main.cpp)
target_link_directories(pdf_to_webp_application PRIVATE ${CMAKE_SOURCE_DIR}/../components/shared_array/build/)
target_link_libraries(pdf_to_webp_application shared_array)
