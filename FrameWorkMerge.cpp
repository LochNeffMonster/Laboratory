/*
* SDL.cpp
*
*  Created on: Oct 21, 2013
*      Author: AndrewTNeff
*/

//#include "RakPeerInterface.h"
#include <SDL.h>
#include "Timer.h"
#include "Dot.h"
#include "Dot2.h"
#include "Draw.h"
#include "World.h"
#include "Entity.h"
#include "Player.h"
#include "Tilemap.h"
#include <string>

/*const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 60;
*/

bool init();

int main(int argc, char* args[]) {
	bool quit = false;
	int frame = 0;
	bool capFPS = true;
	Timer fps;
	Dot myDot = Dot(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	Dot2 myDot2 = Dot2(SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT / 2);
	Draw drawWindow;

	////// Merged framework variables
	World playerWorld1;
	World playerWorld2;




	// set up window
	// and exit if there's a problem
	if (!init()) {
		return 1;
	}

	//setup window
	drawWindow = Draw();

	//if ((drawWindow.getWindow1() == NULL) || (drawWindow.getWindow2() == NULL)){
	if (drawWindow.getWindow1() == NULL){
		return 1;
	}

	//Create the textures
	//Add textures to the draw cycle
	drawWindow.addObjectToPlayer1("floorplan_Zoomed.bmp", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	drawWindow.addObjectToPlayer2("floorplan_Zoomed.bmp", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	drawWindow.addObjectToPlayer1("floorplan_Zoomed.bmp", SCREEN_WIDTH, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	drawWindow.addObjectToPlayer2("floorplan_Zoomed.bmp", SCREEN_WIDTH, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	drawWindow.addObjectToPlayer1("floorplan_Zoomed.bmp", SCREEN_WIDTH/4+8, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT);
	drawWindow.addObjectToPlayer2("floorplan_Zoomed.bmp", SCREEN_WIDTH/4+8, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT);

	drawWindow.setPlayer1("greenPixelMan.bmp", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20, 20);
	drawWindow.setPlayer2("greenPixelMan.bmp", (SCREEN_WIDTH / 2) + 50, SCREEN_HEIGHT / 2, 20, 20);
	//drawWindow.addObjectToPlayer1();
	//drawWindow.addObjectToPlayer1("greenPixelMan.bmp", (SCREEN_WIDTH / 2) + 50, SCREEN_HEIGHT / 2, 20, 20);

	//drawWindow.addObjectToPlayer2();
	//drawWindow.addObjectToPlayer2("greenPixelMan.bmp", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20, 20);

	//Event code
	SDL_Event event;

	//while the user hasn't quit
	while (quit == false) {
		fps.start();
		//while there's an event to handle
		while (SDL_PollEvent(&event)) {
			//If the user has Xed out the window
			if (event.type == SDL_QUIT) {
				//Quit the program
				quit = true;
			}
		}
		//Move the dot
		myDot.update();
		myDot2.update();
		drawWindow.updateCamera(myDot);
		drawWindow.updateCamera2(myDot2);
		// Draw function stuff
		drawWindow.drawObjects();
		//drawWindow.drawPlayer1Objects();
		//drawWindow.drawPlayer2Objects();

		//Cap the frame rate
		if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND){
			SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());
		}
	}

	drawWindow.cleanUp();
	SDL_Quit();

	return 0;
}

bool init() {
	//Start SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}
	return true;
}