#include "NonPlayer.h"
#include <wtypes.h>
#include <random>

NonPlayer::NonPlayer()
{
	// Default window size
	// If not using default, subclass should call setWindowSize()
	windowSize = { 0, 0, 800, 600 }; 

	drawRectangle = D2D1::RectF(0.f, 0.f, 0.f, 0.f);
	currentFrame = 0;

	// maxFrameForAction should be derived from sourceRectangle vector
	// 
	maxFrameForAction = 8; // Number of different types of bitmap actions
	framePerAction = 1;
	frameCount = 0;
	randomSpeed();
	xLocation = 0;
	yLocation = 0;
	active = true;
}

NonPlayer::NonPlayer(ID2D1Bitmap* spriteSheet, std::vector<D2D1_RECT_F> sourceRectangle) {
	// Default window size
	// If not using default, subclass should call setWindowSize()
	windowSize = { 0, 0, 800, 600 };

	this->spriteSheet = spriteSheet;
	this->sourceRectangle = sourceRectangle;

	// Default to Frame 0
	setDrawRectangle(0, 0, sourceRectangle.at(0).right - sourceRectangle.at(0).left, sourceRectangle.at(0).bottom - sourceRectangle.at(0).top);

	currentFrame = 0;
	// maxFrameForAction should be derived from sourceRectangle vector
	// 
	maxFrameForAction = 8;
	framePerAction = 10;
	frameCount = 0;

	randomSpeed();

	float width = sourceRectangle.at(currentFrame).right - sourceRectangle.at(currentFrame).left;
	float height = sourceRectangle.at(currentFrame).bottom - sourceRectangle.at(currentFrame).top;

	xLocation = drawRectangle.left + width / 2;
	yLocation = drawRectangle.top + height / 2;

	active = true;
}

void NonPlayer::setUp(ID2D1Bitmap* spriteSheet, std::vector<D2D1_RECT_F> sourceRectangle) {
	// Default window size
	// If not using default, subclass should call setWindowSize()
	windowSize = { 0, 0, 800, 600 };

	this->spriteSheet = spriteSheet;
	this->sourceRectangle = sourceRectangle;

	// Default to Frame 0
	setDrawRectangle(0, 0, sourceRectangle.at(0).right - sourceRectangle.at(0).left, sourceRectangle.at(0).bottom - sourceRectangle.at(0).top);

	currentFrame = 0;
	// maxFrameForAction should be derived from sourceRectangle vector
	// 
	maxFrameForAction = 8;
	framePerAction = 10;
	frameCount = 0;

	randomSpeed();

	float width = sourceRectangle.at(currentFrame).right - sourceRectangle.at(currentFrame).left;
	float height = sourceRectangle.at(currentFrame).bottom - sourceRectangle.at(currentFrame).top;

	xLocation = drawRectangle.left + width / 2;
	yLocation = drawRectangle.top + height / 2;

	active = true;
}

NonPlayer::~NonPlayer()
{
}

void NonPlayer::setWindowSize(int left, int top, int right, int bottom) {
	windowSize = {left,top,right,bottom};
}

void NonPlayer::draw(ID2D1HwndRenderTarget* renderingTarget) {
	renderingTarget->DrawBitmap(spriteSheet,
		drawRectangle,
		NON_PLAYER_TRANSPARENCY,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		sourceRectangle.at(currentFrame));

}

void NonPlayer::draw(ID2D1HwndRenderTarget* renderingTarget, int x, int y) {
	setLocation(static_cast<float>(x), static_cast<float>(y));
	renderingTarget->DrawBitmap(spriteSheet,
		drawRectangle,
		NON_PLAYER_TRANSPARENCY,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		sourceRectangle.at(currentFrame));
}

void NonPlayer::setLocation(float x, float y) {
	float width = sourceRectangle.at(currentFrame).right - sourceRectangle.at(currentFrame).left;
	float height = sourceRectangle.at(currentFrame).bottom - sourceRectangle.at(currentFrame).top;

	float left = x - (width / 2);
	float top = y - (height / 2);
	float right = x + (width / 2);
	float bottom = y + (height / 2);

	float intPart;
	
	modf(static_cast<float>(left), &intPart);
	left = intPart;
	modf(static_cast<float>(top), &intPart);
	top = intPart;
	modf(static_cast<float>(right), &intPart);
	right = intPart;
	modf(static_cast<float>(bottom), &intPart);
	bottom = intPart;

	setDrawRectangle(left, top, right, bottom);

	xLocation = x;
	yLocation = y;
}

