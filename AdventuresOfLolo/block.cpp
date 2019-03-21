#include "block.h"

Block::Block(int x, int y) : StaticGameObject (x,y) {
    this->canOccup = false;
}

void Block::Draw(QPainter& p) {
    QPixmap pix(":/imgs/img/pedra.png");
    int w = p.device()->width()/13;
    int h = p.device()->height()/14;
    int x = w*(1+this->x);
    int y = h*(2+this->y);
    p.drawPixmap(x,y, w, h, pix);
}

void Block::collision() {}
