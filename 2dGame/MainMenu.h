#pragma once
#include <SDL.h>
#include <SDL_TTF.h>
class MainMenu
{
public:
	MainMenu(SDL_Renderer*);
	~MainMenu();
	void Draw(SDL_Renderer*);
private:
	TTF_Font* font;
	SDL_Renderer* r;
	SDL_Surface* surfaceMsg;
	SDL_Texture* msg;
	SDL_Rect msg_rect;
};

