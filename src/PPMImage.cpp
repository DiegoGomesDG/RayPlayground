#include "PPMImage.h"

#include "color.h"
#include "vec3.h"

#include <iostream>
#include <ostream>

PPMImage::PPMImage(int width, int height) : image_width(width), image_height(height) {}

PPMImage::~PPMImage() {}

void PPMImage::set_pixel(int x, int y) {
}

void PPMImage::save() {
}

void PPMImage::sample() {
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines Remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_color = color(double(i)/(image_width - 1), double(j)/(image_height - 1), 0);
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rDone.       \n";
}
