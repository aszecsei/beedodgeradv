#include <string.h>
#include <tonc.h>

#include "engine.h"
#include "game_scene.h"

int main()
{
    Engine game;

    game.init();
    game.set_scene(new GameScene());

    while (1)
    {
        VBlankIntrWait();
        game.update();
        game.draw();
    }

    return 0;
}
