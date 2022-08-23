# load system
FROM ubuntu:latest

# Upade packages nad install apps
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y tzdata
RUN apt-get install -y build-essential cmake make gdb git

# create work directory
WORKDIR /app

# copy all files
COPY . /app

# run all commands
RUN mkdir build && cd build && cmake ..

# Run app
CMD  cd build && make -j && ./FilesSync