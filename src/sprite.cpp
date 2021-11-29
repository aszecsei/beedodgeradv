#include "sprite.h"
#include "sprite_manager.h"

void SpriteData::load()
{
    // Load Palette
    memcpy16(pal_obj_mem, m_palette, m_paletteSize / 2);
    // Load tiles
    m_tileMemory = SpriteManager::instance().allocate(m_tileDataSize, m_tileId);
    memcpy32(m_tileMemory, m_tileData, m_tileDataSize / 4);
}

void SpriteData::unload()
{
    SpriteManager::instance().deallocate(m_tileMemory);
    m_tileMemory = nullptr;
    m_tileId = -1;
}