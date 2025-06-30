#include<iostream>
using namespace std;
void main() {
	int h;
	cout << "Enter the height\n";
	cin >> h;
	int space = h - 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= space; j++) {
			cout << " ";
		}
		space--;
		for (int j = 1; j <= i; j++) {
			if (j == 1||j==i||i==h) {
				cout << "* ";
			}
			else if (j > 1 && j < i) {
				cout << "  ";
			}

		}
		cout << endl;
	}
	space = h - 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= space; j++) {
			cout << " ";
		}
		space--;
		for (int j = 1; j <= i; j++) {
						cout << "* ";
		}
		cout << endl;

	}

}