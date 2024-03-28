#!/usr/bin/bash

sudo apt-get install gnuplot

rm -rf build
mkdir build && cd build

cmake ../
