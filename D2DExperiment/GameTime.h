#pragma once
#ifndef GAME_TIME
#define GAME_TIME
#include <windows.h>
#include <chrono>

using TimeT = double;

struct GameTime
{

	std::chrono::high_resolution_clock::time_point currentTime;
	std::chrono::high_resolution_clock::time_point lastUpdateTime;
	TimeT elapsedTime;
	TimeT totalGameTime;

	void update();
	void resetElapsedTime();

	GameTime();
	TimeT getElapsedTime();
};
#endif