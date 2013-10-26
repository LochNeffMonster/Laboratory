#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"
#include "World.h"
#include "SDL/SDL.h"

class Player : public Entity{
public:
	static const double PLAYER_DAMP;
	static const double PLAYER_ACCEL;
	static const int PLAYER_SIZE;

	double m_velX, m_velY;
	//Player number is 0 for the first player, or 1 for the second player
	int m_playerNumber;

	Player(int playerNumber);

	virtual void update() override;

private:
	int m_upKey, m_downKey, m_rightKey, m_leftKey;
	bool tilemapCollision();
	
};

#endif