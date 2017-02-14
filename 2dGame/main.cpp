#include <iostream>
#include <fstream>
#include <sstream>
#include <SDL.h>
#include <SDL_TTF.h>
#include <Windows.h>
#include "Player.h"
#include "Engine.h"
#include "MainMenu.h"

using namespace std;

// Window config
int WIDTH = 0, HEIGHT = 0, VSYNC = 0;
const char* TITLE = "OneTapSoftworks - Technology Demo";
const bool RESIZABLE = false;

// State system
enum STATE {MENU, GAME};
STATE state = MENU;

Engine engine;

bool running = true;

int main(int argc, char*args[])
{
	// Initializing
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	cout << "Engine starting..." << endl;
	cout << "Reading config files..." << endl;

	// Reading engine config
	engine.ReadConfig();
	WIDTH = engine.getWidth();
	HEIGHT = engine.getHeight();
	VSYNC = engine.getVsync();
	cout << "Config files readed." << endl;
	cout << "Creating game window." << endl;

	// Setting up graphics
	SDL_GL_SetSwapInterval(VSYNC);

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

	// Creating player
	Player* player = new Player(50,50,50,50);

	// Creating menu instance
	MainMenu* menu = new MainMenu(renderer);

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
			if (state == STATE::GAME)
			{
				float spd = player->getSpd();
				float vel = spd / 100;
				if (event.type == SDL_KEYDOWN)
				{
					
					float spd = player->getSpd();

					if ((event.key.keysym.sym == SDLK_a))
					{
						player->setTurn(1);
						player->setVel(vel);
					}
					if ((event.key.keysym.sym == SDLK_d))
					{
						player->setTurn(2);
						player->setVel(vel);
					}
					if ((event.key.keysym.sym == SDLK_w))
					{
						player->setTurn(3);
						player->setVel(vel);
					}
					if ((event.key.keysym.sym == SDLK_s))
					{
						player->setTurn(4);
						player->setVel(vel);
					}
				}
				if (event.type == SDL_KEYUP)
				{
					if ((event.key.keysym.sym == SDLK_a))
					{
						player->setVel(0);
					}
					if ((event.key.keysym.sym == SDLK_d))
					{
						player->setVel(0);
					}
					if ((event.key.keysym.sym == SDLK_w))
					{
						player->setVel(0);
					}
					if ((event.key.keysym.sym == SDLK_s))
					{
						player->setVel(0);
					}
				}
			}
			else if (state == STATE::MENU)
			{
				if (event.key.keysym.sym == SDLK_s)
				{
					state = STATE::GAME;
				}
				if (event.key.keysym.sym == SDLK_q)
				{
					exit(0);
				}
			}
		}

		/* !RENDERING! */

		// Clearing screen
		if(state == STATE::MENU)
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		else
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		switch (state)
		{
			case STATE::MENU:
				// RENDEROWANIE MENU
				menu->Draw(renderer);
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
	TTF_Quit();
	return EXIT_SUCCESS;
}
