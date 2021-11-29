#ifndef ENGINE_H
#define ENGINE_H

#include "game_scene.h"
#include "scene.h"

enum class SceneType
{
    GameScene,
};

class Engine
{
private:
    Scene *m_currentScene = nullptr;

public:
    void init();
    void update();
    void draw();

    void set_scene(Scene *newScene);
};

#endif // ENGINE_H