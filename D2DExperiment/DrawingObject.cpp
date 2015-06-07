#include "DrawingObject.h"
/// Version 1.01

DrawingObject::DrawingObject()
{
	velocity.setX(0);
	velocity.setY(0);
	acceleration.x = 0.f;
	acceleration.y = 0.f;
	active = false;
}


DrawingObject::~DrawingObject()
{
}

void DrawingObject::setWindowSize(int left, int top, int width, int height) {
	windowSize = { left, top, left + width, top + height };
}

D2D1_RECT_F DrawingObject::getDrawRectangle() {
	return drawRectangle;
}

void DrawingObject::setActive(bool b) {
	active = b;
}

void DrawingObject::setStrokeWidth(float w) {
	strokeWidth = w;
}

void DrawingObject::setBrush(ID2D1SolidColorBrush* b) {
	brush = b;
}

void DrawingObject::setVelocity(float x, float y) {
	velocity.setX(x);
	velocity.setY(y);
}

void DrawingObject::setSpeed(float s) {
	speed = s;
}

void DrawingObject::setAngle(float a) {
	angle = a * TUtils::PI / 180.f;
}

void DrawingObject::setAcceleration(float x, float y) {
	acceleration.x = x;
	acceleration.y = y;
}

void DrawingObject::setAccelerationX(float x) {
	acceleration.x = x;
}

void DrawingObject::setAccelerationY(float y) {
	acceleration.y = y;
}

float DrawingObject::getAccelerationX() {
	return acceleration.x;
}

float DrawingObject::getAccelerationY() {
	return acceleration.y;
}

float DrawingObject::getVelocityX() {
	return velocity.getX();
}

float DrawingObject::getVelocityY() {
	return velocity.getY();
}
