#ifndef TILED_SCENE_H
#define TILED_SCENE_H

#include <tonc.h>

#include "scene.h"

class TiledScene : public Scene
{
public:
    inline static const int OBJ_CNT = 128;
    OBJ_ATTR obj_buffer[OBJ_CNT];
    OBJ_AFFINE *const obj_aff_buffer;

    TiledScene()
        : obj_aff_buffer((OBJ_AFFINE *)obj_buffer)
    {
    }

    void init() override;
    void update() override;
    void draw() override;
};

#endif // TILED_SCENE_H