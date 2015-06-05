#pragma once
#ifndef LABEL_DISPLAY
#define LABEL_DISPLAY
#include <d2d1.h>
#include <dwrite.h>
#include <vector>
#include <string>

class LabelDisplayBox
{
	IDWriteFactory* factory;
	ID2D1Brush *brush; 
	std::string text;
	IDWriteTextFormat* textFormat;
	IDWriteTextLayout* textLayout;
	float x;
	float y;
	float width;
	float height;

	std::wstring wsText;
	std::wstring toWString(std::string);

public:
	LabelDisplayBox();
	LabelDisplayBox(ID2D1Brush*);
	LabelDisplayBox(ID2D1Brush*, float, float);
	LabelDisplayBox(ID2D1Brush*, float, float, std::string);
	LabelDisplayBox(ID2D1Brush*, float, float, std::string, IDWriteTextFormat*);
	LabelDisplayBox(ID2D1Brush*, float, float, float, float, std::string, IDWriteTextFormat*);
	~LabelDisplayBox();
	void draw(ID2D1HwndRenderTarget*);
	void setLocation(float, float);
	void setLocation(float, float, float, float);
	void setBrush(ID2D1Brush*);
	void setText(std::string);
	void setTextFormat(IDWriteTextFormat*);
	void setDWriteFactory(IDWriteFactory*);
};

#endif