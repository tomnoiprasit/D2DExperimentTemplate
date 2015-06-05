#pragma once
#ifndef _NON_PLAYER_H
#define _NON_PLAYER_H
#include <d2d1.h>
#include <vector>
#include <math.h>
#include "GameTime.h"
#include "Velocity.h"

#pragma comment(lib, "d2d1")
class NonPlayer
{

protected:

	ID2D1Bitmap* spriteSheet;
	D2D1_RECT_F drawRectangle;
	std::vector<D2D1_RECT_F> sourceRectangle;
	RECT windowSize;

	const float NON_PLAYER_TRANSPARENCY{ 0.8f };

	void setDrawRectangle(D2D1_RECT_F);
	void setDrawRectangle(float, float, float, float);

	int currentFrame;
	bool active;
	int frameCount;

	float xLocation;
	float yLocation;
	Velocity velocity;
	float angle{ 0.f };

	const float MAX_X_SPEED = 5;
	const float MAX_Y_SPEED = 5;
	const float MIN_X_SPEED = -5;
	const float MIN_Y_SPEED = -5;

	void bounceLeftRight();
	void bounceTopBottom();

	int maxFrameForAction;
	int framePerAction;
	

public:
	NonPlayer();
	NonPlayer(ID2D1Bitmap*, std::vector<D2D1_RECT_F>);
	~NonPlayer();
	void setUp(ID2D1Bitmap*, std::vector<D2D1_RECT_F>);
	void draw(ID2D1HwndRenderTarget*);
	void draw(ID2D1HwndRenderTarget*, int, int);
	void setLocation(float, float);
	enum {
		MOVE_LEFT,
		MOVE_RIGHT,
		MOVE_UP,
		MOVE_DOWN
	} action;

	void update(GameTime);
	void randomSpeed();
	D2D1_RECT_F getDrawRectangle();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void moveLeft(float);
	void moveRight(float);
	void moveUp(float);
	void moveDown(float);
	void setActive(bool);
	bool isActive();
	// For subclass to consider setting them
	void setWindowSize(int, int, int, int);

};

#endif