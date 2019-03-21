#include <iostream>
#include "mempool.h"
#include "image.h"
#include "pool.h"

using namespace std;

int main()
{
    unsigned int countOfBlocks = 5;
    unsigned int sizeOfBlock = sizeof(Image)+IMAGE_HEIGHT*IMAGE_WIDTH*sizeof(Pixel);
    Pool *p = new Pool(countOfBlocks, sizeOfBlock);

    Image* pictures [6];
    for(int i = 0; i < 6; i++) {
        pictures[i] = pool_new(p);
    }

    create_white(pictures[0]);
    SaveImage(pictures[0], "WHITE1");

    create_black(pictures[1]);
    SaveImage(pictures[1], "BLACK1");

    create_color(pictures[2]);
    SaveImage(pictures[2], "COLOR1");

    create_white(pictures[3]);
    SaveImage(pictures[3], "WHITE2");

    create_black(pictures[4]);
    SaveImage(pictures[4], "BLACK2");

    create_color(pictures[5]);
    SaveImage(pictures[5], "COLOR2");

    pool_delete(pictures[2], p);

    delete p;
}
