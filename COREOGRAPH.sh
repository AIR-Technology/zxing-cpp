#!/bin/sh

cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j8 --config Release
sudo cmake --install build