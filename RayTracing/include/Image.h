#ifndef RAYTRACING_IMAGE_H
#define RAYTRACING_IMAGE_H
#include "color.h"

class Image {
public:
    int width, height;
    std::vector<color> pixels;

    Image(int width, int height) : width(width), height(height), pixels(width * height) {}

    void set_pixel(int x, int y, const color &c) {
        pixels[y * width + x] = c;
    }

    const color &get_pixel(int x, int y) const {
        return pixels[y * width + x];
    }

    void write_ppm(std::ostream &out) const {

        out << "P3\n" << width << ' ' << height << "\n255\n";
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                write_color(out, get_pixel(i, j));
            }
        }
    }
};

#endif //RAYTRACING_IMAGE_H