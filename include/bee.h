#ifndef BEE_H
#define BEE_H

#include "sprite.h"
#include <tonc.h>

class Bee
{
private:
    SpriteData *m_spriteData;
    POINT m_pos;
    OBJ_ATTR *m_objData;

    u32 m_width;
    u32 m_height;

    s32 m_margin_left;
    s32 m_margin_right;
    s32 m_margin_top;
    s32 m_margin_bottom;

    void clamp_to_screen(bool &hitX, bool &hitY);

public:
    Bee()
        : m_spriteData(nullptr)
        , m_pos({0, 0})
        , m_objData(nullptr)
        , m_width(16)
        , m_height(16)
        , m_margin_left(5)
        , m_margin_right(5)
        , m_margin_top(2)
        , m_margin_bottom(2)
    {
    }

    void init(OBJ_ATTR *objData, SpriteData *sprite, POINT position = {0});
    void update();
    void draw();
};

#endif // BEE_H