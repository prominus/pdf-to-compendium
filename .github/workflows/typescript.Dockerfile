# Container to build javascript from typescrip code. 

FROM node:16 as base
LABEL maintainer="Cody LeClair <prominus001@gmail.com>"

# Set the user to not be root. This avoids needing to change owners of output files
# Based on the following blog: https://nickjanetakis.com/blog/running-docker-containers-as-a-non-root-user-with-a-custom-uid-and-gid
ARG UID=1000
ARG GID=1000

RUN groupmod -g "${GID}" node && usermod -u "${UID}" -g "${GID}" node

USER node

WORKDIR /home/node

# TODO: The production target has not been tested yet.
FROM base as production

COPY --chown=node:node .. .

RUN npm i && npm run build