#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <string>
#include "SDL/SDL.h"

class Entity{
public:
	double m_x, m_y;
	SDL_Texture* m_texture;
	int m_imageWidth, m_imageHeight;
	int m_imageCenterX, m_imageCenterY;

	virtual void update();
	virtual void draw();

	void setLocation(double x, double y);
	void setImage(std::string filename, int width, int height);
	void setImage(SDL_Texture* texture, int width, int height);
	
protected:
	World* m_world;

private:
	void setWorld(World* world);
	friend class World;
};

#endif