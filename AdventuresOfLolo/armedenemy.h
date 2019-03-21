#ifndef ARMEDENEMY_H
#define ARMEDENEMY_H

#include <enemy.h>
#include <enemybullet.h>
#include <bulletfactory.h>

class ArmedEnemy : public Enemy
{
private:
    bool isActive;
    EnemyBulletFactory *factory;
public:
    ArmedEnemy(int,int, EnemyBulletFactory*);

    void setActive();
    bool getIsActive();

    Bullet* shoot();

    void Draw(QPainter&) override final;
};

#endif // ARMEDENEMY_H
