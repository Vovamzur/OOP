#include "enemy.h"

Enemy::Enemy(int x, int y): StaticGameObject (x,y)
{
    this->isStone = false;
    this->canOccup = false;
}

void Enemy::setStone() {
    this->isStone = true;
}

void Enemy::Draw(QPainter& p) {
    QPixmap pix(":/imgs/img/bichoVerde.png");
    if(this->isStone) {
        pix.load(":/imgs/img/ovo.png");
    }
    int w = p.device()->width()/13;
    int h = p.device()->height()/14;
    int x = w*(1+this->x);
    int y = h*(2+this->y);
    p.drawPixmap(x, y, w, h, pix);
}

bool Enemy::getIsStone() {
    return this->isStone;
}

void Enemy::collision() {
    if(!this->isStone) {
        this->isStone = true;
    } else {
        this->destroyed = true;
    }
}
