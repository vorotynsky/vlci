FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    sudo \
    g++ \
    catch \
    cmake

ENV CC=/usr/bin/gcc
ENV CXX=/usr/bin/g++

ADD "." "/vlci"

RUN chmod u+x "/vlci/tests/run_tests.sh"
ENTRYPOINT [ "/vlci/tests/run_tests.sh" ]