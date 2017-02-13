#include "Engine.h"

Engine::Engine(){}
Engine::~Engine(){}

void Engine::ReadConfig()
{
	fstream cfg;
	cfg.open("engine/core.cfg");
	string line;
	int current_line = 1;
	size_t      value = 0;

	while (getline(cfg, line))
	{
		if (current_line == 2)
		{
			stringstream respond = parse(line);
			respond >> value;
			w = value;
		}
		if (current_line == 3)
		{
			stringstream respond = parse(line);
			respond >> value;
			h = value;
		}
		if (current_line == 4)
		{
			stringstream respond = parse(line);
			respond >> value;
			vsync = value;
		}
		if (current_line == 5)
		{
			stringstream respond = parse(line);
			respond >> value;
			fps_limit = value;
		}
		current_line++;
	}
	cfg.close();
}

int Engine::getHeight(){return h;}
int Engine::getWidth(){return w;}
int Engine::getVsync(){return vsync;}
int Engine::getFpsLimit(){return fps_limit;}
