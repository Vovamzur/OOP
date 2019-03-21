#include "pool.h"
#include <iostream>
#include "image.h"

using namespace std;

char* Pool::Alloc()
{
    char* newPoolImg = nullptr;
    for(unsigned int i = 0; i < countOfBlocks; i++) {
        if(arrayOfFree[i]) {
            newPoolImg = startOfPool + i*sizeOfOneBlock;
            arrayOfFree[i] = false;
            break;
        }
    }
    if(!newPoolImg) {
        cout << "Memeory is full" << endl;
        return nullptr;
    }
    cout << "Memory is successfully allocated" << endl;
    return newPoolImg;
}

void Pool::Free(void* ptr)
{
    uint8_t i = static_cast<uint8_t>(reinterpret_cast<char*>(ptr)-startOfPool)/sizeOfOneBlock;
    arrayOfFree[i] = true;
    cout << "Removed data from memory!" << endl;
}

Pool::Pool(unsigned int number, unsigned int blockSize)
{
    countOfBlocks = number;
    sizeOfOneBlock = blockSize;
    arrayOfFree = new bool[countOfBlocks];
    for(unsigned int i = 0; i < countOfBlocks; i++) {
        arrayOfFree[i] = true;
    }
    startOfPool = new char[number*blockSize];
}

Pool::~Pool()
{
    delete startOfPool;
    delete [] arrayOfFree;
}

Image* pool_new(Pool *p)
{
    char* ptr = p->Alloc();
    if(ptr == nullptr) return nullptr;
    Image *img = reinterpret_cast<Image*>(ptr);
    img->pixelMatrix = reinterpret_cast<Pixel*>(reinterpret_cast<char*>(img) + sizeof(Pixel*));
    return img;
}

void pool_delete(Image* img, Pool * pool) {
    pool->Free(reinterpret_cast<void*>(img));
}
