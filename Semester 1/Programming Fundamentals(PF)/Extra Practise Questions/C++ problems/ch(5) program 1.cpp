#include<iostream>
using namespace std;
void main() {
	int num, digit, a = 1, i = 1,d,sum=0;
	cout << "how many digit number you want to input\n";
	cin >> digit;
	cout << "Enter a number\n";
	cin >> num;
	while (digit >= a) {
		i = i * 10;
		a++;

	}
	i = i / 10;
	
	while (i > 0) {
		d = num / i;
		num = num % i;
		cout << d<<"  ";
		i = i / 10;
		sum = sum + d;

	}
	cout << endl;
	cout << sum;
}