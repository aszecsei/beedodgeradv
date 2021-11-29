#ifndef ENTITY_H
#define ENTITY_H

#include "sprite.h"
#include <tonc.h>

class Entity
{
protected:
    SpriteData *m_spriteData = nullptr;
    POINT m_pos = POINT{0, 0};
    OBJ_ATTR *m_objData = nullptr;

    u32 m_width = 16;
    u32 m_height = 16;

    s32 m_margin_left = 0;
    s32 m_margin_right = 0;
    s32 m_margin_top = 0;
    s32 m_margin_bottom = 0;

    void clamp_to_screen(bool &hitX, bool &hitY);

public:
    virtual void update();
    virtual void draw();

    inline u32 halfwidth() const
    {
        return m_width / 2;
    }
    inline u32 halfheight() const
    {
        return m_height / 2;
    }
    inline s32 left() const
    {
        return m_pos.x + m_margin_left - (s32)halfwidth();
    }
    inline s32 right() const
    {
        return m_pos.x - m_margin_right + (s32)halfwidth();
    }
    inline s32 top() const
    {
        return m_pos.y + m_margin_top - (s32)halfheight();
    }
    inline s32 bottom() const
    {
        return m_pos.y - m_margin_bottom + (s32)halfheight();
    }
};

#endif // ENTITY_H