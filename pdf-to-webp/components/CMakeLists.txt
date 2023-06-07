# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    pdf_to_webp_components
    VERSION 0.0.1
    LANGUAGES CXX
)



add_subdirectory(artwork_handler)
add_subdirectory(external)
add_subdirectory(handler)
add_subdirectory(image)
add_subdirectory(image_extractor)
add_subdirectory(json_handle)
add_subdirectory(test_doctest)
add_subdirectory(tsqueue)