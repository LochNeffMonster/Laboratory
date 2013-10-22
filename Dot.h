/*
 * Dot.h
 *
 *  Created on: Oct 21, 2013
 *      Author: AndrewTNeff
 */

#ifndef DOT_H_
#define DOT_H_

#include "SDL/SDL.h"
const int DOT_WIDTH = 20;
const int DOT_HEIGHT = 20;
//const int SCREEN_WIDTH = 762;
//const int SCREEN_HEIGHT = 441;

class Dot
{
	//private:
	public:
	//the offsets of the dot
	int x,y;
	//velocity of the dot
	int xVel, yVel;

	//public:
	Dot();
	//Handles key presses
	void handle_input(SDL_Event event);
	//Move the dot
	void move();
	//Show on the screen
	void show();
};


#endif /* DOT_H_ */
