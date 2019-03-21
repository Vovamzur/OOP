#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H

#include <bullet.h>
#include <bulletanimation.h>

struct Factory {
    virtual Bullet* createBullet(int,int,int,int) = 0;
    virtual ~Factory() = default;
};

struct LoloBulletFactory : public Factory {
    Bullet * createBullet(int x, int y, int trX, int trY) override final {
        return new Bullet(x,y, trX, trY, new LoloBulletAnimation);
    }
};

struct EnemyBulletFactory : public Factory {
    Bullet * createBullet(int x, int y, int trX = 1, int trY = 0) override final {
        return new Bullet(x,y, trX, trY, new EnemyBulletAnimation);
    }
};

#endif // BULLETFACTORY_H
