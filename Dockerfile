FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    sudo \
    g++ \
    catch \
    cmake

ENV CC=/usr/bin/gcc
ENV CXX=/usr/bin/g++

ADD "./CMakeLists.txt" "/vlci/"
ADD "./tests" "/vlci/tests"
ADD "./vlcp" "/vlci/vlcp"
ADD "./client" "/vlci/client"

RUN chmod u+x "/vlci/tests/run_tests.sh"
ENTRYPOINT [ "/vlci/tests/run_tests.sh" ]