find "server" \( -name "*.cpp" -o -name "*.hpp" \) -exec clang-format -i {} +
find "client" \( -name "*.cpp" -o -name "*.hpp" \) -exec clang-format -i {} +
find "game_engine" \( -name "*.cpp" -o -name "*.hpp" \) -exec clang-format -i {} +