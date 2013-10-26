#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <string>
#include "SDL/SDL.h"

class Entity{
public:
	//Position of the entity
	double m_x, m_y;
	//Image of the entity
	SDL_Texture* m_texture;
	//The size of the entity measured in pixels
	int m_imageWidth, m_imageHeight;
	//The offset into the image that is considered the point of rotation.  By default it is initialized to the midpoint of the image
	int m_imageCenterX, m_imageCenterY;

	//Called every frame.  Entities should do all logic, physics, and other object handling in this method
	virtual void update() = 0;
	//Called to draw the entity to the screen.
	virtual void draw();

	//Sets the location of the entity
	void setLocation(double x, double y);
	//Sets the image of the entity
	void setImage(std::string filename, int width, int height);
	void setImage(SDL_Texture* texture, int width, int height);
	
protected:
	World* m_world;

private:
	void setWorld(World* world);
	friend class World;
};

#endif