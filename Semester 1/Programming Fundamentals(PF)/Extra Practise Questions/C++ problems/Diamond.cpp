#include<iostream>
using namespace std;
void main() {
	int space, column, row, j = 1, h;
	cout << "Enter the height of diamond\n";
	cin >> h;
	for (row = 1; h >= row; row++) {
		for (space = 1; space <= h - row; space++) {
			cout << " ";
		}
		for (column = 1; column <= 2 * row - 1; column++) {
			cout << "*";
		}
		cout << endl;

	}

	for (row = 1; h > row; row++) {
		for (space = 1; space <= row; space++) {
			cout << " ";

		}
		for (column = 1; column < 2*(h-row); column++) {
			cout << "*";
		}
		cout << endl;
	}
}