/*Assignment
Name: Sufyan Ali
 Roll No :21L-7541*/
#include<iostream>
using namespace std;
int main() {
	float a, b;
	cout << "please enter two numbers" << endl;
	cout << "before swap a is " << endl;
	cin >> a;//Let a=5
	cout << "before swap b is " << endl;
	cin >> b;//Let b=6
	a = a + b;//5+6=11
	b = a - b;//11-6=5
	a = a - b;//11-5=6
	cout << "after swap a is "<< endl << a << endl;
	cout << "after swap b is " << endl << b << endl;
}
