#include "Entdy.h"

Entdy::Entdy(float xin, float yin, float Size, SDL_Texture* tex) :
	Texture(tex), x(xin), y(yin), size(Size)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	
	SDL_QueryTexture(Texture, NULL, NULL, &currentFrame.w, &currentFrame.h);

}
