#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QPair>
#include <drawable.h>

class StaticGameObject : public Drawable
{
protected:
    int x, y;
    bool canOccup;
    bool destroyed;

public:
    StaticGameObject(int, int);
    ~StaticGameObject() override {}
    QPair <int,int> GetPosition();

    bool isDestroyed();
    bool getCanOccup();

    virtual void collision() = 0;
    void Draw(QPainter&) override;
};

#endif // GAMEOBJECT_H
