#include <iostream>
#include <stdexcept>
#include <string>

#include "Client.hpp"

int main(const int ac, const char** av)
{
    try
    {
        Client::get().run(ac, av);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Client error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
