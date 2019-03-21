#ifndef BLOCK_H
#define BLOCK_H

#include <staticgameobject.h>

struct Block : public StaticGameObject
{
    Block(int,int);
    ~Block() override final{}

    void collision() override final;
    void Draw(QPainter&) override final;
};

#endif // BLOCK_H
