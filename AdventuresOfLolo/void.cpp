#include "void.h"

Void::Void(int x, int y) : StaticGameObject(x,y)
{
    this->o = StaticGameObject::Object::VOID;
}

Void::~Void() {

}
