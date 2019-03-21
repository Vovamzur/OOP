#include "chest.h"

Chest::Chest(int x,int y) : StaticGameObject(x,y)
{
    this->open = false;
    this->taken = false;
    this->canOccup = true;
    this->state = new struct Close();
}

void Chest::openChest() {
    this->open = true;
}

void Chest::closeChest() {
    this->open = false;
}

void Chest::setState(ChestState *s) {
    this->state = s;
}

void Chest::ChangeState() {
    this->state->next(this);
}

bool Chest::isTaken() {
    return this->taken;
}

bool Chest::isOpen() {
    return this->open;
}

void Chest::collision() {
    if(this->open && !this->taken) {
        this->taken = true;
    }
}

void Chest::Draw(QPainter& p) {
    QPixmap pix(":/imgs/img/bau.png");
    int w = p.device()->width()/13;
    int h = p.device()->height()/14;
    int x = w*(1+this->x);
    int y = h*(2+this->y);
    if(this->open && !this->taken) {
        pix.load(":/imgs/img/bauAberto.png");
    } else if (this->taken && this->open) {
        pix.load(":/imgs/img/bauVazio.png");
    }
    p.drawPixmap(x, y, w, h, pix);
}

