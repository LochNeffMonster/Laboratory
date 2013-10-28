#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include <SDL.h>

class Tilemap{
public:
	static const int WIDTH = 12;
	static const int HEIGHT = 12;
	static const int TILES = 5;
	static const int TILE_SIZE = 64;
	static const int TILE_SOLID_THRESHOLD = 3;
	int** m_tilemap;
	SDL_Texture** m_tilemapTextures;

	Tilemap(int** tilemap);
	~Tilemap();

	void draw();

	void setTile(int tileX, int tileY, int newTile);
	void setTile(double posX, double posY, int newTile);
	int getTile(int tileX, int tileY);
	int getTile(double posX, double posY);
	bool isSolid(int tileX, int tileY);
	bool isSolid(double posX, double posY);

private:
	bool inBounds(int tileX, int tileY);
};

#endif