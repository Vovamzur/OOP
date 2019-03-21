#ifndef VOID_H
#define VOID_H

#include <staticgameobject.h>

class Void : public StaticGameObject
{
public:
    Void(int, int);
    ~Void() override final;
};

#endif // VOID_H
