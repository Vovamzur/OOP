#include "game.h"

Game& Game::getInstance() {
    static Game game;
    return game;
}

Game::Game():
    levelFile("D://projects//game//AdventuresOfLolo//levels//level1.txt"),  
    loloBulletFactory(new LoloBulletFactory),
    enemyBulletFactory(new EnemyBulletFactory),
    out(new int{0}),
    bulletTimer(new QTimer()),
    bullet(nullptr),
    enemyBullet(nullptr),
    map(new Map())
{
    this->loadLevelFromFile();
}

Game::~Game() {
    this->levelFile.close();
    delete loloBulletFactory;
    delete enemyBulletFactory;
    delete out;
    if (this->bulletTimer) delete this->bulletTimer;
    delete this->map;
    if (this->bullet) delete this->bullet;
    if (this->enemyBullet) delete this->enemyBullet;
}

void Game::loadLevelFromFile(){
    this->levelFile >> *this->out;
    char c;
    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < 11; j++) {
            this->levelFile >> c;

            if (c == '1') {
                this->map->array[j][i] = new Block(j,i);
            } else if (c == '2') {
                this->map->countOfHearts++;
                this->map->array[j][i] = new Heart(j,i, &this->map->countOfHearts);
            } else if(c == '3') {
                this->map->array[j][i] = new Lolo(j, i, this->loloBulletFactory);
                this->map->lolo.reset(dynamic_cast<Lolo*>(this->map->array[j][i]));
            } else if (c == '4') {
                this->map->array[j][i] = new Chest(j,i);
                this->map->chest.reset(dynamic_cast<Chest*>(this->map->array[j][i]));
            } else if (c == '5') {
                this->map->array[j][i] = new Enemy(j,i);
            } else if (c == '6') {
                this->map->array[j][i] = new ArmedEnemy(j,i, this->enemyBulletFactory);
                this->map->armedEnemy.reset(dynamic_cast<ArmedEnemy*>(this->map->array[j][i]));
            } else this->map->array[j][i] = nullptr;
        }
    }
}

void Game::enemyShoot() {
    if(this->map->chest.data()->isOpen()) {
        if(!this->map->armedEnemy->getIsActive()) {
            this->map->armedEnemy->setActive();
        }
        if(!this->map->armedEnemy->getIsStone()) {
            if(this->map->armedEnemy->GetPosition().second == this->map->lolo.data()->GetPosition().second) {
                if(!this->enemyBullet) {
                    this->enemyBullet = this->map->armedEnemy->shoot();
                }
            }
        }
    }
}

void Game::gameMoveEnemyBullet() {
    if(this->enemyBullet) {
        this->enemyBullet->moveBullet();
        if(this->enemyBullet->isDestroyed()) {
            delete this->enemyBullet;
            this->enemyBullet = nullptr;
        }
    }
}

void Game::gameMoveBullet() {
    if(this->bullet) {
        this->bullet->moveBullet();
        if(this->map->array[this->bullet->GetPosition().first][this->bullet->GetPosition().second]) {
            this->map->checkCollision(this->bullet->GetPosition());
            this->bullet->collision();
        }
        if(this->bullet->isDestroyed()) {
            delete this->bullet;
            this->bullet = nullptr;
        }
    }
}

void Game::gameMoveLolo(Lolo::Direction dir) {
    this->map->lolo.data()->SetDirection(dir);
    if(this->map->possibilityToMoveByDir(dir)) {
        this->map->lolo->move(dir);
    }
    enemyShoot();
}
