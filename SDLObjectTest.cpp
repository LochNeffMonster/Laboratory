/*
 * SDL.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: AndrewTNeff
 */

#include "SDL/SDL.h"
#include "Timer.h"
#include "Dot.h"
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 20;
//const int DOT_WIDTH = 20;
//const int DOT_HEIGHT = 20;


bool init();
void clean_up();
SDL_Texture *load_texture(SDL_Renderer* renderer, std::string filename);
void draw_texture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height);

int main(int argc, char* args[]) {
	bool quit = false;
	int frame = 0;
	bool capFPS = true;
	Timer fps;
	Dot myDot;

	// set up window
	// and exit if there's a problem
	if (!init()) {
		return 1;
	}

	//setup window
	SDL_Window *window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Texture *screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

	//apply_surface(renderer, background, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	if (window == NULL) {
		return 1;
	}

	//Create the textures
	SDL_Texture* dot = load_texture(renderer, "greenPixelMan.bmp");
	SDL_Texture* background = load_texture(renderer, "floorplan_Zoomed.bmp");

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
		draw_texture(renderer, background, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		//Then show the Dot
		draw_texture(renderer, dot, myDot.x, myDot.y, 50, 50);
		//Update Screen
		SDL_RenderPresent(renderer);

		//Cap the frame rate
		if(fps.get_ticks() < 1000 / FRAMES_PER_SECOND){
			SDL_Delay( (1000/FRAMES_PER_SECOND) - fps.get_ticks() );
		}
	}

	//Free the loaded image
	SDL_DestroyTexture(dot);
	SDL_DestroyTexture(background);
	SDL_DestroyRenderer(renderer);
	clean_up();

	return 0;
}

bool init() {
	//Start SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}
	return true;
}

void clean_up() {
	//Quit SDL
	SDL_Quit();
}

SDL_Texture *load_texture(SDL_Renderer* renderer, std::string filename) {
	//Load image into a Surface first, then load it into a Texture
	SDL_Surface* loadedImage = SDL_LoadBMP(filename.c_str());
	if (loadedImage == NULL){
		return NULL;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
	SDL_FreeSurface(loadedImage);
	return texture;
}

void draw_texture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height) {
	//Make a temp rectangle to hold the offsets
	SDL_Rect offset;
	//Give the offsets to the rectangle
	offset.x = x;
	offset.y = y;
	offset.w = width;
	offset.h = height;
	//Blit the surface
	SDL_RenderCopy(renderer, texture, NULL, &offset);
}

