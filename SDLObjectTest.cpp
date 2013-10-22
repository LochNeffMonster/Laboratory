/*
 * SDL.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: AndrewTNeff
 */

#include "SDL/SDL.h"
//#include "SDL/SDL_ttf.h"
#include "Timer.h"
#include "Dot.h"
#include <string>

const int SCREEN_WIDTH = 762;
const int SCREEN_HEIGHT = 441;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 20;
//const int DOT_WIDTH = 20;
//const int DOT_HEIGHT = 20;


bool init();
void clean_up();
SDL_Surface *load_image(std::string filename);
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination);

int main(int argc, char* args[]) {
	bool quit = false;
	int frame = 0;
	bool capFPS = true;
	Timer fps;
	// the images
	SDL_Surface *screen = NULL;
	SDL_Surface *dot = NULL;
	SDL_Surface *background = NULL;
	Dot myDot;

	// set up window
	// and exit if there's a problem
	if (!init()) {
		return 1;
	}
	//setup screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
			SDL_SWSURFACE);
	if (screen == NULL) {
		return 1;
	}
	//load the images
	dot = SDL_LoadBMP("greenPixelMan.bmp");
	background = load_image("floorplan_Zoomed.bmp");

	//Apply the background to the screen
	apply_surface(0, 0, background, screen);
	//apply the message to the screen
	//apply_surface( 50, 50, message, screen);

	//Event code
	SDL_Event event;



	//while the user hasn't quit
	while (quit == false) {
		fps.start();
		//while there's an event to handle
		while (SDL_PollEvent(&event)) {
			//Handle events for the dot
			myDot.handle_input(event);
			//If the user has Xed out the window
			if (event.type == SDL_QUIT) {
				//Quit the program
				quit = true;
			}
		}
		//Move the dot
		myDot.move();
	// Draw function stuff
		//Fill in the background
		apply_surface(0, 0, background, screen);
		//Then show the Dot
		//myDot.show();
		apply_surface( myDot.x, myDot.y, dot, screen );
		//Update Screen
		if (SDL_Flip(screen) == -1) {
			return 1;
		}
		//Cap the frame rate
		if(fps.get_ticks() < 1000 / FRAMES_PER_SECOND){
			SDL_Delay( (1000/FRAMES_PER_SECOND) - fps.get_ticks() );
		}

	}

	//Free the loaded image
	SDL_FreeSurface(dot);
	SDL_FreeSurface(background);
	clean_up();

	return 0;
}
bool init() {

	//Start SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return 1;
	}

	//set the window caption
	SDL_WM_SetCaption("SDL Object Test", NULL);

	return true;
}
void clean_up() {
	//Quit SDL
	SDL_Quit();
}

SDL_Surface *load_image(std::string filename) {
	//temporary storage for the image that's loaded
	SDL_Surface* loadedImage = NULL;
	//the optimized image that will be used
	SDL_Surface* optimizedImage = NULL;

	//load using SDL image
	loadedImage = SDL_LoadBMP( filename.c_str() );

	//if nothing went wrong in loading the image
	if (loadedImage != NULL) {
		//create and optimized image
		optimizedImage = SDL_DisplayFormat(loadedImage);
		//free the old image
		SDL_FreeSurface(loadedImage);
	}
	// return the optimized image
	return optimizedImage;
}
void apply_surface(int x, int y, SDL_Surface* source,
		SDL_Surface* destination) {
	//Make a temp rectangle to hold the offsets
	SDL_Rect offset;
	//Give the offsets to the rectangle
	offset.x = x;
	offset.y = y;
	//Blit the surface
	SDL_BlitSurface(source, NULL, destination, &offset);
}

