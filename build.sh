#!/usr/bin/bash

sudo apt-get install gnuplot

rm -rf build
mkdir data
mkdir build && cd build

cmake ../
