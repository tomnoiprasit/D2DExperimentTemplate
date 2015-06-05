#pragma once
#include <d2d1.h>
class DPIScale
{
	static float scaleX;
	static float scaleY;

public:

	static void Initialize(ID2D1Factory *pFactory)
	{
		float dpiX, dpiY;
		pFactory->GetDesktopDpi(&dpiX, &dpiY);
		scaleX = dpiX / 96.0f;
		scaleY = dpiY / 96.0f;
	}

	static float getScaleX() {
		return scaleX;
	}

	static float getScaleY() {
		return scaleY;
	}

	template <typename T>
	static D2D1_POINT_2F PixelsToDips(T x, T y)
	{
		return D2D1::Point2F(static_cast<float>(x) / scaleX, static_cast<float>(y) / scaleY);
	}
};

float DPIScale::scaleX = 1.0f;
float DPIScale::scaleY = 1.0f;