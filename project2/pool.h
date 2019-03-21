#ifndef POOL_H
#define POOL_H
#include "image.h"

struct Pool
{
    unsigned int countOfBlocks;
    unsigned int sizeOfOneBlock;
    bool* arrayOfFree;
    char* startOfPool;

    char* Alloc();
    void Free(void* ptr);

    Pool(unsigned int countOfBlocks, unsigned int sizeOfOneBlock);
    ~Pool();
};

Image* pool_new(Pool *p);
void pool_delete(Image* img, Pool *p);

#endif // POOL_H
