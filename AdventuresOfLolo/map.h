#ifndef MAP_H
#define MAP_H

#include <staticgameobject.h>
#include <heart.h>
#include <chest.h>
#include <lolo.h>
#include <enemy.h>
#include <armedenemy.h>
#include <block.h>

struct Map
{
private:
    bool possibilityToMove(int,int);
public:
    StaticGameObject ***array;

    QScopedPointer<Lolo> lolo;
    QScopedPointer<Chest> chest;
    QScopedPointer<ArmedEnemy> armedEnemy;

    int countOfHearts;

    Map();
    ~Map();
    bool possibilityToMoveByDir(Lolo::Direction);
    void checkCollision(QPair<int,int>);

    void Draw(QPainter&);
};

#endif // MAP_H
