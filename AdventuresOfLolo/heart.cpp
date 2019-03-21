#include "heart.h"

Heart::Heart(int x, int y, int* count) : StaticGameObject (x,y) {
    this->canOccup = true;
    this->count = count;
}

void Heart::Draw(QPainter& p) {
    QPixmap pix(":/imgs/img/coracao.png");
    int w = p.device()->width()/13;
    int h = p.device()->height()/14;
    int x = w*(1+this->x);
    int y = h*(2+this->y);
    p.drawPixmap(x, y, w, h, pix);
}

void Heart::collision() {
    (*this->count)--;
    this->destroyed = true;
}
