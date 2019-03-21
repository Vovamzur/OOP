#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <QPainter>

struct Drawable
{
protected:
    virtual ~Drawable() = default;
    virtual void Draw(QPainter&) = 0;
};

#endif // DRAWABLE_H
