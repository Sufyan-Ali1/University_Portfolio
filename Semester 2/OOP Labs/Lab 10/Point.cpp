#include "Point.h"
#include<iostream>
using namespace std;
Point::Point(int a, int b) {
	x = a;
	y = b;
	cout << "Point() Called\n";
}
void Point::print() {
	cout << "(" << x << "," << y << ")" << endl;
}
Point::~Point() {
	cout << "~Point() called\n";
}
