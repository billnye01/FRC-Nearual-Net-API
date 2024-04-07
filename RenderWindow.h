#pragma once

#include "SDL.h" //lib
#include "CheckSDL.h"
#include <iostream>
#include <vector>
#include <string>

#include "Entdy.h"

class RenderWindow
{

public:

	RenderWindow(const char* title, int width, int hight);
	
	SDL_Texture* LoadTexture(std::string Imagepath);

	void SetImageOrgin(std::string ImageOrgin);

	Entdy* CreateEntdy(float x, float y, float Size, SDL_Texture* tex);

	void renderOne(Entdy* entdy);
	void Destroy(Entdy entdy);

	void Clear();
	void renderAll();
	void Display();

	void CleanUp();

	void SetSizeMod(float SizeModIn);
	float GetSizeMod();

private:

	bool Spacefree_B;
	int SpaceFree_I;

	float SizeMod = 1;

	std::vector<Entdy*> entdys;

	std::string ImageFileOrgin;

	SDL_Renderer* Renderer;
	SDL_Window* Window;

	CheckSDL checkSDL;
};

