#include "RenderWindow.h"
#include "SDL_image.h"

RenderWindow::RenderWindow(const char* title, int width, int hight)
	:Window(NULL), Renderer(NULL)
{

	Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, hight, SDL_WINDOW_SHOWN);


	checkSDL.CheckifWindoInit(Window);

	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::LoadTexture(std::string Imagepath)
{

	SDL_Texture* Texture = IMG_LoadTexture(Renderer, (ImageFileOrgin + Imagepath).c_str());
	if (checkSDL.CheckifTextLoad(Texture)) {  return nullptr; }

	return Texture;
}

void RenderWindow::SetImageOrgin(std::string ImageOrgin)
{
	ImageFileOrgin = ImageOrgin;
}

Entdy* RenderWindow::CreateEntdy(float x, float y, float Size, SDL_Texture* tex)
{
	Entdy* entdyPtr = new Entdy(x, y, Size * SizeMod, tex);
	entdys.push_back(entdyPtr);

	int lastIndex = entdys.size() - 1;
	entdys[lastIndex]->ArrayNum = lastIndex;

	return entdys[lastIndex];
}

void RenderWindow::renderOne(Entdy* entdy)
{
	//               x                     y                     length                hight  
	SDL_Rect scr = {
		entdy->currentFrame.x, entdy->currentFrame.y, entdy->currentFrame.w, entdy->currentFrame.h
	}; // what pixles in image

	//               x                     y                     length                hight  
	SDL_Rect dst = {
		entdy->x, entdy->y, entdy->currentFrame.w * entdy->size, entdy->currentFrame.h * entdy->size
	}; // place and size

	std::cout << entdy->x << std::endl;

	SDL_RenderCopy(Renderer, entdy->Texture, &scr, &dst);
}

void RenderWindow::Destroy(Entdy entdy)
{

	entdys.erase(entdys.begin() + entdy.ArrayNum);

}


void RenderWindow::Clear()
{
	SDL_RenderClear(Renderer);
}

void RenderWindow::renderAll()
{

	for (int i = 0; i < entdys.size(); i++) {
		renderOne(entdys[i]);
	}
	
}

void RenderWindow::Display()
{
	SDL_RenderPresent(Renderer);
}

void RenderWindow::CleanUp()
{

	SDL_DestroyWindow(Window);

}

void RenderWindow::SetSizeMod(float SizeModIn)
{

	SizeMod = SizeModIn;

}

float RenderWindow::GetSizeMod()
{
	return SizeMod;
}
