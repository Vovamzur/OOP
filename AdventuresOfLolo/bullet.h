#ifndef BULLET_H
#define BULLET_H

#include <staticgameobject.h>
#include <bulletanimation.h>

class Bullet : public StaticGameObject
{
protected:
    int m_trajectoryX;
    int m_trajectoryY;

    double m_x;
    double m_y;

    bool isOutOfField();
    BulletAnimation *animation;

public:
    Bullet(int, int, int, int, BulletAnimation*);
    //Bullet(int&, int&, int, int, BulletAnimation*);
    ~Bullet() override;
    void moveBullet();

    void collision() override final;
    void Draw(QPainter&) override;
};

#endif // BULLET_H
