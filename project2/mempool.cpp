#include <mempool.h>
#include <iostream>

using namespace std;

MemPool::MemPool(){
    for(unsigned int i = 0; i<imgNumber; i++){
            Ptr* pointer = reinterpret_cast<Ptr*>(arr + (imgNumber-1)*blockSize - i*blockSize);
            pointer->Next = linkedList;
            linkedList = pointer;
            pointer->isFree = true;
    }
}

MemPool::~MemPool()
{
    cout << "Memory was cleared!" << endl;
    delete[] arr;
}

Image* pool_new(MemPool* pool){

    MemPool::Ptr* pointer = pool->linkedList;

    for(unsigned int i = 0; i<pool->imgNumber; i++)
    {
            if(pointer->isFree == true)
            {
               Image* picture = reinterpret_cast<Image*>(sizeof(MemPool::Ptr)+reinterpret_cast<char*>(pointer));
               picture->pixelMatrix = reinterpret_cast<Pixel*>(sizeof(Image)+reinterpret_cast<char*>(picture));
               pointer->isFree = false;
               cout<<"Picture created"<<endl;
               return picture;
            }
            else
            {
                pointer = pointer->Next;
            }
    }

    cout<<"MemoryPool filled"<<endl;
    return nullptr;
}

void pool_delete(MemPool* pool, Image* picture) {
    MemPool::Ptr* pointer = pool->linkedList;

    for(unsigned int i = 0; i<=pool->imgNumber; i++){
            if(picture == reinterpret_cast<Image*>(reinterpret_cast<char*>(pointer)+sizeof(MemPool::Ptr))
                    && pointer->isFree == false){
                pointer->isFree = true;
                cout<<"Picture deleted"<<endl;
                return;
            }
            else{
                pointer = pointer->Next;
            }
    }
    cout<<"MemoryPool is free"<<endl;
}

