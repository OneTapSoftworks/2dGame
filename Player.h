#pragma once
#include <SDL.h>

class Player
{
public:
	Player(float,float,int,int);
	~Player();
	void Move(float, float);
	void Draw(SDL_Renderer*);
	void Update();
	float getX(), getY();
	int getW(), getH();
	void setX(float), setY(float);
	void setW(int), setH(int);
	float getSpd();
	void setSpd(float);

private:
	SDL_Rect playerRect;
	float speed;
	float x, y;
	float w, h;
};

