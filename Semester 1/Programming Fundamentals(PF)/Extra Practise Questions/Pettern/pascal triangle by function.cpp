#include<iostream>
using namespace std;
int factorial(int num) {
	int factor = 1;
	for (int i = 1; i <= num; i++) {
		factor = factor * i;
	}
	return factor;
}
void main() {
	cout << "Enter the height of triangle\n";
	int h;
	cin >> h;
	int space = h - 1;
	for (int i = 0; i < h; i++) {
		for (int spc = 1; spc <= space; spc++) {
			cout << " ";
		}
		space--;
		for (int j = 0; j <= i; j++) {
			cout << factorial(i) / (factorial(j) * factorial(i - j)) << " ";
		}
		cout << endl;
	}
}