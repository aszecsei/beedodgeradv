#include "bee.h"

void Bee::clamp_to_screen(bool &hitX, bool &hitY)
{
    const int GAME_MARGIN = 24;

    const int X_MIN = 0 - m_margin_left + GAME_MARGIN;
    const int X_MAX = SCREEN_WIDTH - m_width + m_margin_right - GAME_MARGIN;
    const int Y_MIN = 0 - m_margin_top + GAME_MARGIN;
    const int Y_MAX = SCREEN_HEIGHT - m_height + m_margin_bottom - GAME_MARGIN;

    hitX = false;
    hitY = false;

    if (m_pos.x <= X_MIN)
    {
        m_pos.x = X_MIN;
        hitX = true;
    }
    if (m_pos.x >= X_MAX)
    {
        m_pos.x = X_MAX;
        hitX = true;
    }
    if (m_pos.y <= Y_MIN)
    {
        m_pos.y = Y_MIN;
        hitY = true;
    }
    if (m_pos.y >= Y_MAX)
    {
        m_pos.y = Y_MAX;
        hitY = true;
    }
}

void Bee::init(OBJ_ATTR *objData, SpriteData *sprite, POINT position)
{
    m_objData = objData;
    m_spriteData = sprite;
    m_pos = position;

    obj_set_attr(m_objData, ATTR0_SQUARE | ATTR0_8BPP, ATTR1_SIZE_16, ATTR2_ID(m_spriteData->tileId()));
}

void Bee::update()
{
    bool hitX, hitY;
    clamp_to_screen(hitX, hitY);
}

void Bee::draw()
{
    obj_set_attr(m_objData, ATTR0_SQUARE | ATTR0_8BPP, ATTR1_SIZE_16, ATTR2_ID(m_spriteData->tileId()));
    obj_set_pos(m_objData, m_pos.x, m_pos.y);
}