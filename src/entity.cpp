#include "entity.h"

void Entity::clamp_to_screen(bool &hitX, bool &hitY)
{
    const int GAME_MARGIN = 24;

    const int X_MIN = GAME_MARGIN;
    const int X_MAX = SCREEN_WIDTH - GAME_MARGIN;
    const int Y_MIN = GAME_MARGIN;
    const int Y_MAX = SCREEN_HEIGHT - GAME_MARGIN;

    hitX = false;
    hitY = false;

    if (left() < X_MIN)
    {
        m_pos.x += X_MIN - left();
        hitX = true;
    }
    if (right() > X_MAX)
    {
        m_pos.x -= right() - X_MAX;
        hitX = true;
    }
    if (top() < Y_MIN)
    {
        m_pos.y += Y_MIN - top();
        hitY = true;
    }
    if (bottom() > Y_MAX)
    {
        m_pos.y -= bottom() - Y_MAX;
        hitY = true;
    }
}

void Entity::update()
{
}

void Entity::draw()
{
    obj_set_pos(m_objData, m_pos.x - halfwidth(), m_pos.y - halfheight());
}