#include "game_scene.h"
#include "sprite_manager.h"
#include <tonc.h>

#include "BgGame.h"
#include "SprPlayer.h"
#include "SprBee.h"

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
    // Load tiles
    int playerTileId;
    void *playerTileMem = SpriteManager::instance().allocate(SprPlayerTilesLen, playerTileId);
    memcpy32(playerTileMem, SprPlayerTiles, SprPlayerTilesLen / 4);

    // BEE DATA
    // Load tiles
    int beeTileId;
    void *beeTileMem = SpriteManager::instance().allocate(SprBeeTilesLen, beeTileId);
    memcpy32(beeTileMem, SprBeeTiles, SprBeeTilesLen / 4);

    // Set up BG0 for an 8bb 30x20t map, using charblock 0 and screenblock 30
    REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;

    obj_set_attr(&obj_buffer[0], ATTR0_SQUARE | ATTR0_8BPP, ATTR1_SIZE_16, ATTR2_ID(playerTileId));
    obj_set_attr(&obj_buffer[1], ATTR0_SQUARE | ATTR0_8BPP, ATTR1_SIZE_16, ATTR2_ID(beeTileId));
}

void GameScene::clamp_to_screen()
{
    const int GAME_MARGIN = 24;

    const int X_MIN = 0 - 4 + GAME_MARGIN;
    const int X_MAX = SCREEN_WIDTH - 16 + 4 - GAME_MARGIN;
    const int Y_MIN = 0 - 2 + GAME_MARGIN;
    const int Y_MAX = SCREEN_HEIGHT - 16 + 2 - GAME_MARGIN;

    if (m_x <= X_MIN)
    {
        m_x = X_MIN;
    }
    if (m_x >= X_MAX)
    {
        m_x = X_MAX;
    }
    if (m_y <= Y_MIN)
    {
        m_y = Y_MIN;
    }
    if (m_y >= Y_MAX)
    {
        m_y = Y_MAX;
    }
}

void GameScene::update()
{
    TiledScene::update();

    m_vx = bit_tribool(key_is_down(-1), KI_RIGHT, KI_LEFT);
    m_vy = bit_tribool(key_is_down(-1), KI_DOWN, KI_UP);

    m_x += m_vx;
    m_y += m_vy;

    clamp_to_screen();
}

void GameScene::draw()
{
    TiledScene::draw();

    obj_set_pos(&obj_buffer[0], m_x, m_y);
    obj_set_pos(&obj_buffer[1], 92, 50);
}

void GameScene::unload()
{
    SpriteManager::instance().clear();
}