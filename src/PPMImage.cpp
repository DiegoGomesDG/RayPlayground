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

void PPMImage::sample() {}
