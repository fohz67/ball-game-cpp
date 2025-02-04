#include "utils/ErrorHandling.hpp"
#include <regex>
#include <stdexcept>

void ErrorHandling::checkArgs(const int ac, const char** av) {
    if (ac > 1) {
        std::string ip(av[1]);
        std::regex  ipRegex(
            R"(^(?:(?:25[0-5]|2[0-4][0-9]|1?[0-9]?[0-9])\.){3}(?:25[0-5]|2[0-4][0-9]|1?[0-9]?[0-9])$)");

        if (!std::regex_match(ip, ipRegex)) {
            throw std::runtime_error("Error: Invalid IP address format. "
                                     "Expected format: X.X.X.X (0-255).");
        }
    }

    if (ac > 2) {
        std::string port(av[2]);
        std::regex  portRegex(
            R"(^([1-9][0-9]{3,4}|102[4-9]|10[3-9][0-9]|1[1-9][0-9]{2}|[2-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$)");

        if (!std::regex_match(port, portRegex)) {
            throw std::runtime_error("Error: Invalid port number. Must be between 1024 and 65535.");
        }
    }
}
