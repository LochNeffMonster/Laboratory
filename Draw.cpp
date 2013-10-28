
#include "Draw.h"
#include "PlayerWindow.h"
#include "Entity.h"

Object::Object(){
	_x = 0;
	_y = 0;
	_xOffset = 0;
	_yOffset = 0;
	_width = 0;
	_height = 0;
	_texture = NULL;
}

Draw::Draw(){
	// Initialize Variables
	cameraObjects1.resize(1);
	cameraObjects2.resize(1);
	playerObject1 = Object(0, 0, 0, 0, NULL);
	playerObject2 = Object(0, 0, 0, 0, NULL);
	camera = Object(0,0,0,0,NULL);
	camera2 = Object(0,0,0,0,NULL);
	//setup windows
	SDL_Window *window1 = SDL_CreateWindow("Prototype Player 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	SDL_Window *window2 = SDL_CreateWindow("Prototype Player 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	RendPlayer1 = SDL_CreateRenderer(window1, -1, 0);
	RendPlayer2 = SDL_CreateRenderer(window2, -1, 0);
	//PlayerWindow playerWondow1;
	//PlayerWindow playerWondow2;
	/*if (playerWindows[0].init()){
		printf("Could not init player 1");
	}
	if (playerWindows[1].init()){
		printf("Could not init player 2");
	}*/
	
	//Render player 1
	SDL_SetRenderDrawColor(RendPlayer1, 0, 0, 0, 255);
	SDL_RenderClear(RendPlayer1);
	SDL_RenderPresent(RendPlayer1);
	//Render player 2
	SDL_SetRenderDrawColor(RendPlayer2, 0, 0, 0, 255);
	SDL_RenderClear(RendPlayer2);
	SDL_RenderPresent(RendPlayer2);

}
SDL_Window* Draw::getWindow1(){ return window1; }
SDL_Window* Draw::getWindow2(){ return window2; }
SDL_Texture* Draw::loadTexture(SDL_Renderer* renderer, std::string filename){
	//Load image into a Surface first, then load it into a Texture
	SDL_Surface* loadedImage = SDL_LoadBMP(filename.c_str());
	if (loadedImage == NULL){
		printf("Could not load texture file: %s\n", filename.c_str());
		return NULL;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
	SDL_FreeSurface(loadedImage);
	return texture;
}
void Draw::drawTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height){
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
void Draw::addObjectToPlayer1(std::string fileName, int x, int y, int width, int height){
	//SDL_Texture* newTexture = loadTexture(RendPlayer1, fileName);
	Object newObject = Object(x, y, width, height, loadTexture(RendPlayer1, fileName));
	//Object newObject2 = Object(x, y, width, height, loadTexture(RendPlayer2, fileName));
	cameraObjects1.push_back(newObject);
	//cameraObjects2.push_back(newObject2);
}
void Draw::addObjectToPlayer2(std::string fileName, int x, int y, int width, int height){
	//SDL_Texture* newTexture = loadTexture(RendPlayer1, fileName);
	//Object newObject = Object(x, y, width, height, loadTexture(RendPlayer1, fileName));
	Object newObject2 = Object(x, y, width, height, loadTexture(RendPlayer2, fileName));
	//cameraObjects1.push_back(newObject);
	cameraObjects2.push_back(newObject2);
}
void Draw::setPlayer1(std::string fileName, int x, int y, int width, int height){
	playerObject1 = Object(x, y, width, height, loadTexture(RendPlayer1, fileName));
	cameraObjects2.push_back(playerObject1);
}
void Draw::setPlayer2(std::string fileName, int x, int y, int width, int height){
	playerObject2 = Object(x, y, width, height, loadTexture(RendPlayer2, fileName));
	cameraObjects1.push_back(playerObject2);
}
void Draw::drawObjects(){
	drawPlayer1Objects();
	drawPlayer2Objects();
	/*
	for (int i = cameraObjects1.size()-2; i > 0; i--){
		//objectList.at(i)._x = objectList.at(i)._x + camera._x - (SCREEN_WIDTH / 2);
		//objectList.at(i)._y = objectList.at(i)._y + camera._y - (SCREEN_HEIGHT / 2);
		///cameraObjects1.at(i)._x += camera._x;// +(SCREEN_WIDTH / 2);
		///cameraObjects1.at(i)._y += camera._y;// +(SCREEN_HEIGHT / 2);
		cameraObjects1.at(i)._x += camera._x;// +(SCREEN_WIDTH / 2);
		cameraObjects1.at(i)._y += camera._y;// +(SCREEN_HEIGHT / 2);
		//objectList.at(i)._x = objectList.at(i)._x - camera._x + SCREEN_WIDTH;
		//objectList.at(i)._y = objectList.at(i)._x - camera._y + SCREEN_HEIGHT;
		//objectList.at(i)._x = objectList.at(i)._x - camera._x;
		//objectList.at(i)._y = objectList.at(i)._y - camera._y;
	}
	for (int i = cameraObjects2.size()-1; i >= 0; i--){
		cameraObjects2.at(i)._x += camera2._x;// +(SCREEN_WIDTH / 2);
		cameraObjects2.at(i)._y += camera2._y;// +(SCREEN_HEIGHT / 2);
	}
	//for (int i = objectList.size() - 1; i > 0 - 1; i--){
	for (int i = 0; i < cameraObjects1.size(); i++){
		drawTexture(RendPlayer1, cameraObjects1.at(i)._texture, cameraObjects1.at(i)._x, cameraObjects1.at(i)._y, cameraObjects1.at(i)._width, cameraObjects1.at(i)._height);
		drawTexture(RendPlayer2, cameraObjects2.at(i)._texture, cameraObjects2.at(i)._x, cameraObjects2.at(i)._y, cameraObjects2.at(i)._width, cameraObjects2.at(i)._height);
	}
	//Update Screen
	SDL_RenderPresent(RendPlayer1);
	SDL_RenderPresent(RendPlayer2);*/
}
void Draw::drawPlayer1Objects(){
	//Update the position of all objects relative to player 1
	for (int i = 0; i <= cameraObjects1.size()-1; i++){
		cameraObjects1.at(i)._x += camera._xOffset;// +(SCREEN_WIDTH / 2);
		cameraObjects1.at(i)._y += camera._yOffset;// +(SCREEN_HEIGHT / 2);
		//cameraObjects1.at(i)._x += camera._x;// +(SCREEN_WIDTH / 2);
		//cameraObjects1.at(i)._y += camera._y;// +(SCREEN_HEIGHT / 2);
	}
	//Draw the textures for all objects for player 2
	for (int i = 0; i <= cameraObjects1.size()-1; i++){
		drawTexture(RendPlayer1, cameraObjects1.at(i)._texture, cameraObjects1.at(i)._x, cameraObjects1.at(i)._y, cameraObjects1.at(i)._width, cameraObjects1.at(i)._height);
	}
	//Draw Player 1
	drawTexture(RendPlayer1, playerObject2._texture, playerObject2._x, playerObject2._y, playerObject2._width, playerObject2._height);
	drawTexture(RendPlayer1, playerObject1._texture, playerObject1._x, playerObject1._y, playerObject1._width, playerObject1._height);
	//Update Screen
	SDL_RenderPresent(RendPlayer1);
}
void Draw::drawPlayer2Objects(){
	//printf(" Just in Drawing Player 2 objects\n");
	//printf("Player 2 has %d objects to draw\n",cameraObjects2.size());
	//Update the position of all objects relative to player 2
	for (int i = 0; i <= cameraObjects2.size() - 1; i++){
		cameraObjects2.at(i)._x += camera2._xOffset;// +(SCREEN_WIDTH / 2);
		cameraObjects2.at(i)._y += camera2._yOffset;// +(SCREEN_HEIGHT / 2);
	}
	//Draw the textures for all objects for player 1
	for (int i = 0; i <= cameraObjects2.size()-1; i++){
	//	printf("drawing object %d", i);
		drawTexture(RendPlayer2, cameraObjects2.at(i)._texture, cameraObjects2.at(i)._x, cameraObjects2.at(i)._y, cameraObjects2.at(i)._width, cameraObjects2.at(i)._height);
	}
	//Draw Player 2
	drawTexture(RendPlayer2, playerObject1._texture, playerObject1._x, playerObject1._y, playerObject1._width, playerObject1._height);
	drawTexture(RendPlayer2,playerObject2._texture, playerObject2._x,playerObject2._y, playerObject2._width,playerObject2._height);
	SDL_RenderPresent(RendPlayer2);
}
/*
void Draw::drawEntity(Entity entity){
	if (enitity.perspective == 1 || enitity.perspective == 3){ //Entity rendered for just player 1 or both players
		drawTexture(RendPlayer1, entity.m_texture, entity.m_x, entity.m_y, entity.m_imageWidth, entity.m_imageHeight);
		SDL_RenderPresent(RendPlayer1);
	}else if(enitity.perspective == 2 || enitity.perspective == 3){	//Entity rendered for just player 2 or both players
		drawTexture(RendPlayer2, entity.m_texture, entity.m_x, entity.m_y, entity.m_imageWidth, entity.m_imageHeight);
		SDL_RenderPresent(RendPlayer2);
	}
}*/
void Draw::updateCamera(Dot dot){
	camera._xOffset = playerObject1._x - dot.x;
	camera._yOffset = playerObject1._y - dot.y;
	//playerObject1._x = dot.x;
	//playerObject1._y = dot.y;
	printf("CAMERA X,Y: %d, %d\n", camera._xOffset, camera._yOffset);
}
void Draw::updateCamera2(Dot2 dot){
	camera2._xOffset = playerObject2._x - dot.x;
	camera2._yOffset = playerObject2._y - dot.y;
	//playerObject2._x = dot.x;
	//playerObject2._y = dot.y;
	printf("CAMERA 2 X,Y: %d, %d\n", camera2._xOffset, camera2._yOffset);
}
void Draw::cleanUp(){
	for (int i = 0; i < cameraObjects1.size(); i++){
		SDL_DestroyTexture(cameraObjects1.at(i)._texture);
	}
	for (int i = 0; i < cameraObjects2.size(); i++){
		SDL_DestroyTexture(cameraObjects2.at(i)._texture);
	}
	SDL_DestroyRenderer(RendPlayer1);
	SDL_DestroyRenderer(RendPlayer2);
}