#include "CheckSDL.h"

CheckSDL::CheckSDL()
{

	SDL_Init(SDL_INIT_EVERYTHING);

	CheckIfVidioInit();
	CheckIfImageCabilityInit();

}

bool CheckSDL::CheckIfGameRunning()
{
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

bool CheckSDL::CheckifWindoInit(SDL_Window* window)
{
	if (window == NULL) {
		std::cout << "Window failed: " << SDL_GetError() << "\n";
		return true;
	}
	return false;
}

bool CheckSDL::CheckifTextLoad(SDL_Texture* text)
{

	if (text == NULL) {
		// Handle error, e.g., print an error message and return nullptr
		std::cout << "Failed to create texture: " << SDL_GetError();
		return true;
	}

	return false;
}

bool CheckSDL::CheckifSurfaceLoad(SDL_Surface* surface)
{
	if (surface == NULL) {
		// Handle error, e.g., print an error message and return nullptr
		std::cout << "Failed to load image: " << SDL_GetError();
		return true;
	}

	return false;
}

bool CheckSDL::CheckIfImageCabilityInit()
{

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		std::cerr << "Failed to initialize SDL_image: " << IMG_GetError() << std::endl;
		// ... (additional cleanup if needed)
		return true;
	}

	return false;
}

bool CheckSDL::CheckIfVidioInit()
{

	if (SDL_Init(SDL_INIT_VIDEO) > 0) {

		std::cout << "failed to init video: " << SDL_GetError() << "\n";

		return true;
	}


	return false;
}
