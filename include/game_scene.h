#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "tiled_scene.h"

class GameScene : public TiledScene
{
private:
    int m_x;
    int m_y;
    int m_vx;
    int m_vy;

    void bounce_off_screen_edges();

public:
    GameScene()
    {
        m_x = SCREEN_WIDTH / 2 - 8;
        m_y = SCREEN_HEIGHT / 2 - 8;
        m_vx = 1;
        m_vy = 1;
    }

    void init() override;
    void update() override;
    void draw() override;
};

#endif // GAME_SCENE_H