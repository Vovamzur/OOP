#ifndef GAME_H
#define GAME_H

#include <fstream>
#include <QTimer>
#include <map.h>
#include <bulletfactory.h>

class Game
{
    std::ifstream levelFile;
    void loadLevelFromFile();
    void checkCollWithLolo();
    void enemyShoot();

    Game();
    ~Game();
    Game(const Game& rhs) = delete;
    Game& operator=(const Game& rhs) = delete;

    LoloBulletFactory *loloBulletFactory;
    EnemyBulletFactory *enemyBulletFactory;

public:   
    int *out;
    QTimer *bulletTimer;    
    Bullet *bullet;
    Bullet *enemyBullet;
    Map* map;

    static Game& getInstance();

    void gameMoveLolo(Lolo::Direction);
    void gameMoveBullet();
    void gameMoveEnemyBullet();
};

#endif // GAME_H
