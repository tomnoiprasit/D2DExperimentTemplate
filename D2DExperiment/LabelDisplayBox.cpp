#include "LabelDisplayBox.h"

LabelDisplayBox::LabelDisplayBox()
{
	width = 200.f;
	height = 24.f;
}

LabelDisplayBox::LabelDisplayBox(ID2D1Brush* brush) {
	setBrush(brush);
}

LabelDisplayBox::LabelDisplayBox(ID2D1Brush* brush, float x, float y) {
	setBrush(brush);
	setLocation(x, y);
}

LabelDisplayBox::LabelDisplayBox(ID2D1Brush* brush, float x, float y, std::string s) {
	setBrush(brush);
	setLocation(x, y);
	setText(s);
}

LabelDisplayBox::LabelDisplayBox(ID2D1Brush* brush, float x, float y, std::string s, IDWriteTextFormat* textFormat) {
	setBrush(brush);
	setLocation(x, y);
	setText(s);
	setTextFormat(textFormat);
}

LabelDisplayBox::LabelDisplayBox(ID2D1Brush* brush, float left, float top, float right, float bottom, std::string s, IDWriteTextFormat* textFormat) {
	setBrush(brush);
	setLocation(left, top, right, bottom);
	setText(s);
	setTextFormat(textFormat);
}

LabelDisplayBox::~LabelDisplayBox()
{

}

void LabelDisplayBox::draw(ID2D1HwndRenderTarget* renderingTarget) {
	
	renderingTarget->DrawTextA(
		wsText.c_str(), 
		wsText.size(), 
		textFormat, 
		D2D1::RectF(x,y,x+width,y+height),
		brush);
	//renderingTarget->DrawTextLayout(D2D1::Point2F(x, y), textLayout, brush);
}

void LabelDisplayBox::setLocation(float x, float y) {
	this->x = x;
	this->y = y;
}

void LabelDisplayBox::setLocation(float left, float top, float right, float bottom) {
	this->x = left;
	this->y = top;
	this->width = right - left;
	this->height = bottom - top;
}

void LabelDisplayBox::setBrush(ID2D1Brush* brush) {
	this->brush = brush;
}

void LabelDisplayBox::setText(std::string s) {
	text = s;
	wsText = toWString(s);
}

void LabelDisplayBox::setTextFormat(IDWriteTextFormat* textFormat) {
	this->textFormat = textFormat;
	//factory->CreateTextLayout(
	//	wsText.c_str(),      // The string to be laid out and formatted.
	//	wsText.size(),  // The length of the string.
	//	textFormat,  // The text format to apply to the string (contains font information, etc).
	//	width,         // The width of the layout box.
	//	height,        // The height of the layout box.
	//	&textLayout  // The IDWriteTextLayout interface pointer.
	//);
}

void LabelDisplayBox::setDWriteFactory(IDWriteFactory* factory) {
	this->factory = factory;
}

std::wstring LabelDisplayBox::toWString(std::string s) {
	std::wstring ws;

	for (auto c : s) {
		if (c == '/')
			ws.push_back(c);
		ws.push_back(c);
	}
	ws.push_back(0);

	return ws;
}
