#include "Engine.h"

Engine::Engine(){}
Engine::~Engine(){}

void Engine::ReadConfig()
{
	fstream cfg;
	cfg.open("engine.cfg");

	int current_line = 1;
	string line;

	while (getline(cfg, line))
	{
		if (current_line == 2)
		{
			string lineBuf = line;
			size_t      pos = lineBuf.find_first_of(":");
			string attr = lineBuf.substr(0, pos - 1);
			size_t      value = 0;
			stringstream ss(lineBuf.substr(pos + 1));
			ss >> value;
			w = value;
		}
		if (current_line == 3)
		{
			string lineBuf = line;
			size_t      pos = lineBuf.find_first_of(":");
			string attr = lineBuf.substr(0, pos - 1);
			size_t      value = 0;
			stringstream ss(lineBuf.substr(pos + 1));
			ss >> value;
			h = value;
		}
		if (current_line == 4)
		{
			string lineBuf = line;
			size_t      pos = lineBuf.find_first_of(":");
			string attr = lineBuf.substr(0, pos - 1);
			size_t      value = 0;
			stringstream ss(lineBuf.substr(pos + 1));
			ss >> value;
			vsync = value;
		}
		current_line++;
	}
	cfg.close();
}

int Engine::getHeight(){return h;}
int Engine::getWidth(){return w;}
int Engine::getVsync(){return vsync;}
