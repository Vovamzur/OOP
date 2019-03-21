#include"image.h"
#ifndef MEMPOOL_H
#define MEMPOOL_H

struct MemPool{

    struct Ptr{
        Ptr* Next = nullptr;
        bool isFree = true;
    };

    unsigned int imgNumber = 4;
    unsigned int blockSize = sizeof(Image) +
            (IMAGE_HEIGHT * IMAGE_WIDTH) * sizeof(Pixel) + sizeof (Ptr);
    char* arr = new char[blockSize * imgNumber];
    Ptr* linkedList = reinterpret_cast<Ptr*>(arr + (imgNumber-1)*blockSize);

    MemPool();
    ~MemPool();
};

Image* pool_new(MemPool* pool);
void pool_delete(MemPool* pool, Image* colorPicture);

#endif // MEMPOOL_H
