/*
 mgba.h
 Copyright (c) 2016 Jeffrey Pfau
 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
  1. Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation and/or
     other materials provided with the distribution.
 THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <tonc.h>

#include "mgba.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define REG_DEBUG_ENABLE (vu16 *)0x4FFF780
#define REG_DEBUG_FLAGS (vu16 *)0x4FFF700
#define REG_DEBUG_STRING (char *)0x4FFF600

namespace mgba
{
ssize_t mgba_stdout_write(struct _reent *r __attribute__((unused)), int fd __attribute__((unused)), const char *ptr,
                          size_t len)
{
    if (len > 0x100)
    {
        len = 0x100;
    }
    strncpy(REG_DEBUG_STRING, ptr, len);
    *REG_DEBUG_FLAGS = (u16)Level::Info | 0x100;
    return len;
}

ssize_t mgba_stderr_write(struct _reent *r __attribute__((unused)), int fd __attribute__((unused)), const char *ptr,
                          size_t len)
{
    if (len > 0x100)
    {
        len = 0x100;
    }
    strncpy(REG_DEBUG_STRING, ptr, len);
    *REG_DEBUG_FLAGS = (u16)Level::Error | 0x100;
    return len;
}

void printf(const char *ptr, ...)
{
    va_list args;
    va_start(args, ptr);
    vsnprintf(REG_DEBUG_STRING, 0x100, ptr, args);
    va_end(args);
    *REG_DEBUG_FLAGS = (u16)Level::Info | 0x100;
}

void printf(Level level, const char *ptr, ...)
{
    va_list args;
    va_start(args, ptr);
    vsnprintf(REG_DEBUG_STRING, 0x100, ptr, args);
    va_end(args);
    *REG_DEBUG_FLAGS = (u16)level | 0x100;
}

bool open()
{
    *REG_DEBUG_ENABLE = 0xC0DE;
    return *REG_DEBUG_ENABLE == 0x1DEA;
}

void close()
{
    *REG_DEBUG_ENABLE = 0;
}
} // namespace mgba
