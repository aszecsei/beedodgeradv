#ifndef SPRITE_H
#define SPRITE_H

#include <tonc.h>

class SpriteData
{
private:
    const u32 *m_tileData = nullptr;
    size_t m_tileDataSize = 0;

    const u16 *m_palette = nullptr;
    size_t m_paletteSize = 0;

    int m_tileId = -1;
    void *m_tileMemory = nullptr;

public:
    SpriteData(const u32 tileData[], size_t tileDataSize, const u16 palette[], size_t paletteSize)
        : m_tileData(tileData)
        , m_tileDataSize(tileDataSize)
        , m_palette(palette)
        , m_paletteSize(paletteSize)
    {
    }

    SpriteData()
    {
    }

    void load();
    void unload();

    inline const bool loaded()
    {
        return m_tileId >= 0;
    }

    inline const int tileId()
    {
        return m_tileId;
    }
};

#endif // SPRITE_H