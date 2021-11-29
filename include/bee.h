#ifndef BEE_H
#define BEE_H

#include "entity.h"

class Bee : public Entity
{
protected:
    POINT m_vel = POINT{0, 0};

public:
    Bee()
    {
        m_margin_left = 1;
        m_margin_right = 1;
        m_margin_bottom = 3;
        m_margin_top = 4;
    }

    void init(OBJ_ATTR *objData, SpriteData *sprite, POINT position = {0, 0}, POINT velocity = {0, 0});
    void update() override;
    void draw() override;
};

#endif // BEE_H