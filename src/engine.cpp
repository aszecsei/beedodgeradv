#include "engine.h"
#include "mgba.h"

#include <tonc.h>

void Engine::init()
{
    irq_init(nullptr);
    irq_enable(II_VBLANK);
}

void Engine::update()
{
    key_poll();
    m_currentScene->update();
}

void Engine::draw()
{
    m_currentScene->draw();
}

void Engine::set_scene(Scene *newScene)
{
    mgba::printf("Transitioning to new scene...");
    if (m_currentScene != nullptr)
    {
        mgba::printf("Deleting old scene...");
        delete m_currentScene;
    }
    m_currentScene = newScene;
    m_currentScene->init();
}