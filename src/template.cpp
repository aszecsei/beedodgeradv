#include <tonc.h>
#include <string.h>

#include "player.h"
#include "game.h"

#define OBJ_CNT 128
OBJ_ATTR obj_buffer[OBJ_CNT];
OBJ_AFFINE *const obj_aff_buffer = (OBJ_AFFINE *)obj_buffer;

const int X_MIN = -4;
const int X_MAX = 210 - 12;

const int Y_MIN = -2;
const int Y_MAX = 160 - 14;

int x = 96;
int y = 32;
int vx = 1;
int vy = 1;

void bounce_off_screen_edges()
{
	if (x <= X_MIN)
	{
		x = X_MIN;
		vx *= -1;
	}
	if (x >= X_MAX)
	{
		x = X_MAX;
		vx *= -1;
	}
	if (y <= Y_MIN)
	{
		y = Y_MIN;
		vy *= -1;
	}
	if (y >= Y_MAX)
	{
		y = Y_MAX;
		vy *= -1;
	}
}

void update()
{
	x += vx;
	y += vy;

	bounce_off_screen_edges();
}

void draw()
{
	obj_set_pos(obj_buffer, x, y);
	oam_copy(oam_mem, obj_buffer, OBJ_CNT);
}

int main()
{
	// DCNT_MODE0 is a tiled video mode, so we're using sprites instead
	// of drawing directly to the screen buffer
	// DCNT_BG0 enables the 0th background
	// DCNT_OBJ is the flag that tells our program to use sprites
	// DCNT_OBJ_1D means that our sprites are stored in a 1-dimensional
	// array; Grit handles this for us.
	REG_DISPCNT = DCNT_MODE0 | DCNT_BG0 | DCNT_OBJ | DCNT_OBJ_1D;

	// Initialize OBJ_ATTRS with safe values.
	oam_init(obj_buffer, OBJ_CNT);

	// BACKGROUND DATA
	// Load Palette
	memcpy(pal_bg_mem, gamePal, gamePalLen);
	// Load tiles into CBB 0
	memcpy(&tile_mem[0][0], gameTiles, gameTilesLen);
	// Load map into SBB 30
	memcpy(&se_mem[30], gameMap, gameMapLen);

	// PLAYER DATA
	// Load Palette
	memcpy(pal_obj_mem, playerPal, playerPalLen);
	// Load tiles into CBB 4
	memcpy(&tile_mem[4], playerTiles, playerTilesLen);

	// Set up BG0 for an 8bb 30x20t map, using charblock 0 and screenblock 30
	REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;

	obj_set_attr(obj_buffer, ATTR0_SQUARE | ATTR0_8BPP, ATTR1_SIZE_16, 0 | 0);

	irq_init(nullptr);
	irq_enable(II_VBLANK);

	while (1)
	{
		// update();
		VBlankIntrWait();
		draw();
	}

	return 0;
}
