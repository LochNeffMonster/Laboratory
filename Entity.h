#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "SDL/SDL.h"

class Entity{
public:
	double x, y;
	SDL_Texture* texture;
	int imageCenterX, imageCenterY;

	virtual void update();
	virtual void draw();
};

#endif