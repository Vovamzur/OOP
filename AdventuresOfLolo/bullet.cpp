#include "bullet.h"

Bullet::Bullet(int x, int y, int trajectoryX, int trajectoryY, BulletAnimation *an) : StaticGameObject(x,y)
{
    this->m_x = x;
    this->m_y = y;
    this->m_trajectoryX = trajectoryX;
    this->m_trajectoryY = trajectoryY;
    this->animation = an;
}

Bullet::~Bullet() {
    delete this->animation;
}

void Bullet::moveBullet() {
    this->m_x += this->m_trajectoryX * 0.1;
    this->m_y += this->m_trajectoryY * 0.1;
    this->x = static_cast<int>(ceil(this->m_x));
    this->y = static_cast<int>(ceil(this->m_y));
    if(this->isOutOfField()) {
        this->destroyed = true;
    }
}

bool Bullet::isOutOfField() {
    if (this->m_y < 0 || this->m_y > 10 || this->m_x < 0 || this->m_x > 10) return true;
    return false;
}

void Bullet::Draw(QPainter& p) { 
    int w = p.device()->width()/13;
    int h = p.device()->height()/14;
    int x = static_cast<int>(w*(1+this->m_x));
    int y = static_cast<int>(h*(2+this->m_y));
    p.drawPixmap(x, y, w, h, this->animation->view());
}

void Bullet::collision() {
    this->destroyed = true;
}
