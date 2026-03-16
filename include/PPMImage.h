#ifndef RAYTRACING_PPMIMAGE_H
#define RAYTRACING_PPMIMAGE_H

class PPMImage {
private:
    // TODO: Add 2D array to store the pixels
    int image_width;
    int image_height;
public:
    PPMImage(int width, int height);
    ~PPMImage();

    void set_pixel(int x, int y);
    void save();
    void sample();
};

#endif