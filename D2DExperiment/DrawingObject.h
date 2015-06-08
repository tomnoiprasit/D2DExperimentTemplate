#pragma once
#include <d2d1.h>
#include <functional>
#include "Velocity.h"
#include "TUtils.h"
/// Version 1.01
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
	D2D1_POINT_2F acceleration;
	D2D1_POINT_2F gravity;
	void setWindowSize(int, int, int, int);
	ID2D1SolidColorBrush* brush;
	float strokeWidth{ 1.f };
	float speed{ 0.f };
	float angle{ 0.f };

public:
	DrawingObject();
	~DrawingObject();
	D2D1_RECT_F getDrawRectangle();
	void setActive(bool);
	bool isActive() { return active; }
	void setBrush(ID2D1SolidColorBrush*);
	void setStrokeWidth(float);
	void setVelocity(float, float);
	void setAcceleration(float, float);
	void setAccelerationX(float);
	void setAccelerationY(float);
	float getAccelerationX();
	float getAccelerationY();
	float getVelocityX();
	float getVelocityY();
	void setSpeed(float);
	void setAngle(float);
	void setGravity(float f) { gravity.y = f; }
	float getGravity() { return gravity.y; }
	bool useGravity() { return !(gravity.x == 0 && gravity.y == 0); }
};

