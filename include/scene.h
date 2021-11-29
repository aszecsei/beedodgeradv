#ifndef SCENE_H
#define SCENE_H

class Scene
{
  public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void unload() = 0;

    virtual ~Scene()
    {
    }
};

#endif // SCENE_H