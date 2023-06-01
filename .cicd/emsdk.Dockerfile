# Container to build javascript from C++ code. As ths QPDF library is a dependency this installs QPDF from source

FROM emscripten/emsdk:3.1.40 as base
# Set the user to not be root. This avoids needing to change owners of output files
# Based on the following blog: https://nickjanetakis.com/blog/running-docker-containers-as-a-non-root-user-with-a-custom-uid-and-gid
ARG UID=1001
ARG GID=1000

# Create a folder to place the downloaded QPDF source code
WORKDIR /home/Downloads

# Install qpdf and create non root user
RUN wget --show-progress -v https://github.com/qpdf/qpdf/releases/download/v11.4.0/qpdf-11.4.0.tar.gz; \
    tar -xvf qpdf-11.4.0.tar.gz; \
    cd qpdf-11.4.0; \
    build-scripts/build-linux; \
    useradd --create-home --no-log-init -u "${UID}" -g "${GID}" dev

# set user and directory
USER dev
WORKDIR /home/dev