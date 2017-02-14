#include "MainMenu.h"

MainMenu::MainMenu(SDL_Renderer* r)
{
	SDL_Color White = { 255,255,255 };

	font = TTF_OpenFont("engine/fonts/arial.ttf", 24);
	surfaceMsg = TTF_RenderText_Solid(font, "Wcisnij S zeby zaczac albo Q zeby wylaczyc gre!", White);
	msg = SDL_CreateTextureFromSurface(r, surfaceMsg);

	msg_rect.x = 0;
	msg_rect.y = 0;
	msg_rect.w = 480;
	msg_rect.h = 100;
}
MainMenu::~MainMenu(){}

void MainMenu::Draw(SDL_Renderer* rr)
{
	SDL_RenderCopy(rr, msg, NULL, &msg_rect);
}
