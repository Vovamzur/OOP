#include <image.h>
#include <iostream>
#include <fstream>

using namespace std;

void create_white(Image* res) {
    if(res != nullptr) {
        for(unsigned int i = 0; i < IMAGE_HEIGHT; i++) {
            for(unsigned int j = 0; j < IMAGE_WIDTH; j++) {
                res->pixelMatrix[i*IMAGE_HEIGHT+j].colorR = static_cast<unsigned char>(255);
                res->pixelMatrix[i*IMAGE_HEIGHT+j].colorG = static_cast<unsigned char>(255);
                res->pixelMatrix[i*IMAGE_HEIGHT+j].colorB = static_cast<unsigned char>(255);
            }
        }
    }
}

void create_black(Image* res) {
    if(res != nullptr) {
        for(unsigned int i = 0; i < IMAGE_HEIGHT; i++) {
            for(unsigned int j = 0; j < IMAGE_WIDTH; j++) {
                res->pixelMatrix[i*IMAGE_HEIGHT+j].colorR = static_cast<unsigned char>(0);
                res->pixelMatrix[i*IMAGE_HEIGHT+j].colorG = static_cast<unsigned char>(0);
                res->pixelMatrix[i*IMAGE_HEIGHT+j].colorB = static_cast<unsigned char>(0);
            }
        }
    }
}

void create_color(Image* res) {
    if(res != nullptr) {
        for(unsigned int i = 0; i < IMAGE_HEIGHT; i++) {
            for(unsigned int j = 0; j < IMAGE_WIDTH; j++) {
                unsigned int tmp = static_cast<unsigned int>(i*j);
                res->pixelMatrix[i*IMAGE_HEIGHT+j].colorR = static_cast<unsigned char>(tmp);
                res->pixelMatrix[i*IMAGE_HEIGHT+j].colorG = static_cast<unsigned char>(tmp);
                res->pixelMatrix[i*IMAGE_HEIGHT+j].colorB = static_cast<unsigned char>(tmp);
            }
        }
    }
}

void SaveImage(Image* img, string imageName) {
    if(img == nullptr) {
        return;
    }

    ofstream file(PATH + imageName + ".ppm", ios::binary);
    file << "P6" << endl
         << IMAGE_WIDTH << endl
         << IMAGE_HEIGHT << endl
         << "255" << endl;

    for(int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            file << img->pixelMatrix[i*IMAGE_WIDTH+j].colorB;
            file << img->pixelMatrix[i*IMAGE_WIDTH+j].colorG;
            file << img->pixelMatrix[i*IMAGE_WIDTH+j].colorR;
        }
    }
    file.close();
}

void LoadImage (Image *img, string imageName) {
    if (img == nullptr){
        return;
    }

    ifstream file(PATH + imageName + ".ppm", ios::binary);

    if(!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    } else cout << "File was openned successfully" << endl;

    string date1,date2,date3,date4;
    file >> date1 >> date2 >> date3 >> date4;

    for(unsigned int i = 0; i < IMAGE_HEIGHT; i++) {
        for (unsigned int j = 0; j < IMAGE_WIDTH; j++) {
            char* tmp = new char [3];
            file.read(tmp, 3);
            img->pixelMatrix[i*IMAGE_WIDTH+j].colorB = static_cast<unsigned char>(tmp[0]);
            img->pixelMatrix[i*IMAGE_WIDTH+j].colorG = static_cast<unsigned char>(tmp[1]);
            img->pixelMatrix[i*IMAGE_WIDTH+j].colorR = static_cast<unsigned char>(tmp[2]);
            delete [] (tmp);
        }
    }
    file.close();
}
