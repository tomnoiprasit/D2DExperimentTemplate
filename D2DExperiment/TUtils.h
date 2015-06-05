#pragma once
#include <d2d1.h>
#include <random>

class TUtils
{
public:
	TUtils();
	~TUtils();

	static bool intersects(D2D1_RECT_F, D2D1_RECT_F); // Simple geometrical hit-test (rectangles)
	static bool intersects(D2D1_POINT_2F, float, D2D1_POINT_2F, float); // Simple distance collision detection
	static int randIntBetween(int, int);
	static std::wstring TUtils::toWSString(std::string s);
};

