#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "SprPlayer.h"

class Player : public Entity
{
public:
    Player()
    {
        sprite = Sprite(
            (u32 *)SprPlayerTiles,
            SprPlayerTilesLen,
            (u16 *)SprPlayerPal,
            SprPlayerPalLen);

        pt_set(&position, SCREEN_WIDTH / 2 -)
    }
};

#endif // PLAYER_H