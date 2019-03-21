#include "map.h"

Map::Map():
    lolo(nullptr),
    chest(nullptr),
    armedEnemy(nullptr),
    countOfHearts(0)
{
    this->array = new StaticGameObject**[11];
    for(int i = 0 ; i < 11; i++) {
        this->array[i] = new StaticGameObject*[11];
    }
}

Map::~Map() {
    for(int i = 0; i < 11; i++) {
        delete[] array[i];
    }
    delete[] array;
}


bool Map::possibilityToMove(int x, int y) {
    if(x < 11 && y < 11 && x > -1 && y  > -1) {
        if(!this->array[x][y]) {
            return true;
        }
        if(this->array[x][y]->getCanOccup()) {
            this->checkCollision(QPair<int,int>(x, y));
            if(this->countOfHearts == 0 && !this->chest.data()->isOpen()) {
//                this->chest.data()->openChest();
                this->chest.data()->ChangeState();
            }
            return true;
        }
    }
    return false;
}

bool Map::possibilityToMoveByDir(Lolo::Direction dir) {
    int x = this->lolo->GetPosition().first;
    int y = this->lolo->GetPosition().second;
    switch (dir) {
    case Lolo::Direction::UP: {
        if(this->possibilityToMove(x, y-1)) {
            return true;
        }
        break;
    }
    case Lolo::Direction::DOWN: {
        if(this->possibilityToMove(x,y+1)) {
            return true;
        }
        break;
    }
    case Lolo::Direction::RIGHT: {
        if(this->possibilityToMove(x+1, y)) {
            return true;
        }
        break;
    }
    case Lolo::Direction::LEFT: {
        if(this->possibilityToMove(x-1, y)) {
            return true;
        }
        break;
    }
    }
    return false;
}

void Map::Draw(QPainter& painter) {
    for(int i = 0 ; i < 11; i++) {
        for(int j = 0; j < 11; j++) {
            if(this->array[i][j]) {
                this->array[i][j]->Draw(painter);
            }
        }
    }
    this->lolo->Draw(painter);
}

void Map::checkCollision(QPair<int,int> p) {
//    if(!this->array[p.first][p.second]) {
//        if(this->lolo->GetPosition() == p) {
//            this->lolo.take();
//        }
//    } else {
//        this->array[p.first][p.second]->collision();
//        if(this->array[p.first][p.second]->isDestroyed()) {
//            delete this->array[p.first][p.second];
//            this->array[p.first][p.second] = nullptr;
//        }
//    }
    this->array[p.first][p.second]->collision();
    if(this->array[p.first][p.second]->isDestroyed()) {
        delete this->array[p.first][p.second];
        this->array[p.first][p.second] = nullptr;
    }
}
