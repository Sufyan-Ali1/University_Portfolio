#include<iostream>
using namespace std;
void main() {
	int factorial = 1,p;
	cout << "Enter a positive number which you want to calculate factorial\n";
	cin >> p;
	if (p < 0) {
		cout << "Error! factorial of negative number does not exist";
	}
	else{
		while (p > 0) {
			factorial = factorial * p;
			p--;
		}
		cout << factorial;
	}
	
}