#include "DrawingObject.h"


DrawingObject::DrawingObject()
{
	velocity.setX(0);
	velocity.setY(0);
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