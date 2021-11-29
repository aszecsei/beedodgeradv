#ifndef ENTITY_H
#define ENTITY_H

#include "sprite.h"

class Entity
{
public:
    SpriteData sprite;
    POINT position;

    Entity()
    {
    }
};

#endif // ENTITY_H