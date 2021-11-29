#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include <tonc.h>

enum class MemoryStatus : u8
{
    Unused,
    Used,
    Continue
};

class SpriteManager
{
  private:
    static const int MEMORY_BLOCKS = 1024;
    MemoryStatus m_memoryStatus[MEMORY_BLOCKS];
    SpriteManager()
    {
    }

  public:
    static SpriteManager &instance()
    {
        static SpriteManager INSTANCE;
        return INSTANCE;
    }

    void *allocate(size_t size, int &id);
    void deallocate(void *spriteData);
    void clear();
};

#endif // SPRITE_MANAGER_H