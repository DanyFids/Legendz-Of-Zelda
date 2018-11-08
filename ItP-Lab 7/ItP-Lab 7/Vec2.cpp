#include<string>
#include"Vec2.h"

Vec2::Vec2(int X, int Y) {
	x = (float)X;
	y = (float)Y;
}

Vec2::Vec2(double X, double Y) {
	x = (float)X;
	y = (float)Y;
}

Vec2::Vec2(float X, float Y) {
	x = X;
	y = Y;
}

Vec2::Vec2(const Vec2 &v) {
	x = v.x;
	y = v.y;
}

char* Vec2::toBytes() {
	const int size = sizeof(Vec2);
	char bytes[size];
	std::memcpy(bytes, this, size);

	return bytes;
}