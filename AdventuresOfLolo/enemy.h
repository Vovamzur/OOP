#ifndef ENEMY_H
#define ENEMY_H

#include <staticgameobject.h>

struct Enemy : public StaticGameObject
{
    Enemy(int,int);
    ~Enemy() override {}
    void setStone();
    bool getIsStone();

    void collision() override final;
    void Draw(QPainter&) override;

protected:
    bool isStone;
};

#endif // ENEMY_H
