#include <iostream>
#include <stdexcept>
#include <string>

#include "Client.hpp"
#include "util/Error.hpp"

int main(const int ac, const char** av)
{
    try
    {
        Error::checkArgs(ac, av);
        Client::get().run(av);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Client error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
