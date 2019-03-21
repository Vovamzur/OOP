#include "bulletanimation.h"

BulletAnimation::~BulletAnimation() {}

QPixmap LoloBulletAnimation::view() {
    QPixmap pix(":/imgs/img/caixa.png");
    return pix;
}

QPixmap EnemyBulletAnimation::view() {
    QPixmap pix(":/imgs/img/fire.png");
    return pix;
}
