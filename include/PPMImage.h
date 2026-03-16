#ifndef RAYTRACING_PPMIMAGE_H
#define RAYTRACING_PPMIMAGE_H


class PPMImage {
private:
    int imageWidth;
    int imageHeight;
public:
    PPMImage(int width, int height);
    ~PPMImage();

    void setPixel(int x, int y);
    void save();
};

#endif