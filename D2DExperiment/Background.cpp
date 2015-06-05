#include "Background.h"

Background::Background()
{

}

// setBackground is now marked as faded.
// Use setUp instead
// TN
void Background::setBackground(ID2D1Bitmap* spriteSheet, std::vector<D2D1_RECT_F> sourceRectangle) {

	this->spriteSheet = spriteSheet;
	this->sourceRectangle = sourceRectangle;

	setDrawRectangle(0.f, 0.f, sourceRectangle.at(0).right - sourceRectangle.at(0).left, sourceRectangle.at(0).bottom - sourceRectangle.at(0).top);

	float width = sourceRectangle.at(0).right - sourceRectangle.at(0).left;
	float height = sourceRectangle.at(0).bottom - sourceRectangle.at(0).top;

}

void Background::setUp(ID2D1Bitmap* spriteSheet, std::vector<D2D1_RECT_F> sourceRectangle) {

	this->spriteSheet = spriteSheet;
	this->sourceRectangle = sourceRectangle;

	setDrawRectangle(0.f, 0.f, sourceRectangle.at(0).right - sourceRectangle.at(0).left, sourceRectangle.at(0).bottom - sourceRectangle.at(0).top);

	float width = sourceRectangle.at(0).right - sourceRectangle.at(0).left;
	float height = sourceRectangle.at(0).bottom - sourceRectangle.at(0).top;

}

Background::~Background()
{
}

void Background::setDrawRectangle(float left, float top, float right, float bottom) {
	drawRectangle.left = left;
	drawRectangle.top = top;
	drawRectangle.right = right;
	drawRectangle.bottom = bottom;
}

void Background::draw(ID2D1HwndRenderTarget* renderingTarget) {
	renderingTarget->DrawBitmap(spriteSheet,
		drawRectangle,
		1.0,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		sourceRectangle.at(0));
}

void Background::update(GameTime) {

}