#include "GameTime.h"

void GameTime::update() {

	currentTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - lastUpdateTime);
	lastUpdateTime = currentTime;
	elapsedTime += time_span.count()*33.3333;
	totalGameTime += elapsedTime;
}

GameTime::GameTime() {
	totalGameTime = elapsedTime = 0;
	lastUpdateTime = currentTime = std::chrono::high_resolution_clock::now();
}

TimeT GameTime::getElapsedTime() {
	return elapsedTime;
}

void GameTime::resetElapsedTime() {
	elapsedTime = 0;
}