#ifndef ENTITY_H
#define ENTITY_H

#include "sprite.h"

class Entity
{
public:
    Sprite sprite;
    POINT position;

    Entity()
    {
    }
};

#endif // ENTITY_H