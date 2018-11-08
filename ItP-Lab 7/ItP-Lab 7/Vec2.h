#pragma once


class Vec2 {
public:
	float x, y;

	Vec2(int X, int Y);
	Vec2(float X, float Y);
	Vec2(double X, double Y);
	Vec2(const Vec2 &v);

	char* toBytes();
};