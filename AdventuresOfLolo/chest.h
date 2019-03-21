#pragma once

#ifndef CHEST_H
#define CHEST_H

#include <staticgameobject.h>
#include <cheststate.h>

class Chest : public StaticGameObject
{
    ChestState *state;

    bool open;
    bool taken;
public:
    int *countOfHeart;

    void setState(ChestState *s);
    void ChangeState();

    Chest(int, int);
    ~Chest() override final{}
    bool isTaken();
    bool isOpen();

    void openChest();
    void closeChest();

    void collision() override final;
    void Draw(QPainter&) override final;
};

#endif // CHEST_H
