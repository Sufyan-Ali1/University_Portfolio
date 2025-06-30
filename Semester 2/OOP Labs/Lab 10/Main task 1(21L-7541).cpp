#include<iostream>
#include"Point.h"
#include"Circle.h"
using namespace std;
void main() {
	Circle a(3, 4, 5.67);
	a.print();
}
//Output
// 
//Point() Called
//Circle() Called
//Center(3, 4)
//
//Radius is 5.67
//~Circle() Called
//~Point() called