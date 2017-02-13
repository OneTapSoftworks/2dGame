#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Engine
{
public:
	Engine();
	~Engine();

	// Simple parser
	stringstream parse(string line)
	{
		string lineBuf = line;
		size_t      pos = lineBuf.find_first_of(":");
		string attr = lineBuf.substr(0, pos - 1);
		stringstream respond(lineBuf.substr(pos + 1));
		return respond;
	}

	int getWidth(), getHeight(), getVsync();

	void ReadConfig();
private:
	int w, h, vsync;
};

