#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "iostream"

class CheckSDL
{
public:

	SDL_Event event;

	CheckSDL();

	bool CheckIfGameRunning();

	bool CheckifWindoInit(SDL_Window* window);
	bool CheckifTextLoad(SDL_Texture* text);
	bool CheckifSurfaceLoad(SDL_Surface* surface);
	bool CheckIfImageCabilityInit();
	bool CheckIfVidioInit();

};

