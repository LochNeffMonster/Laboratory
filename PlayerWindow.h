#ifndef DRAW_H_
#define DRAW_H_

#include <SDL.h>
#include <string>
#include "Draw.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 60;

class PlayerWindow{
public:
	//Intializes internals
	PlayerWindow();
	//Creates window
	bool init();
	//Handles window events
	void handleEvent(SDL_Event& e);
	//Focuses on window
	void focus();
	//Shows windows contents
	void render();
	//Deallocates internals
	void free();
	//Window dimensions
	int getWidth();
	int getHeight();
	//Window focii
	bool hasMouseFocus();
	bool hasKeyboardFocus();
	bool isShown();

private:
	//Window data
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	int mWindowID;
	//Window dimensions
	int mWidth;
	int mHeight;
	//Window focus
	bool mMouseFocus;
	bool mKeyboardFocus;
	bool mFullScreen;
	bool mShown;
};

#endif /* DRAW_H_ */