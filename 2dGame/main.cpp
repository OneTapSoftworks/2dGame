#include <iostream>
#include <SDL.h>
#include "SDL_render.h"

using namespace std;

// Window config
const int WIDTH = 640, HEIGHT = 480;
const char* TITLE = "OneTapSoftworks - Technology Demo";
const bool RESIZABLE = false;

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

	// Setting up a Rectangle
	SDL_Rect rect;
	rect.x = 50;
	rect.y = 50;
	rect.w = 50;
	rect.h = 50;

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
		}

		/* !RENDERING! */

		// Clearing screen
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		// Rendering player
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &rect);

		// Cleaning up
		SDL_RenderPresent(renderer);
	}

	// Cleaning up
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}
