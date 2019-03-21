#ifndef HEART_H
#define HEART_H

#include <staticgameobject.h>
#include <chest.h>

#include <qdebug.h>
#include <QString>

struct Heart : public StaticGameObject
{
    int* count;
    Heart(int, int, int*);
    ~Heart() override final {}

    void collision() override final;
    void Draw(QPainter&) override final;
};

#endif // HEART_H
