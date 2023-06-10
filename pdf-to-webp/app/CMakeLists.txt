# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)
project(
    pdftowebp_application
    VERSION 0.0.1
    LANGUAGES CXX
)

# fetch latest argparse
include(FetchContent)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_GetProperties(argparse)
if(NOT argparse_POPULATED)
    FetchContent_MakeAvailable(argparse)
    message(STATUS "argparse source dir: ${argparse_SOURCE_DIR}")
    message(STATUS "argparse binary dir: ${argparse_BINARY_DIR}")
endif()

#################################################################
########################### QPDF ################################
#################################################################

# # Use find_library to locate qpdf library file
# find_library(PDFTOWEBP_LIBRARIES NAME pdftowebp_export
#     PATHS /workspaces/pdf-images-to-foundry_dev/pdf-to-webp/components/public/build
# )

# # Check if qpdf library was found
# if(NOT PDFTOWEBP_LIBRARIES)
#     message(FATAL_ERROR "Failed to find ${PDFTOWEBP_LIBRARIES} library.")
# endif()

set(PDFTOWEBP_INCLUDE_DIRS /workspaces/pdf-images-to-foundry_dev/pdf-to-webp/components/public/include)

add_executable(pdftowebp_application main.cpp)

# Include directories for header files
target_include_directories(pdftowebp_application
    PRIVATE
        ${pdftowebp_SOURCE_DIR}
        ${argparse_SOURCE_DIR}/include
        ${PDFTOWEBP_INCLUDE_DIRS}
)

# Link the g++-compiled library
target_link_libraries(pdftowebp_application
    PRIVATE
        ${pdftowebp_PATH}
        /workspaces/pdf-images-to-foundry_dev/pdf-to-webp/components/public/build/libpdftowebp_export.a
)

# Set compiler options for Emscripten
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_SDL=2")

# Selecting the variant
set(CMAKE_TOOLCHAIN_FILE /emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake)
set(CMAKE_CROSSCOMPILING_EMULATOR /emsdk/node/15.14.0_64bit/bin/node)

# Set the output directory for Emscripten-generated files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/workspaces/pdf-images-to-foundry_dev/pdf-to-webp/app/build")

# Set the Emscripten-specific settings
set(EMSCRIPTEN_LINK_FLAGS "-s WASM=1 -s \"EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']\" -s MODULARIZE=1 -s EXPORT_ES6=1")
# set(EMSCRIPTEN_LINK_FLAGS "-s WASM=1 -s \"EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']\" --post-js /build/pdftowebp_application.cjs")

# Apply Emscripten-specific settings
set_target_properties(pdftowebp_application PROPERTIES LINK_FLAGS "${EMSCRIPTEN_LINK_FLAGS}")