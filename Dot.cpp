/*
 * Dot.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: AndrewTNeff
 */
#include "Dot.h"

Dot::Dot() {
	x = 0;
	y = 0;
	xVel = 0;
	yVel = 0;
}
//Handles key presses
void Dot::handle_input(SDL_Event event) {
	//If a key was pressed
	if (event.type == SDL_KEYDOWN) {
		//Adjust the velocity
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			yVel -= DOT_HEIGHT / 2;
			break;
		case SDLK_DOWN:
			yVel += DOT_HEIGHT / 2;
			break;
		case SDLK_LEFT:
			xVel -= DOT_WIDTH / 2;
			break;
		case SDLK_RIGHT:
			xVel += DOT_WIDTH / 2;
			break;
		}
	} //If a key was released
	else if (event.type == SDL_KEYUP) {
		//Adjust the velocity
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			yVel += DOT_HEIGHT / 2;
			break;
		case SDLK_DOWN:
			yVel -= DOT_HEIGHT / 2;
			break;
		case SDLK_LEFT:
			xVel += DOT_WIDTH / 2;
			break;
		case SDLK_RIGHT:
			xVel -= DOT_WIDTH / 2;
			break;
		}
	}
}
//Move the dot
void Dot::move() {
	//Move the dot left or right
	x += xVel;

	//If the dot went too far to the left or right
	if ((x < 0) || (x + DOT_WIDTH > 762)) {
		//move back
		x -= xVel;
	}

	//Move the dot up or down
	y += yVel;

	//If the dot went too far up or down
	if ((y < 0) || (y + DOT_HEIGHT > 441)) {
		//move back
		y -= yVel;
	}
}
//Show on the screen
void Dot::show()
{
    //Show the dot
   // apply_surface( x, y, dot, screen );
}

