#include<iostream>
#include"Vec2.h"

int main() {
	Vec2 v1(23,5);
	int s = sizeof(Vec2);
	char * bytes;
	std::cout << v1.x << ',' << v1.y << std::endl;

	bytes = v1.toBytes();

	for (int i = 0; i < s; i++) {
		std::cout << bytes[i];
	}
	std::cout << std::endl;

	Vec2 * v2 = new Vec2(0, 0);

	std::memcpy(v2, bytes, s);

	std::cout << v2->x << ',' << v2->y << std::endl;

	system("pause");

	return 0;
}