/*
* Dot.cpp
*
*  Created on: Oct 21, 2013
*      Author: AndrewTNeff
*/
#include "Dot2.h"

Dot2::Dot2() {
	x = 0;
	y = 0;
	xVel = 0;
	yVel = 0;
}
Dot2::Dot2(int _x, int _y){
	x = _x;
	y = _y;
	xVel = 0;
	yVel = 0;
}
//Handles key presses
void Dot2::update() {
	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	xVel *= DOT2_DAMP;
	yVel *= DOT2_DAMP;

	//If a key was pressed
	if (keystates[SDL_Scancode::SDL_SCANCODE_UP]) {
		yVel += DOT2_ACCEL;
	}
	if (keystates[SDL_Scancode::SDL_SCANCODE_DOWN]) {
		yVel -= DOT2_ACCEL;
	}
	if (keystates[SDL_Scancode::SDL_SCANCODE_LEFT]) {
		xVel += DOT2_ACCEL;
	}
	if (keystates[SDL_Scancode::SDL_SCANCODE_RIGHT]) {
		xVel -= DOT2_ACCEL;
	}

	//Move the dot left or right
	x -= xVel;

	//If the dot went too far left or right
	if (x < 0){
		x = 0;
		xVel = -xVel;
	}
	else if (x + DOT2_WIDTH > 640){
		x = 640 - DOT2_WIDTH;
		xVel = -xVel;
	}

	//Move the dot up or down
	y -= yVel;

	//If the dot went too far up or down
	if (y < 0){
		y = 0;
		yVel = -yVel;
	}
	else if (y + DOT2_HEIGHT > 480){
		y = 480 - DOT2_HEIGHT;
		yVel = -yVel;
	}
}
//Show on the screen
void Dot2::show()
{
	//Show the dot
	// apply_surface( x, y, dot, screen );
}

