#include "staticgameobject.h"

StaticGameObject::StaticGameObject(int x, int y):
    x(x),
    y(y),
    canOccup(false),
    destroyed(false)
{}

QPair <int ,int > StaticGameObject::GetPosition() {
    QPair <int,int> position;
    position.first = this->x;
    position.second = this->y;
    return position;
}

void StaticGameObject::Draw(QPainter&) {}

bool StaticGameObject::getCanOccup() {
    return this->canOccup;
}

bool StaticGameObject::isDestroyed() {
    return this->destroyed;
}
