#include "game_scene.h"
#include "BgGame.h"
#include "SprPlayer.h"
#include <tonc.h>

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

    // PLAYER DATA
    // Load Palette
    memcpy16(pal_obj_mem, SprPlayerPal, SprPlayerPalLen / 2);
    // Load tiles into CBB 4
    memcpy32(&tile_mem[4], SprPlayerTiles, SprPlayerTilesLen / 4);

    // Set up BG0 for an 8bb 30x20t map, using charblock 0 and screenblock 30
    REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;

    obj_set_attr(obj_buffer, ATTR0_SQUARE | ATTR0_8BPP, ATTR1_SIZE_16, 0 | 0);
}

void GameScene::bounce_off_screen_edges()
{
    const int GAME_MARGIN = 24;

    const int X_MIN = 0 - 4 + GAME_MARGIN;
    const int X_MAX = SCREEN_WIDTH - 16 + 4 - GAME_MARGIN;
    const int Y_MIN = 0 - 2 + GAME_MARGIN;
    const int Y_MAX = SCREEN_HEIGHT - 16 + 2 - GAME_MARGIN;

    if (m_x <= X_MIN)
    {
        m_x = X_MIN;
        m_vx *= -1;
    }
    if (m_x >= X_MAX)
    {
        m_x = X_MAX;
        m_vx *= -1;
    }
    if (m_y <= Y_MIN)
    {
        m_y = Y_MIN;
        m_vy *= -1;
    }
    if (m_y >= Y_MAX)
    {
        m_y = Y_MAX;
        m_vy *= -1;
    }
}

void GameScene::update()
{
    TiledScene::update();

    m_x += m_vx;
    m_y += m_vy;
    bounce_off_screen_edges();
}

void GameScene::draw()
{
    TiledScene::draw();
    obj_set_pos(obj_buffer, m_x, m_y);
}