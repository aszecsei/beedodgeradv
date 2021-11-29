#include "game_scene.h"

#include <tonc.h>

#include "BgGame.h"
#include "SprBee.h"
#include "SprPlayer.h"
#include "common.h"
#include "sprite_manager.h"

void GameScene::init()
{
    TiledScene::init();

    // BACKGROUND DATA
    // Load Palette
    memcpy16(pal_bg_mem, BgGamePal, BgGamePalLen / 2);
    // Load tiles into CBB 0
    memcpy32(&tile_mem[0][0], BgGameTiles, BgGameTilesLen / 4);
    // Load map into SBB 30
    memcpy16(&se_mem[30], BgGameMap, BgGameMapLen / 2);

    m_playerSpriteData = SpriteData(SprPlayerTiles, SprPlayerTilesLen, SprPlayerPal, SprPlayerPalLen);
    m_playerSpriteData.load();
    m_beeSpriteData = SpriteData(SprBeeTiles, SprBeeTilesLen, SprBeePal, SprBeePalLen);
    m_beeSpriteData.load();

    // Set up BG0 for an 8bb 30x20t map, using charblock 0 and screenblock 30
    REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;

    obj_set_attr(&obj_buffer[0], ATTR0_SQUARE | ATTR0_8BPP, ATTR1_SIZE_16, ATTR2_ID(m_playerSpriteData.tileId()));
    obj_set_attr(&obj_buffer[1], ATTR0_SQUARE | ATTR0_8BPP | ATTR0_AFF, ATTR1_SIZE_16 | ATTR1_AFF_ID(0),
                 ATTR2_ID(m_beeSpriteData.tileId()));
    obj_aff_identity(&obj_aff_buffer[0]);
}

void GameScene::clamp_to_screen(int &x, int &y, bool &hitX, bool &hitY)
{
    const int GAME_MARGIN = 24;

    const int X_MIN = 0 - 4 + GAME_MARGIN;
    const int X_MAX = SCREEN_WIDTH - 16 + 4 - GAME_MARGIN;
    const int Y_MIN = 0 - 2 + GAME_MARGIN;
    const int Y_MAX = SCREEN_HEIGHT - 16 + 2 - GAME_MARGIN;

    hitX = false;
    hitY = false;

    if (x <= X_MIN)
    {
        x = X_MIN;
        hitX = true;
    }
    if (x >= X_MAX)
    {
        x = X_MAX;
        hitX = true;
    }
    if (y <= Y_MIN)
    {
        y = Y_MIN;
        hitY = true;
    }
    if (y >= Y_MAX)
    {
        y = Y_MAX;
        hitY = true;
    }
}

void GameScene::update()
{
    TiledScene::update();

    m_vx = bit_tribool(key_is_down(-1), KI_RIGHT, KI_LEFT);
    m_vy = bit_tribool(key_is_down(-1), KI_DOWN, KI_UP);

    bool hitX;
    bool hitY;

    m_x += m_vx;
    m_y += m_vy;

    clamp_to_screen(m_x, m_y, hitX, hitY);

    m_bx += m_bvx;
    m_by += m_bvy;

    clamp_to_screen(m_bx, m_by, hitX, hitY);
    if (hitX)
    {
        m_bvx *= -1;
    }
    if (hitY)
    {
        m_bvy *= -1;
    }

    if (m_bvx > 0 && m_bvy > 0)
    {
        m_brot = 180 + 45;
    }
    else if (m_bvx > 0 && m_bvy < 0)
    {
        m_brot = 270 + 45;
    }
    else if (m_bvx < 0 && m_bvy > 0)
    {
        m_brot = 90 + 45;
    }
    else if (m_bvx < 0 && m_bvy < 0)
    {
        m_brot = 45;
    }
}

void GameScene::draw()
{
    TiledScene::draw();

    obj_set_pos(&obj_buffer[0], m_x, m_y);
    obj_set_pos(&obj_buffer[1], m_bx, m_by);

    obj_aff_rotate(&obj_aff_buffer[0], ANGLE(m_brot));
}

void GameScene::unload()
{
    m_beeSpriteData.unload();
    m_playerSpriteData.unload();
}