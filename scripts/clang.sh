#!/bin/bash

find "server" \( -name "*.cpp" -o -name "*.hpp" \) -exec clang-format -i {} +
find "client" \( -name "*.cpp" -o -name "*.hpp" \) -exec clang-format -i {} +
find "gengine" \( -name "*.cpp" -o -name "*.hpp" \) -exec clang-format -i {} +
