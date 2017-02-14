#pragma once
#include <SDL.h>
#include <Windows.h>

class Player
{
public:
	Player(float,float,int,int);
	~Player();
	void MoveX(float);
	void MoveY(float);
	void Draw(SDL_Renderer*);
	void Update();
	float getX(), getY();
	int getW(), getH();
	void setX(float), setY(float);
	void setW(int), setH(int);
	void setTurn(int);
	float getSpd(), getVel();
	void setSpd(float), setVel(float);
	enum TURN { LEFT, RIGHT, UP, DOWN };
	TURN turn = DOWN;

private:
	SDL_Rect playerRect;
	float speed, vel;
	float x, y;
	float w, h;
};

