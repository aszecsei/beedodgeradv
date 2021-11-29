#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
public:
    Player()
    {
        m_margin_left = 5;
        m_margin_right = 5;
        m_margin_top = 2;
        m_margin_bottom = 2;
    }

    void init(OBJ_ATTR *objData, SpriteData *sprite, POINT position = {0});
    void update() override;
    void draw() override;
};

#endif // PLAYER_H