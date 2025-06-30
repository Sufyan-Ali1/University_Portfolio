#include<iostream>
using namespace std;
void main() {
	cout << "Enter  a number for check divisibility by 11\n";
	int num, sum = 0, b = 1,a,c;
	cin >> num;
	c = num;
	while (num > 0) {
		a = num % 10;
		num = num / 10;
		sum = sum + a * b;
		b = b * (-1);
	}
	


	if (sum % 11 == 0) {
		cout  <<c<< " is divisible by 11\n";
	}
	else {
		cout << c << " is not divisible by 11\n";
	}
}