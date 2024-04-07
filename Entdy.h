#pragma once

#include "SDL.h"
#include "SDL_image.h"

class Entdy
{

public:
	Entdy(float xin, float yin, float Size, SDL_Texture* tex);

	float x, y, size;
	SDL_Rect currentFrame;
	SDL_Texture* Texture;

	int ArrayNum;

};

