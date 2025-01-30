#include "Server.hpp"
#include <iostream>

int main()
{
    try
    {
        Server server(12345);
        server.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Server error: " << e.what() << std::endl;
    }
    return 0;
}
