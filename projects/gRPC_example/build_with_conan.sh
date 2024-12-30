#!/usr/bin/env bash

conan install . --build=missing -s build_type=Debug

cmake --preset ninja-conan-debug

cmake --build --preset ninja-conan-debug
