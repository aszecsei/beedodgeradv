#ifndef SPRITE_H
#define SPRITE_H

#include <tonc.h>

class Sprite
{
public:
    u32 *tile_data;
    size_t tile_data_size;

    u16 *Palette;
    size_t palette_size;

    Sprite(u32 *tileData, size_t tileDataSize, u16 *palette, size_t paletteSize)
        : tile_data(tileData)
        , tile_data_size(tileDataSize)
        , Palette(palette)
        , palette_size(paletteSize)
    {
    }

    Sprite()
        : tile_data(nullptr)
        , tile_data_size(0)
        , Palette(nullptr)
        , palette_size(0)
    {
    }
};

#endif // SPRITE_H