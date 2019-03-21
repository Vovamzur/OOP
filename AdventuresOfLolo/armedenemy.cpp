#include "armedenemy.h"

ArmedEnemy::ArmedEnemy(int x, int y, EnemyBulletFactory *fac) : Enemy (x,y) {
    this->factory = fac;
}

Bullet* ArmedEnemy::shoot() {
    return this->factory->createBullet(this->GetPosition().first, this->GetPosition().second);
}

void ArmedEnemy::setActive() {
    this->isActive = true;
}

bool ArmedEnemy::getIsActive() {
    return this->isActive;
}

void ArmedEnemy::Draw(QPainter& p) {
    QPixmap pix(":/imgs/img/bichoRosa2.png");
    if(this->isActive) {
        pix.load(":/imgs/img/bichoRosaAcordado2.png");
    }
    if(this->isStone) {
        pix.load(":/imgs/img/ovo.png");
    }
    int w = p.device()->width()/13;
    int h = p.device()->height()/14;
    int x = w*(1+this->x);
    int y = h*(2+this->y);
    p.drawPixmap(x, y, w, h, pix);
}
