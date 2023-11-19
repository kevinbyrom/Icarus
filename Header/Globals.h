#ifndef __Globals_H
#define __Globals_H


#include "GGame.h"
#include "GBitmap.h"
#include "GSprite.h"


#define NUM_ICARUS_SPRX		14	
#define NUM_ICARUS_SPRY		2
#define NUM_ICARUS_SPRITES	(NUM_ICARUS_SPRX * NUM_ICARUS_SPRY)


extern GGame Game;

extern GBITMAP SurfaceBmp,
			   BufferBmp;

extern GSPRITE IcarusSpr[NUM_ICARUS_SPRITES];


#endif