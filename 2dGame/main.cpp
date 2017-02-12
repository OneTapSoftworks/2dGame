#include <iostream>
#include <SDL.h>

using namespace std;

const int WIDTH = 640, HEIGHT = 480;
const char* TITLE = "OneTapSoftworks - Technology Demo";

int main(int argc, char*args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	cout << "Engine starting..." << endl;

	SDL_Window *window;

	window = SDL_CreateWindow(TITLE, 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

	if (window == NULL)
		cout << "ERROR: " << SDL_GetError() << endl;

	while (true) 
	{
		// INPUT
		// RENDER GAME
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}