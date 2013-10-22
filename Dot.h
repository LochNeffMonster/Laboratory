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
const double DOT_ACCEL = 1;
const double DOT_DAMP = 0.9;

class Dot
{
	//private:
	public:
	//the offsets of the dot
	double x,y;
	//velocity of the dot
	double xVel, yVel;

	//public:
	Dot();
	//Updates the dots state
	void update();
	//Show on the screen
	void show();
};


#endif /* DOT_H_ */
