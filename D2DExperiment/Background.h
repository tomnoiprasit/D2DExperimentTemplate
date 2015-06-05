#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <d2d1.h>
#include <vector>
#include "GameTime.h"

#pragma comment(lib, "d2d1")

class Background
{
	D2D1_RECT_F drawRectangle;
	ID2D1Bitmap* spriteSheet;
	std::vector<D2D1_RECT_F> sourceRectangle;
	void setDrawRectangle(float,float,float,float);

public:
	Background();

	void setBackground(ID2D1Bitmap* , std::vector<D2D1_RECT_F>);
	void setUp(ID2D1Bitmap*, std::vector<D2D1_RECT_F>); // Redefine the setBackground to make it consistent
	void draw(ID2D1HwndRenderTarget*);
	void update(GameTime);

	~Background();
};
#endif
