#ifndef ENGINE_H
#define ENGINE_H

#include "scene.h"

class Engine
{
  private:
    Scene *m_currentScene;

  public:
    void init();
    void update();
    void draw();

    void set_scene(Scene *newScene);
};

#endif // ENGINE_H