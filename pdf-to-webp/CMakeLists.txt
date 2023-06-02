cmake_minimum_required(VERSION 3.0.0)
project(pdf_to_webp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(pdf_to_webp artwork_handler.cpp image_extractor.cpp shared_array.cpp main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
