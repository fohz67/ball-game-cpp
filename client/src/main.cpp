#include <iostream>
#include "Client.hpp"

int main() {
    try {
        Client client("127.0.0.1", 12345);
        client.start();
    } catch (const std::exception& e) {
        std::cerr << "Client error: " << e.what() << std::endl;
    }
    return 0;
}
