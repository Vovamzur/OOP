#include "memorypool.h"

MemoryPool::MemoryPool(uint numOfBlocks):
    numOfBlocks(numOfBlocks),
    numFreeBlocks(0),
    numInitialized(0),
    memStart(nullptr),
    next(nullptr)
{ }

MemoryPool::~MemoryPool(){
    delete [] memStart;
}

void* pool_new()
