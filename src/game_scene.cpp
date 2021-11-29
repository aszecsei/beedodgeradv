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

    // Set up BG0 for an 8bb 30x20t map, using charblock 0 and screenblock 30
    REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;

    // SPRITE DATA

    m_playerSpriteData = SpriteData(SprPlayerTiles, SprPlayerTilesLen, SprPlayerPal, SprPlayerPalLen);
    m_playerSpriteData.load();
    m_beeSpriteData = SpriteData(SprBeeTiles, SprBeeTilesLen, SprBeePal, SprBeePalLen);
    m_beeSpriteData.load();

    // Set up sprite entities
    m_player.init(&obj_buffer[0], &m_playerSpriteData, POINT{SCREEN_WIDTH / 2 - 8, SCREEN_HEIGHT / 2 - 8});

    for (size_t i = 0; i < BEE_CNT; i++)
    {
        m_bees[i].init(&obj_buffer[1 + i], &m_beeSpriteData, POINT{60 + (int)i * 20, 30});
    }
}

void GameScene::update()
{
    TiledScene::update();

    m_player.update();
    for (size_t i = 0; i < BEE_CNT; i++)
    {
        m_bees[i].update();
    }
}

void GameScene::draw()
{
    TiledScene::draw();

    m_player.draw();
    for (size_t i = 0; i < BEE_CNT; i++)
    {
        m_bees[i].draw();
    }
}

void GameScene::unload()
{
    TiledScene::unload();

    m_beeSpriteData.unload();
    m_playerSpriteData.unload();
}