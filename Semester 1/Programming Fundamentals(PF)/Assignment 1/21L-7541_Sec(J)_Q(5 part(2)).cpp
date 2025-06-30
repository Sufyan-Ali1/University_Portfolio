/*Assignment
Name: Sufyan Ali
Roll No: 21L-7541*/
#include<iostream>
using namespace std;
void main()
{
	float a, b;
	cout << "Please enter two numbers"<<endl ;
	cout << "before swap a = ";
	cin >> a;
	cout << "before swap b = ";
	cin >> b;
	a = a * b; //ex: a=9 b=8 (9*8=72)
	b = a / b;//(72/8=9)
	a = a / b;//(72/9=8)
	cout << "after swap a =" << a << endl;
	cout << "after swap b =" << b << endl;
}