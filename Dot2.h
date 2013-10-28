/*
* Dot.h
*
*  Created on: Oct 21, 2013
*      Author: AndrewTNeff
*/

#ifndef DOT2_H_
#define DOT2_H_

#include <SDL.h>

const int DOT2_WIDTH = 20;
const int DOT2_HEIGHT = 20;
const double DOT2_ACCEL = 0.1;
const double DOT2_DAMP = 0.01;

class Dot2
{
	//private:
public:
	//the offsets of the dot
	double x, y;
	//velocity of the dot
	double xVel, yVel;

	//public:
	Dot2();
	Dot2(int _x, int _y);
	//Updates the dots state
	void update();
	//Show on the screen
	void show();
};


#endif /* DOT2_H_ */
