#include "lolo.h"

Lolo::Lolo(int x,int y, LoloBulletFactory *fac) : StaticGameObject(x,y) {
    this->direction = Direction::DOWN;
    this->canOccup = true;
    this->factory = fac;
}

void Lolo::SetDirection(Direction dir) {
    this->direction = dir;
}

Bullet* Lolo::shoot() {
    int trajectoryX = 0;
    int trajectoryY = 0;
    switch(this->direction) {
    case Direction::DOWN:  {trajectoryY = 1;  break; }
    case Direction::UP:    {trajectoryY = -1; break; }
    case Direction::LEFT:  {trajectoryX = -1; break; }
    case Direction::RIGHT: {trajectoryX = 1;  break; }
    }
    return this->factory->createBullet(this->GetPosition().first, this->GetPosition().second, trajectoryX, trajectoryY);
}

void Lolo::move(Direction dir) {
    switch (dir) {
    case Direction::UP: {
        this->y--;
        break;
    }
    case Direction::DOWN: {
        this->y++;
        break;
    }
    case Direction::RIGHT:{
        this->x++;
        break;
    }
    case Direction::LEFT: {
        this->x--;
        break;
    }
    }
}

void Lolo::Draw(QPainter& p) {
    QPixmap pix(":/imgs/img/loloU.png");
    int w = p.device()->width()/13;
    int h = p.device()->height()/14;
    int x = w*(1+this->x);
    int y = h*(2+this->y);
    switch(this->direction) {
    case Direction::UP: {
        pix.load(":/imgs/img/loloU.png");
        break;
    }
    case Direction::DOWN: {
        pix.load(":/imgs/img/lolo.png");
        break;
    }
    case Direction::LEFT: {
        pix.load(":/imgs/img/loloL.png");
        break;
    }
    case Direction::RIGHT: {
        pix.load(":/imgs/img/loloR.png");
        break;
    }
    }
    p.drawPixmap(x, y, w, h, pix);
}

void Lolo::collision() {
    this->destroyed = true;
}
