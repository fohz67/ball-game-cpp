#include <iostream>

#include "Server.hpp"

int main()
{
    try
    {
        Server::get().run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Server error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
