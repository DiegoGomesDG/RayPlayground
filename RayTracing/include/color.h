#ifndef RAYTRACING_COLOR_H
#define RAYTRACING_COLOR_H

#include "vec3.h"
#include "interval.h"

#include <glm/glm.hpp>

using color = vec3;

inline real linear_to_gamma(double linear_component) {
    if (linear_component > 0) {
        return std::sqrt(linear_component);
    }
    return 0.0;
}

inline void write_color(std::ostream &out, const color &pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Apply a linear to gamma transform for gamma 2
    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    /* Translate the [0, 1] component values to the byte range [0, 255]*/
    static const interval intensity(0.000, 0.999);
    int rbyte = static_cast<int>(256 * intensity.clamp(r));
    int gbyte = static_cast<int>(256 * intensity.clamp(g));
    int bbyte = static_cast<int>(256 * intensity.clamp(b));

    out << rbyte << ' ' << gbyte << ' ' << bbyte << std::endl;
}

inline glm::u8vec3 to_rgb8(const color& pixel_color)
{
    auto r = linear_to_gamma(pixel_color.x());
    auto g = linear_to_gamma(pixel_color.y());
    auto b = linear_to_gamma(pixel_color.z());

    static const interval intensity(0.000, 0.999);

    uint8_t rbyte = static_cast<uint8_t>(256 * intensity.clamp(r));
    uint8_t gbyte = static_cast<uint8_t>(256 * intensity.clamp(g));
    uint8_t bbyte = static_cast<uint8_t>(256 * intensity.clamp(b));

    return { rbyte, gbyte, bbyte };
}

inline uint32_t to_rgba(const color& pixel_color)
{
    auto r = linear_to_gamma(pixel_color.x());
    auto g = linear_to_gamma(pixel_color.y());
    auto b = linear_to_gamma(pixel_color.z());

    static const interval intensity(0.000, 0.999);

    uint8_t rbyte = static_cast<uint8_t>(256 * intensity.clamp(r));
    uint8_t gbyte = static_cast<uint8_t>(256 * intensity.clamp(g));
    uint8_t bbyte = static_cast<uint8_t>(256 * intensity.clamp(b));

    return (0xFF << 24) | (bbyte << 16) | (gbyte << 8) | rbyte;
}

#endif //RAYTRACING_COLOR_H