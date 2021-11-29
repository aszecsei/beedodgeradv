#include "player.h"

void Player::init(OBJ_ATTR *objData, SpriteData *sprite, POINT position)
{
    m_objData = objData;
    m_spriteData = sprite;
    m_pos = position;

    obj_set_attr(m_objData, ATTR0_SQUARE | ATTR0_8BPP, ATTR1_SIZE_16, ATTR2_ID(m_spriteData->tileId()));
}

void Player::update()
{
    int vx = bit_tribool(key_is_down(-1), KI_RIGHT, KI_LEFT);
    int vy = bit_tribool(key_is_down(-1), KI_DOWN, KI_UP);

    m_pos.x += vx;
    m_pos.y += vy;

    bool hitX, hitY;
    clamp_to_screen(hitX, hitY);
}

void Player::draw()
{
    Entity::draw();
}