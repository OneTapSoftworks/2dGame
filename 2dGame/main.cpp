#include <iostream>
#include <SDL.h>
#include "Player.h"

using namespace std;

// Window config
const int WIDTH = 640, HEIGHT = 480;
const char* TITLE = "OneTapSoftworks - Technology Demo";
const bool RESIZABLE = false;

enum STATE {MENU, GAME};
STATE state = GAME;

bool running = true;

int main(int argc, char*args[])
{
	// Initializing
	SDL_Init(SDL_INIT_EVERYTHING);
	cout << "Engine starting..." << endl;

	// Setting up game window
	SDL_Window *window;
	window = SDL_CreateWindow(TITLE, 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		WIDTH, HEIGHT, RESIZABLE);
	if (window == NULL) // Errors finding (for debugging)
		cout << "ERROR: " << SDL_GetError() << endl;

	// Setting up renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Player* player = new Player(50,50,50,50);

	SDL_Event event;
	while (running) 
	{
		// Events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
				break;
			}
			if (event.type == SDL_KEYDOWN)
			{
				float spd = player->getSpd();
				if ((event.key.keysym.sym == SDLK_a))
				{
					player->Move(-spd, 0);
				}
				if ((event.key.keysym.sym == SDLK_d))
				{
					player->Move(spd, 0);
				}
				if ((event.key.keysym.sym == SDLK_w))
				{
					player->Move(0, -spd);
				}
				if ((event.key.keysym.sym == SDLK_s))
				{
					player->Move(0, spd);
				}
			}
		}

		/* !RENDERING! */

		// Clearing screen
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		switch (state)
		{
			case STATE::MENU:
				// RENDEROWANIE MENU
				break;
			case STATE::GAME:
				// RENDEROWANIE GRY
				player->Draw(renderer);
				break;
		}

		// Cleaning up
		SDL_RenderPresent(renderer);
	}

	// Cleaning up
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}
