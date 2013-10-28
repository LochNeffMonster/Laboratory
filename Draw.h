#ifndef DRAW_H_
#define DRAW_H_

#include <SDL.h>
#include <string>
#include <vector>
#include "Dot.h"
#include "Dot2.h"
#include "PlayerWindow.h"
#include "Entity.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 60;

class Object{
public:
	double _x, _y, _width, _height, _xOffset, _yOffset;
	SDL_Texture* _texture;
	Object();
	Object(int x, int y, int width, int height, SDL_Texture* texture) : _x(x), _y(y), _width(width), _height(height), _texture(texture){}

};

class Draw
{
private:
	SDL_Window *window1;
	SDL_Window *window2;
	SDL_Renderer *RendPlayer1;
	SDL_Renderer *RendPlayer2;
	// vectors hold all objects to be rendered for each player
	std::vector<Object> cameraObjects1;
	std::vector<Object> cameraObjects2;
	//held separately to not be updated by camera
	Object playerObject1;
	Object playerObject2;
	// Objects merely serve as coodinates for camera updates
	Object camera;
	Object camera2;

public:
	Draw();
	SDL_Texture *loadTexture(SDL_Renderer* renderer, std::string filename);
	//Draws a texture to a renderer
	void drawTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height);
	SDL_Window* getWindow1();
	SDL_Window* getWindow2();
	//These functions add objects to a players renderer
	void addObjectToPlayer1(std::string fileName, int x, int y, int width, int height);
	void addObjectToPlayer2(std::string fileName, int x, int y, int width, int height);
	// This just calls the drawPlayerXObject functions
	void drawObjects();
	//These functions draw all objects in the object list in the order they are input
	//Will be undated with draw layer indices when the Real object class is made
	void drawPlayer1Objects();
	void drawPlayer2Objects();
//	void drawEntity(Entity entity);
	//These functions set a player avatar to draw as well as tell the each screens camera to follow
	void setPlayer1(std::string fileName, int x, int y, int width, int height);
	void setPlayer2(std::string fileName, int x, int y, int width, int height);
	//Updates the cameras with the new position of the player avatars
	//Will be updated to Player class when it's made
	void updateCamera(Dot dot);
	void updateCamera2(Dot2 dot);
	//Destroys renderers
	void cleanUp();

};



#endif /* DRAW_H_ */