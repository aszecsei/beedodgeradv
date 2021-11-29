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

    int m_bx;
    int m_by;
    int m_bvx;
    int m_bvy;
    int m_brot;

    void clamp_to_screen(int &x, int &y, bool &hitX, bool &hitY);

public:
    GameScene()
        : m_x(SCREEN_WIDTH / 2 - 8)
        , m_y(SCREEN_HEIGHT / 2 - 8)
        , m_vx(1)
        , m_vy(1)
        , m_bx(30)
        , m_by(50)
        , m_bvx(1)
        , m_bvy(1)
        , m_brot(90)
    {
    }

    void init() override;
    void update() override;
    void draw() override;
    void unload() override;
};

#endif // GAME_SCENE_H