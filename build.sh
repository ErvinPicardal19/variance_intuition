#!/usr/bin/bash

sudo apt-get install gnuplot

if [ -d ./data ];
then
   echo "data folder exist."
else
   mkdir data
fi

rm -rf build
mkdir build && cd build

cmake ../
