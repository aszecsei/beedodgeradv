#ifndef SPRITE_H
#define SPRITE_H

#include <tonc.h>

class Sprite
{
public:
    u32 *TileData;
    size_t TileDataSize;

    u16 *Palette;
    size_t PaletteSize;

    Sprite(u32 *tileData, size_t tileDataSize, u16 *palette, size_t paletteSize)
        : TileData(tileData), TileDataSize(tileDataSize), Palette(palette), PaletteSize(paletteSize)
    {
    }

    Sprite()
        : TileData(nullptr), TileDataSize(0), Palette(nullptr), PaletteSize(0)
    {
    }
};

#endif // SPRITE_H