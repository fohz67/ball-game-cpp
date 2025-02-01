#pragma once

#include <cstdint>
#include <stdexcept>
#include <vector>

struct ColorServer {
    static uint32_t vecToInt(const std::vector<double>& color) {
        if (color.size() != 4) {
            throw std::runtime_error("Error: Color vector must have exactly 4 "
                                     "elements (R, G, B, A).");
        }

        uint8_t r = static_cast<uint8_t>(color[0]);
        uint8_t g = static_cast<uint8_t>(color[1]);
        uint8_t b = static_cast<uint8_t>(color[2]);
        uint8_t a = static_cast<uint8_t>(color[3]);

        return (r << 24) | (g << 16) | (b << 8) | a;
    }

    static std::vector<double> intToVec(uint32_t color) {
        return {static_cast<double>((color >> 24) & 0xFF),
                static_cast<double>((color >> 16) & 0xFF),
                static_cast<double>((color >> 8) & 0xFF),
                static_cast<double>(color & 0xFF)};
    }
};
