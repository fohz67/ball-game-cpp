#include <iostream>
#include "Client.hpp"

int main() {
    try {
        Client::get().run();
    } catch (const std::exception& e) {
        std::cerr << "Client error: " << e.what() << std::endl;
    }
    return 0;
}
