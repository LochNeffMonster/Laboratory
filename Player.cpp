#include "Player.h"

Player::Player(int playerNumber){
	m_playerNumber = playerNumber;

	if (m_playerNumber == 0){
		m_upKey = SDL_Scancode::SDL_SCANCODE_UP;
		m_downKey = SDL_Scancode::SDL_SCANCODE_DOWN;
		m_rightKey = SDL_Scancode::SDL_SCANCODE_RIGHT;
		m_leftKey = SDL_Scancode::SDL_SCANCODE_LEFT;
	}else{
		m_upKey = SDL_Scancode::SDL_SCANCODE_W;
		m_downKey = SDL_Scancode::SDL_SCANCODE_S;
		m_rightKey = SDL_Scancode::SDL_SCANCODE_D;
		m_leftKey = SDL_Scancode::SDL_SCANCODE_A;
	}
}


void Player::update(){
	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	m_velX *= PLAYER_DAMP;
	m_velY *= PLAYER_DAMP;

	if (keystates[m_upKey]){
		m_velY += PLAYER_ACCEL;
	}
	if (keystates[m_downKey]){
		m_velY -= PLAYER_ACCEL;
	}
	if (keystates[m_rightKey]){
		m_velX += PLAYER_ACCEL;
	}
	if (keystates[m_leftKey]){
		m_velX -= PLAYER_ACCEL;
	}

	m_x += m_velX;
	if (tilemapCollision()){
		m_x -= m_velX;
		m_velX = 0;
	}

	m_y += m_velY;
	if (tilemapCollision()){
		m_y -= m_velY;
		m_velY = 0;
	}
}

bool Player::tilemapCollision(){
	Tilemap* tilemap = m_world->m_tilemap;
	return tilemap->isSolid(m_x + m_imageWidth / 2, m_y + m_imageHeight / 2) ||
		   tilemap->isSolid(m_x - m_imageWidth / 2, m_y + m_imageHeight / 2) ||
		   tilemap->isSolid(m_x - m_imageWidth / 2, m_y - m_imageHeight / 2) ||
		   tilemap->isSolid(m_x + m_imageWidth / 2, m_y - m_imageHeight / 2);
}
