#ifndef LOLO_H
#define LOLO_H

#include <staticgameobject.h>
#include <bullet.h>
#include <bulletfactory.h>

struct Lolo : public StaticGameObject
{
    enum class Direction{ UP, DOWN, LEFT, RIGHT};
    Lolo(int, int, LoloBulletFactory*);
    ~Lolo() override final {}

    void SetDirection(Direction);
    Bullet* shoot();
    void move(Direction);

    void collision() override final;
    void Draw(QPainter&) override final;
private:
    Direction direction;
    LoloBulletFactory *factory;
};

#endif // LOLO_H
