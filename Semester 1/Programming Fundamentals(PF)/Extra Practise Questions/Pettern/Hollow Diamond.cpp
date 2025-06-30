#include<iostream>
using namespace std;
void main() {
	cout << "Enter the height\n";
	int h;
	cin >> h;
	int space = h-1;
	int k = h;
	int spc = 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= h; j++) {
			if (j <= k) {
				cout << "* ";
			}
			else {
				cout << "  ";
			}
					}
		k--;
			for (int j = 1; j <= h; j++) {
			if (spc <= j) {
				cout << "* ";
			}
			else {
				cout << "  ";
			}
		}
		spc++;
		cout << endl;
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= h; j++) {
			if (j <= i) {
				cout << "* ";
			}
			else {
				cout << "  ";
			}
		}
		for (int j = 1; j <= h; j++) {
			if (j <= space) {
				cout << "  ";
			}
			else {
				cout << "* ";
			}
		}
		space--;
		cout << endl;
    }
}