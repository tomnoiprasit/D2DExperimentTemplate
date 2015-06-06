#pragma once
#include <d2d1.h>
#include "Velocity.h"

class DrawingObject
{
protected:
	const float MAX_X_SPEED = 5;
	const float MAX_Y_SPEED = 5;
	const float MIN_X_SPEED = -5;
	const float MIN_Y_SPEED = -5;
	const float OBJECT_TRANSPARENCY{ 0.8f };

	D2D1_RECT_F drawRectangle;
	D2D1_POINT_2F location;
	RECT windowSize;
	bool active;
	Velocity velocity;
	void setWindowSize(int, int, int, int);
	ID2D1SolidColorBrush* brush;
	float strokeWidth{ 1.f };

public:
	DrawingObject();
	~DrawingObject();
	D2D1_RECT_F getDrawRectangle();
	void setActive(bool);
	bool isActive() { return active; }
	void setBrush(ID2D1SolidColorBrush*);
	void setStrokeWidth(float);
};
