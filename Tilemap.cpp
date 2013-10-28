#include "Tilemap.h"

Tilemap::Tilemap(int** tilemap){
	m_tilemapTextures = new SDL_Texture*[TILES];
	for (int i = 0; i < TILES; i++){
		m_tilemapTextures[i] = NULL;//get texture here
	}

	m_tilemap = tilemap;
}

Tilemap::~Tilemap(){
	for (int i = 0; i < TILES; i++){
		delete m_tilemapTextures[i];
	}
	delete m_tilemapTextures;
}

void Tilemap::draw(){
	for (int x = 0; x < WIDTH; x++){
		for (int y = 0; y < HEIGHT; y++){
			int tile = getTile(x, y);
			SDL_Texture* tileTexture = m_tilemapTextures[tile];
			//drawTexture(x*TILE_SIZE, y*TILE_SIZE, texture);
		}
	}
}

void Tilemap::setTile(int tileX, int tileY, int newTile){
	if (!inBounds(tileX, tileY)){
		return;
	}
	m_tilemap[tileX][tileY] = newTile;
}

void Tilemap::setTile(double posX, double posY, int newTile){
	setTile(static_cast<int>(posX / TILE_SIZE), static_cast<int>(posY / TILE_SIZE), newTile);
}

int Tilemap::getTile(int tileX, int tileY){
	if (!inBounds(tileX, tileY)){
		return -1;
	}
	return m_tilemap[tileX][tileY];
}

int Tilemap::getTile(double posX, double posY){
	return getTile(static_cast<int>(posX / TILE_SIZE), static_cast<int>(posY / TILE_SIZE));
}

bool Tilemap::isSolid(int tileX, int tileY){
	return getTile(tileX, tileY) > TILE_SOLID_THRESHOLD;
}

bool Tilemap::isSolid(double posX, double posY){
	return getTile(posX, posY) > TILE_SOLID_THRESHOLD;
}


bool Tilemap::inBounds(int tileX, int tileY){
	return tileX >= 0 && tileX < WIDTH && tileY >= 0 && tileY < HEIGHT;
}