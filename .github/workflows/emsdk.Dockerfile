# Container to build javascript from C++ code. As ths QPDF library is a dependency this installs QPDF & QPDF Dev Libraries.

FROM emscripten/emsdk:3.1.40 as base
LABEL maintainer="Cody LeClair <prominus001@gmail.com>"

# Copy [doctest](https://github.com/doctest/doctest) to the container libraries
WORKDIR /usr/include
RUN wget --show-progress https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h --output-document=doctest.h

# Set the user to not be root. This avoids needing to change owners of output files
# Based on the following blog: https://nickjanetakis.com/blog/running-docker-containers-as-a-non-root-user-with-a-custom-uid-and-gid
ARG UID=1000
ARG GID=1000

# Create a folder to place the downloaded QPDF source code
WORKDIR /home/Downloads

# Install qpdf and create non root user
# The packages libjsoncpp-dev libjsoncpp-doc libjsoncpp1 are for JSON reading
# The libwebp-dev package is for saving images to webp
# For latest GCC installing gcc-12 gcc-12-base gcc-12-doc g++-12
# For latest G++ installing libstdc++-12-dev libstdc++-12-doc 
# Installing cmake-curses-gui to use ccmake
# Installing valgrind for memory checking
RUN sudo apt-get update &&          \
    sudo apt-get -y install build-essential gdb cmake   \
    zlib1g-dev libjpeg-dev libgnutls28-dev libssl-dev   \
    libjsoncpp-dev libjsoncpp-doc libtiff-tools         \
    libwebp-dev qpdf libqpdf-dev ghostscript gcc-12     \
    gcc-12-base gcc-12-doc g++-12 libstdc++-12-dev      \
    libstdc++-12-doc clang-12 cmake-curses-gui valgrind;\
# User created in original container
# Can be found in source code here https://github.com/trzecieu/emscripten-docker/blob/master/docker/trzeci/emscripten-slim/Dockerfile#L352
    groupmod -g "${GID}" emscripten && usermod -u "${UID}" -g "${GID}" emscripten 

# set user and directory
USER emscripten 
WORKDIR /home/emscripten 