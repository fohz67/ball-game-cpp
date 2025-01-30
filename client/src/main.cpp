#include <iostream>
#include "Client.hpp"

int main(const int ac, const char **av) {
    try {
        if (ac < 3) {
            std::cerr << "Usage: " << av[0] << " <server_ip> <server_port>" << std::endl;
            return 84;
        }
        Client::get().run(av);
    } catch (const std::exception& e) {
        std::cerr << "Client error: " << e.what() << std::endl;
    }
    return 0;
}
