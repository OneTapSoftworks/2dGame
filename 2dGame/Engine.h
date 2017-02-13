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

	int getWidth(), getHeight(), getVsync();

	void ReadConfig();
private:
	int w, h, vsync;
};

