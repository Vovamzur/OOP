#ifndef MEMORYPOOL_H
#define MEMORYPOOL_H


class MemoryPool
{
    typedef unsigned int uint;
    typedef unsigned char uchar;

    uint numOfBlocks;
    uint numFreeBlocks;
    uint numInitialized;
    uchar* memStart;
    uchar* next; //num of next free block

public:
    MemoryPool(uint numOfBlocks);
    ~MemoryPool();

    void* pool_new();
    void pool_delete(void* ptr);
};


#endif // MEMORYPOOL_H
