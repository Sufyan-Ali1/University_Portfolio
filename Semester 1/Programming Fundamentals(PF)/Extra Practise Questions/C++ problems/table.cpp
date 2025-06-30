#include<iostream>
using namespace std;
void main() {
	cout << "Enter a number for print table\n";
	int a, b = 1,c;
	cin >> a;
	cout << "how many times you want to print table\n";
	cin >> c;
	while (b <= c) {

		cout << a << "*" << b << "=" << a * b<<endl;
		b++;
	}

}