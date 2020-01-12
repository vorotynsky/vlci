#!/bin/bash

cd /vlci/tests/lib/Catch2
cmake -Bbuild -H. -DBUILD_TESTING=OFF
sudo cmake --build build/ --target install 
cd /vlci

cmake -DENABLE_TESTING=ON -DGENERATE_DOCUMENTATION=OFF .

cmake --build . --target tests
ctest .
