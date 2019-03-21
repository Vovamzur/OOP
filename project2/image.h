#include <iostream>
#ifndef IMAGE_H
#define IMAGE_H

using namespace std;

const string PATH = "D:\\projects\\project2\\files\\";
const int IMAGE_HEIGHT = 256;
const int IMAGE_WIDTH = 256;

struct Pixel {
    unsigned char colorR;
    unsigned char colorG;
    unsigned char colorB;
};

struct Image {
    Pixel *pixelMatrix;
};

void create_white(Image* res);
void create_black(Image* res);
void create_color(Image* res);
void SaveImage(Image* img, string imageName);
void LoadImage(Image* img, string imageName);

#endif // IMAGE_H
