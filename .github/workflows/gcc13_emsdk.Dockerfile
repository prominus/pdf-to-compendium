FROM gcc:13 as base

# Set the user to not be root. This avoids needing to change owners of output files
# Based on the following blog: https://nickjanetakis.com/blog/running-docker-containers-as-a-non-root-user-with-a-custom-uid-and-gid
ARG UID=1000
ARG GID=1000
ARG USER_NAME=dev
ARG USER_PASSWD=12345

# Needed to prevent an area running the linux `source` command, which does not work on `/bin/sh`
SHELL [ "/bin/bash", "-c" ]

# Update system
RUN apt-get update && apt-get -y upgrade;
RUN apt-get -y install sudo curl wget git-core gnupg \
    zlib1g-dev libjpeg-dev libgnutls28-dev libssl-dev   \
    libjsoncpp-dev libjsoncpp-doc libtiff-tools         \
    libwebp-dev qpdf libqpdf-dev ghostscript

# Install clang
RUN apt-get -y install clang-13
# Install CMake
RUN apt-get -y install cmake cmake-curses-gui
# Install Valgrind
RUN apt-get -y install valgrind
# Install Python
RUN apt-get -y install python3 python3-pip

# Copy [doctest](https://github.com/doctest/doctest) to the container libraries
WORKDIR /usr/include
RUN wget --show-progress https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h --output-document=doctest.h

WORKDIR /
RUN git clone https://github.com/emscripten-core/emsdk.git
WORKDIR /emsdk
RUN ./emsdk install latest
RUN ./emsdk activate latest
RUN source ./emsdk_env.sh

# Set up new user
RUN groupadd -g "${GID}" ${USER_NAME}
RUN adduser --quiet --disabled-password --shell /bin/bash --home /home/$USER_NAME --gecos "User" -u "${UID}" --gid "${GID}" $USER_NAME
# update the password
RUN echo "${USER_NAME}:${USER_PASSWD}" | chpasswd && usermod -aG sudo $USER_NAME
RUN echo $USER_NAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USER_NAME && chmod 0440 /etc/sudoers.d/$USER_NAME
RUN echo "umask 0000" >> /etc/bash.bashrc && echo ". /emsdk/emsdk_env.sh" >> /etc/bash.bashrc

# set home
ENV HOME /home/${USER_NAME}

# the user we're applying this too (otherwise it most likely install for root)
USER $USER_NAME

ENV TERM xterm

# Set the default shell to bash rather than sh
ENV SHELL /bin/bash

# Install emsdk - based on Emscripten installation procedure 
RUN sudo chown -R ${USER_NAME}:${USER_NAME} /emsdk