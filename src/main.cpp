#include <tonc.h>

#include "engine.h"
#include "game_scene.h"
#include "mgba.h"

int main()
{
    mgba::open();
    mgba::printf("Game start!");

    Engine game;

    game.init();
    mgba::printf("Game initialized");
    game.set_scene(new GameScene());

    while (1)
    {
        VBlankIntrWait();
        game.update();
        game.draw();
    }

    game.set_scene(nullptr);

    mgba::close();

    return 0;
}
