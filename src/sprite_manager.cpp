#include "sprite_manager.h"

#include <memory.h>
#include <tonc.h>

#define TILE_BASE (u8 *)&tile_mem[4]

void *SpriteManager::allocate(size_t size, int &id)
{
    u8 *base = TILE_BASE;

    size_t found = 0;
    for (size_t i = 0; i < MEMORY_BLOCKS; i++)
    {
        if (m_memoryStatus[i] == MemoryStatus::Unused)
        {
            found++;
        }
        else
        {
            found = 0;
        }
        if (found == size)
        {
            size_t start = i + 1 - size;
            m_memoryStatus[start] = MemoryStatus::Used;
            for (size_t j = start + 1; j < start + size; j++)
            {
                m_memoryStatus[j] = MemoryStatus::Continue;
            }

            id = start / sizeof(TILE);

            return base + start;
        }
    }

    return nullptr;
}

void SpriteManager::deallocate(void *spriteData)
{
    u8 *base = TILE_BASE;
    u8 *data = (u8 *)spriteData;
    size_t diff = data - base;

    size_t end = diff + 1;
    while (m_memoryStatus[end] == MemoryStatus::Continue)
    {
        end++;
    }

    for (size_t i = diff; i < end; i++)
    {
        m_memoryStatus[i] = MemoryStatus::Unused;
    }
}

void SpriteManager::clear()
{
    memset(m_memoryStatus, (int)MemoryStatus::Unused, MEMORY_BLOCKS);
}