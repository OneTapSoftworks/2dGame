#include "Player.h"

Player::Player(float x, float y, int w, int h)
{
	// Setup player
	Player::x = x;
	Player::y = y;
	Player::w = w;
	Player::h = h;

	speed = 5;
}
Player::~Player(){}

// Draw player
void Player::Draw(SDL_Renderer* r)
{
	Update();

	SDL_SetRenderDrawColor(r, 51, 102, 25, 255);
	SDL_RenderFillRect(r, &playerRect);
}

// Update function for player
void Player::Update()
{
	playerRect.x = x;
	playerRect.y = y;
	playerRect.w = 50;
	playerRect.h = 50;
}

void Player::Move(float xx, float yy)
{
	x += xx;
	y += yy;
}

// Getters&Setters
float Player::getX(){return x;}
float Player::getY(){return y;}
int Player::getW(){return w;}
int Player::getH(){return h;}
void Player::setX(float xx){x=xx;}
void Player::setY(float yy){y=yy;}
void Player::setW(int ww){w=ww;}
void Player::setH(int hh){h = hh;}
void Player::setSpd(float spd){speed = spd;}
float Player::getSpd(){return speed;}