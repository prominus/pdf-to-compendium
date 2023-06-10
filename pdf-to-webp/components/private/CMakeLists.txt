cmake_minimum_required(VERSION 3.21.0)
project(
    pdftowebp_private
    VERSION 0.0.1
    LANGUAGES CXX
)

#################################################################
######################## JSONCPP ################################
#################################################################

# Use find_library to locate JSON C++ library file
find_library(JSONCPP_LIBRARIES NAMES jsoncpp
    PATHS /usr/lib/x86_64-linux-gnu
)

# Check if JSON C++ library was found
if(NOT JSONCPP_LIBRARIES)
message(FATAL_ERROR "Failed to find ${JSONCPP_LIBRARIES} library.")
endif()

set(JSONCPP_INCLUDE_DIRS /usr/include/jsoncpp/json)
#################################################################
########################### WEBP ################################
###############c##################################################

# Use find_library to locate Webp library file
find_library(WEBP_LIBRARIES NAME webp
    PATHS /usr/lib/x86_64-linux-gnu
)

# Check if Webp library was found
if(NOT WEBP_LIBRARIES)
    message(FATAL_ERROR "Failed to find ${WEBP_LIBRARIES} library.")
endif()

set(WEBP_INCLUDE_DIRS /usr/include/webp)

#################################################################
########################### QPDF ################################
#################################################################

# Use find_library to locate qpdf library file
find_library(QPDF_LIBRARIES qpdf
    PATHS /usr/lib/x86_64-linux-gnu
)

# Check if qpdf library was found
if(NOT QPDF_LIBRARIES)
    message(FATAL_ERROR "Failed to find ${QPDF_LIBRARIES} library.")
endif()

set(QPDF_INCLUDE_DIRS /usr/include/qpdf)

#################################################################

add_library(pdftowebp_private STATIC
    src/artwork_handler.cpp
    src/image_extractor.cpp
    src/image.cpp
    src/json_ref.cpp
    
    include/artwork_handler.h
    include/fs_map.h
    include/handler.h
    include/image_extractor.h
    include/image.h
    include/json_ref.h
    include/tsqueue.h
)

target_include_directories(pdftowebp_private
    PRIVATE
        ${JSONCPP_INCLUDE_DIRS}
        ${WEBP_INCLUDE_DIRS}
        ${QPDF_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include/private
)

target_link_libraries(pdftowebp_private
    PRIVATE
    ${JSONCPP_LIBRARIES}  
    ${WEBP_LIBRARIES}
    ${QPDF_LIBRARIES}
)