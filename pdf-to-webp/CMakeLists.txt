# TODO: look at https://stunlock.gg/posts/emscripten_with_cmake/
cmake_minimum_required(VERSION 3.21.0)

# set(BUILD_SHARED_LIBS False)

project(
    pdf_to_webp
    VERSION 0.0.1
    LANGUAGES CXX
)
include(CTest)


# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# fetch latest argparse
include(FetchContent)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
# FetchContent_Declare(
#     jsoncpp
#     GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
# )
# FetchContent_Declare(
#     qpdf
#     GIT_REPOSITORY https://github.com/qpdf/qpdf.git
#     GIT_TAG 9907700
# )
FetchContent_MakeAvailable(
    argparse
    # jsoncpp
    # qpdf
)


add_subdirectory(components)
add_subdirectory(app)