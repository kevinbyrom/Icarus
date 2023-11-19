#include <windows.h>
#include "DirectX.h"
#include "GGame.h"
#include "Globals.h"




int GGame::Init()
	{
	if (!InitDX())
		return 0;

	SurfaceBmp.AttachToDDSurface(lpBack);
	BufferBmp.Create(320, 240, 8);
	
	LoadIcarusSpr();

	return 1;
	}





void GGame::ShutDown()
	{
	BufferBmp.Destroy();
		
	ShutDownDX();
	}





void GGame::DoLogic()
	{
	BufferBmp.Fill8(0);
	
	IcarusSpr[2].Draw(&BufferBmp, 0, 0);

	SurfaceBmp.LockDDSurface();
	SurfaceBmp.Blit(&BufferBmp, 0, 0, 320, 240, 0, 0);
	SurfaceBmp.UnlockDDSurface();

	lpPrimary->Flip(NULL, 0);
	}











void GGame::LoadIcarusSpr()
	{
	GBITMAP IcarusBmp;
	int x, y;
	PALETTEENTRY pal[256];



	// Load the icarus bitmap //

	IcarusBmp.LoadBMP("ICARUS1.BMP");


	// Grab the icarus sprites //

	for (y = 0; y < NUM_ICARUS_SPRY; y++)
		for (x = 0; x < NUM_ICARUS_SPRX; x++)
			{
			IcarusSpr[x + (y * NUM_ICARUS_SPRX)].Grab(&IcarusBmp, (x * 16) + (x + 1), (y * 24) + (y + 1), 16, 24, 254);
			}


	// Set the palette //

	memcpy(pal, IcarusBmp.GetPalette(), sizeof(PALETTEENTRY) * 256);
	lpPalette->SetEntries(0, 0, 255, pal);


	// Unload the tile bitmap  //

	IcarusBmp.Destroy();
	}

