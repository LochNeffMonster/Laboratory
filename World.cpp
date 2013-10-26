#include "World.h"

void World::update(){
	for (int i = 0; i < m_entities.size(); i++){
		Entity* entity = m_entities[i];
		entity->update();
	}
}

void World::draw(){
	m_tilemap->draw();
	for (int i = 0; i < m_entities.size(); i++){
		Entity* entity = m_entities[i];
		entity->draw();
	}
}

void World::addEntity(Entity* entity){
	m_entities.push_back(entity);
	entity->setWorld(this);
}

void World::removeEntity(Entity* entity){
	entity->setWorld(NULL);
	for (int i = 0; i < m_entities.size(); i++){
		if (m_entities[i] == entity){
			m_entities[i] = m_entities.back;
			m_entities.pop_back();
			return;
		}
	}
}

void World::setPerspective(int perspective){
	m_currentPerspective = perspective;
}