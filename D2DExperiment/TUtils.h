#pragma once
#include <d2d1.h>
#include <random>

/// Version 1.0
class TUtils
{
public:
	TUtils();
	~TUtils();
	/// <summary>Simple geometrical hit-test (rectangles)</summary>
	static bool intersects(D2D1_RECT_F, D2D1_RECT_F);
	/// <summary>Simple distance collision detection</summary>
	static bool intersects(D2D1_POINT_2F, float, D2D1_POINT_2F, float);
	/// <summary>Random an integer value between 2 given values, inclusive</summary>
	static int randIntBetween(int, int);
	static float randIntBetweenF(int, int);
	/// <summary>Convert std::string to std::wsting</summary>
	static std::wstring TUtils::toWSString(std::string s);
	/// <summary>Pi</summary>
	static const float PI;
};

