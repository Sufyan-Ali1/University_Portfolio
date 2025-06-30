#pragma once
#include"Point.h"
class Circle:public Point
{
	float rad;
public:
	Circle(int = 0, int = 0, float = 0);
	void print();
	~Circle();
};