void NonPlayer::update(GameTime gameTime) {

	float xIntPart;
	float yIntPart;
	modf(static_cast<float>(xLocation + velocity.getX() * static_cast<float>(gameTime.getElapsedTime())), &xIntPart);
	modf(static_cast<float>(yLocation + velocity.getY() * static_cast<float>(gameTime.getElapsedTime())), &yIntPart);
	setLocation(xIntPart, yIntPart);

	bounceLeftRight();
	bounceTopBottom();

	++frameCount;
	if (frameCount > framePerAction) {
		++currentFrame;
		if (currentFrame == maxFrameForAction)
			currentFrame = 0;
		frameCount = 0;
	}

}

void NonPlayer::randomSpeed() {
	std::default_random_engine e(std::random_device{}());
	std::uniform_int_distribution<int> x(static_cast<int>(MIN_X_SPEED), static_cast<int>(MAX_X_SPEED));
	std::uniform_int_distribution<int> y(static_cast<int>(MIN_Y_SPEED), static_cast<int>(MAX_Y_SPEED));
	velocity.setX(0.f);
	while (velocity.getX() == 0) velocity.setX(static_cast<float>(x(e)));
	velocity.setY(0);
	while (velocity.getY() == 0) velocity.setY(static_cast<float>(y(e)));
}

D2D1_RECT_F NonPlayer::getDrawRectangle() {
	return drawRectangle;
}

void NonPlayer::moveLeft() {
	velocity.setY(0);
}

void NonPlayer::moveRight() {
	velocity.setY(0);
}

void NonPlayer::moveUp() {
	velocity.setX(0);
}

void NonPlayer::moveDown() {
	velocity.setX(0);
}

void NonPlayer::moveLeft(float speed) {
	velocity.setX(speed);
	velocity.setY(0);
}

void NonPlayer::moveRight(float speed) {
	velocity.setX(speed);
	velocity.setY(0);
}

void NonPlayer::moveUp(float speed) {
	velocity.setX(0);
	velocity.setY(speed);
}

void NonPlayer::moveDown(float speed) {
	velocity.setX(0);
	velocity.setY(speed);
}

void NonPlayer::setDrawRectangle(D2D1_RECT_F rect) {
	drawRectangle.left = rect.left;
	drawRectangle.top = rect.top;
	drawRectangle.right = rect.right;
	drawRectangle.bottom = rect.bottom;
}

void NonPlayer::setDrawRectangle(float left, float top, float right, float bottom) {
	drawRectangle.left = left;
	drawRectangle.top = top;
	drawRectangle.right = right;
	drawRectangle.bottom = bottom;
}

bool NonPlayer::isActive() {
	return active;
}

void NonPlayer::bounceLeftRight() {
	float width = sourceRectangle.at(currentFrame).right - sourceRectangle.at(currentFrame).left + 1;
	if (drawRectangle.right > windowSize.right) {
		drawRectangle.left = windowSize.right - width;
		drawRectangle.right = drawRectangle.left + width;
		xLocation = drawRectangle.left + width / 2;
		velocity.setX(velocity.getX() *-1);
	}
	else if (drawRectangle.left < 0) {
		drawRectangle.left = 0;
		drawRectangle.right = drawRectangle.left + width;
		xLocation = drawRectangle.left + width / 2;
		velocity.setX(velocity.getX() *-1);
	}
}

void NonPlayer::bounceTopBottom() {
	float height = sourceRectangle.at(currentFrame).bottom - sourceRectangle.at(currentFrame).top + 1;
	if (drawRectangle.bottom > windowSize.bottom) {
		drawRectangle.top = windowSize.bottom - height;
		drawRectangle.bottom = drawRectangle.top + height;
		yLocation = drawRectangle.top + height / 2;
		velocity.setY(velocity.getY() *-1);
	}
	else if (drawRectangle.top < 0) {
		drawRectangle.top = 0;
		drawRectangle.bottom = drawRectangle.top + height;
		yLocation = drawRectangle.top + height / 2;
		velocity.setY(velocity.getY() *-1);
	}
}

void NonPlayer::setActive(bool b) {
	active = b;
}