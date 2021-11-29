#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "sprite.h"
#include "tiled_scene.h"

#include "bee.h"
#include "player.h"

class GameScene : public TiledScene
{
private:
    SpriteData m_playerSpriteData;
    SpriteData m_beeSpriteData;

    Player m_player;

    static const size_t BEE_CNT = 4;
    Bee m_bees[BEE_CNT];

public:
    GameScene()
    {
    }

    void init() override;
    void update() override;
    void draw() override;
    void unload() override;
};

#endif // GAME_SCENE_H