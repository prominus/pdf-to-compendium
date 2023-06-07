cmake_minimum_required(VERSION 3.21.0)
project(
    external
    VERSION 0.0.1
    LANGUAGES CXX
)

find_package(jsoncpp QUIET)
if (NOT jsoncpp_FOUND)
    message(STATUS "jsoncpp not found, initializing git submodule")
    execute_process(
        COMMAND git submodule update --init -- jsoncpp
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
#     message(STATUS "Adding json subdirectory")
    add_subdirectory(jsoncpp)
endif()

find_package(qpdf QUIET)
if (NOT qpdf_FOUND)
    message(STATUS "qpdf not found, initializing git submodule")
    execute_process(
        COMMAND git submodule update --init -- qpdf
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
#     message(STATUS "Adding json subdirectory")
    add_subdirectory(qpdf)
endif()