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
Dot::Dot(int _x, int _y){
	x = _x;
	y = _y;
	xVel = 0;
	yVel = 0;
}
//Handles key presses
void Dot::update() {
	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	xVel *= DOT_DAMP;
	yVel *= DOT_DAMP;

	//If a key was pressed
	if (keystates[SDL_Scancode::SDL_SCANCODE_W]) {
		yVel -= DOT_ACCEL;
	}
	if (keystates[SDL_Scancode::SDL_SCANCODE_S]) {
		yVel += DOT_ACCEL;
	}
	if (keystates[SDL_Scancode::SDL_SCANCODE_A]) {
		xVel -= DOT_ACCEL;
	}
	if (keystates[SDL_Scancode::SDL_SCANCODE_D]) {
		xVel += DOT_ACCEL;
	}

	//Move the dot left or right
	x += xVel;

	//If the dot went too far left or right
	if (x < 0){
		x = 0;
		xVel = -xVel;
	}
	else if (x + DOT_WIDTH > 640){
		x = 640 - DOT_WIDTH;
		xVel = -xVel;
	}

	//Move the dot up or down
	y += yVel;

	//If the dot went too far up or down
	if (y < 0){
		y = 0;
		yVel = -yVel;
	}
	else if (y + DOT_HEIGHT > 480){
		y = 480 - DOT_HEIGHT;
		yVel = -yVel;
	}
}
//Show on the screen
void Dot::show()
{
    //Show the dot
   // apply_surface( x, y, dot, screen );
}

