#include "TUtils.h"

TUtils::TUtils()
{
}


TUtils::~TUtils()
{
}

bool TUtils::intersects(D2D1_RECT_F rect1, D2D1_RECT_F rect2) {
	return !(rect1.right < rect2.left ||
			rect2.right < rect1.left ||
			rect1.bottom < rect2.top ||
			rect2.bottom < rect1.top);
}

bool TUtils::intersects(D2D1_POINT_2F centre1, float radius1, D2D1_POINT_2F centre2, float radius2) {
	float dx = centre1.x - centre2.x;
	float dy = centre1.y - centre2.y;
	float d = sqrtf(dx * dx + dy * dy);
	return d < (radius1 + radius2);
}

int TUtils::randIntBetween(int begin, int end) {
	std::default_random_engine e(std::random_device{}());
	std::uniform_int_distribution<int> u(begin, end);
	return u(e);
}

std::wstring TUtils::toWSString(std::string s) {
	std::wstring ws;

	for (auto c : s) {
		if (c == '/')
			ws.push_back(c);
		ws.push_back(c);
	}
	ws.push_back(0);

	return ws;
}