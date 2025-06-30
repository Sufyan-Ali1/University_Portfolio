/*Assignment 
Name :Sufyan Ali
Roll No :21L-7541*/

#include<iostream>
using namespace std;
void main() {
	cout << "Enter quantity of unit that you buy "<<endl;// 1 unit=100
	int a,b,c;// a is quantity of unit, b is amount of quanity ,c is amout after discount
	cin >> a;
	b = a * 100;
	if (a > 10) {
		c = b - 10 * (b / 100);
		cout << "Total amount after discount is " << c<<endl ;

	}
	else {
		cout << "Total amount " << b << endl;

	}
}