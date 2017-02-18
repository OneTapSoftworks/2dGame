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
		if (current_line == 7)
		{
			stringstream respond = parse(line);
			respond >> value;
			int xxx = value;
			if (xxx == 0)
				dev_mode = false;
			else
				dev_mode = true;
		}
		current_line++;
	}
	cfg.close();
}

void Engine::GetScripts()
{
	fstream loader;
	loader.open("engine/scripts/LOAD.txt");
	string line;
	int current_line = 1;
	size_t val = 0;

	int wykonanie = 0;
	while (getline(loader, line))
	{
		Pliki[wykonanie] = (line);
		wykonanie++;
	}

	loader.close();
}

void Engine::LoadScripts()
{
	int wykonania = 0;

	while (arr_size(Pliki) > wykonania)
	{
		fstream main_py;
		string linijka;
		main_py.open("engine/scripts/" + Pliki[wykonania]);
		string plik = "";

		while (getline(main_py, linijka))
		{
			plik = plik + linijka + "\n";
		}
		const char * c = plik.c_str();
		PyRun_SimpleString(c);
		wykonania++;
		main_py.close();
	}

}

int Engine::getHeight(){return h;}
int Engine::getWidth(){return w;}
int Engine::getVsync(){return vsync;}
int Engine::getFpsLimit(){return fps_limit;}
bool Engine::getDevMode() {return dev_mode;}
