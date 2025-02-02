#!/bin/bash

git submodule update --init --recursive

cmake -B build .
cd build/
make
