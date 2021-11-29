#include "bee.h"

void Bee::init(OBJ_ATTR *objData, SpriteData *sprite, POINT position, POINT velocity)
{
    m_objData = objData;
    m_spriteData = sprite;
    m_pos = position;
    m_vel = velocity;

    obj_set_attr(m_objData, ATTR0_SQUARE | ATTR0_8BPP, ATTR1_SIZE_16, ATTR2_ID(m_spriteData->tileId()));
}

void Bee::update()
{
    m_pos.x += m_vel.x;
    m_pos.y += m_vel.y;

    bool hitX, hitY;
    clamp_to_screen(hitX, hitY);
    if (hitX)
    {
        m_vel.x *= -1;
    }
    if (hitY)
    {
        m_vel.y *= -1;
    }
}

void Bee::draw()
{
    Entity::draw();
}