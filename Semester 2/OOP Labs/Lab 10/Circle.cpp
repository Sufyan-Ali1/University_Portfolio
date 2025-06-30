#include "Circle.h"
//#include"Point.h"
#include<iostream>
using namespace std;
Circle::Circle(int a, int b, float c):Point(a,b){
	rad= c;
	cout << "Circle() Called\n";
}
void Circle::print() {
	cout << "Center ";
	Point::print();
	
	cout << "Radius is " << rad << endl;
}
Circle::~Circle() {
	cout << "~Circle() Called\n";
}