#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>
#include <algorithm>

#include "Entity.h"
#include "Tilemap.h"

class Entity;

class World{
public:
	std::vector<Entity*> m_entities;
	Tilemap* m_tilemap;

	void update();
	void draw();

	void addEntity(Entity* entity);
	void removeEntity(Entity* entity);
};

#endif