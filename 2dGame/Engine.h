#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Python-2.7\Python.h"
#include "Player.h"

using namespace std;

class Engine
{
public:
	Engine();
	~Engine();

	// Get array size
	template <typename T, unsigned int N>
	unsigned int arr_size(const T(&tab)[N])
	{
		return N;
	}

	// Simple parser
	stringstream parse(string line)
	{
		string lineBuf = line;
		size_t      pos = lineBuf.find_first_of(":");
		string attr = lineBuf.substr(0, pos - 1);
		stringstream respond(lineBuf.substr(pos + 1));
		return respond;
	}

	int getWidth(), getHeight(), getVsync(), getFpsLimit();
	bool getDevMode();

	void ReadConfig();
	void GetScripts(), LoadScripts();
private:
	int w, h, vsync, fps_limit;
	bool dev_mode;
	Player* player;
	string Pliki[1000];
};

