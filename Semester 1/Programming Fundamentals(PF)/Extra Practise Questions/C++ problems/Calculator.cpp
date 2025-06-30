#include<iostream>
using namespace std;
void main() {
	cout << "Choose which operation you want to perform\n";
	cout << "+.Addition\n" << "-.Subtraction\n" << "*.Multiplication\n" << "/.Division\n" << "P.Power\n" << "S.Square root\n" << "C.Cube root\n\n";
	
	char op;
	cout << "Operation = ";
	cin >> op;
	
	if(op =='+'){
		cout << "Please enter two numbers\n";
		double a, b;
		cout << "Num 1 = ";
		cin >> a;
		cout << "Num 2 = ";
		cin >> b;
		double c;


		c = a + b;
		cout << "Addition of these two numbers is " << c << endl;
	}

	else if (op == '-') {
		cout << "Please enter two numbers\n";
		double a, b;
		cout << "Num 1 = ";
		cin >> a;
		cout << "Num 2 = ";
		cin >> b;
		double c;
    	c = a - b;
		cout << "Subtraction of these two numbers is " << c << endl;
	}
	else if (op == '*') {
		cout << "Please enter two numbers\n";
		double a, b;
		cout << "Num 1 = ";
		cin >> a;
		cout << "Num 2 = ";
		cin >> b;
		double c;
		c = a - b;
		cout << "Multiplication of these two numbers is " << c << endl;
	}
	else if (op == '/') {
		cout << "Please enter two numbers\n";
		double a, b;
		cout << "Num 1 = ";
		cin >> a;
		cout << "Num 2 = ";
		cin >> b;
		double c;
		c = a / b;
		cout << "Division of these two numbers is " << c << endl;
	}
	else if (op == 'S') {
		cout << "Please enter number\n";
		double a;
		cout << "Num = ";
		cin >> a;
	
	
		cout << "Square root of Num = " << sqrt(a) << endl;
	}
	else if (op == 'P') {
		cout << "Please enter number\n";
		double a,x;
		cout << "Num = ";
		cin >> a;
		cout << "Power = ";
		cin >> x;

		cout << "power of Num " << a << " is " << pow(a, x) << endl;
	}
	else if (op == 'C') {
		cout << "Please enter number\n";
		double a;
		cout << "Num = ";
		cin >> a;


		cout << "Cube root of Num = " << std::cbrt(a) << endl;
	}

	else {

		cout << "No any function exist please enter from above options\n";
	}
}