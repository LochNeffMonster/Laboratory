#include "Entity.h"

void Entity::draw(){

}

void Entity::setLocation(double x, double y){
	m_x = x;
	m_y = y;
}

void Entity::setImage(std::string filename, int width, int height){
	setImage(NULL, width, height);
}

void Entity::setImage(SDL_Texture* texture, int width, int height){
	m_texture = texture;
	m_imageWidth = width;
	m_imageHeight = height;
	m_imageCenterX = m_imageWidth / 2;
	m_imageCenterY = m_imageHeight / 2;
	//foobar
}

void Entity::setWorld(World* world){
	m_world = world;
}