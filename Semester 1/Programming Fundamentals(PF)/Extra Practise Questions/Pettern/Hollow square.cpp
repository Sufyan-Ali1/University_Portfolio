#include<iostream>
using namespace std;
void main() {
	cout << "Enter the height of square\n";
	int h;
	cin >> h;
	for (int j = 1; j <= h; j++) {
		cout << "* ";
	}
	cout << endl;
			for (int k = 1; k <= h - 2;k++) {
			cout << "*";
			for (int space = 1; space <= h - 2; space++) {
				cout << "  ";
			}
			cout << " *";
			cout << endl;
		}
	for (int j = 1; j <= h; j++) {
		cout << "* ";
	}
	cout << endl;


}