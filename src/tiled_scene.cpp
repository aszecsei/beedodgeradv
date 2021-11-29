#include "tiled_scene.h"

void TiledScene::init()
{
    // DCNT_MODE0 : tiled video mode, so we're using sprites instead of drawing
    // directly to the screen buffer DCNT_BG0 : enables the 0th background
    // DCNT_OBJ : tells our program to use sprites
    // DCNT_OBJ_1D : our sprites are stored in a 1-dimensional array; Grit handles
    // this for us.
    REG_DISPCNT = DCNT_MODE0 | DCNT_BG0 | DCNT_OBJ | DCNT_OBJ_1D;

    // Initialize OBJ_ATTRS with safe values.
    oam_init(obj_buffer, OBJ_CNT);
}

void TiledScene::update()
{
}

void TiledScene::draw()
{
    oam_copy(oam_mem, obj_buffer, OBJ_CNT);
}

void TiledScene::unload()
{
}