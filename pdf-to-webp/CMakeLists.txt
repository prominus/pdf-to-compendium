cmake_minimum_required(VERSION 3.21.0)
project(pdf_to_webp VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES main.cpp shared_array.cpp)
add_executable(pdf_to_webp ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
