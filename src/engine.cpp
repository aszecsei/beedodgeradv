#include "engine.h"
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
    if (m_currentScene != nullptr)
    {
        delete m_currentScene;
    }
    m_currentScene = newScene;
    m_currentScene->init();
}