#ifndef BULLETANIMATION_H
#define BULLETANIMATION_H

#include <QPixmap>

struct BulletAnimation
{
    virtual QPixmap view() = 0;
    virtual ~BulletAnimation() = 0;
};

struct EnemyBulletAnimation : public BulletAnimation {
    QPixmap view() override final;
    ~EnemyBulletAnimation() override final {}
};

struct LoloBulletAnimation : public BulletAnimation {
    QPixmap view() override final;
    ~LoloBulletAnimation() override final {}
};

#endif // BULLETANIMATION_H
