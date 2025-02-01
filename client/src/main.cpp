#include <iostream>
#include <stdexcept>
#include <string>
#include "Client.hpp"
#include "utils/ErrorHandling.hpp"

int main(const int ac, const char** av) {
    try {
        ErrorHandling::checkArgs(ac, av);
        Client::get().run(av);
    } catch (const std::exception& e) {
        std::cerr << "Client error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
