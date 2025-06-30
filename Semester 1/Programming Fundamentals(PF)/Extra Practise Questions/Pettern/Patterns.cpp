#include<iostream>
using namespace std;
int Diamond() {
	cout << "Enter the height\n";
	int h;
	cin >> h;
	int space = h - 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= space; j++) {
			cout << " ";
		}
		space--;
		for (int j = 1; j <= 2 * i - 1; j++) {
			cout << "*";
		}
		cout << endl;
	}

	space = 1;
	for (int i = 1; i < h; i++) {
		for (int j = 1; j <= space; j++) {
			cout << " ";
		}
		space++;
		for (int j = 1; j <= 2 * (h - i) - 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}

int HollowDiamond() {

	cout << "Enter the height\n";
	int h;
	cin >> h;
	int space = h - 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= space; j++) {
			cout << " ";
		}
		space--;
		for (int j = 1; j <= 2 * i - 1; j++) {
			if (j == 1 || j == 2 * i - 1) {
				cout << "*";
			}
			else {
				cout << " ";

			}
		}
		cout << endl;
	}

	space = 1;
	for (int i = 1; i < h; i++) {
		for (int j = 1; j <= space; j++) {
			cout << " ";
		}
		space++;
		for (int j = 1; j <= 2 * (h - i) - 1; j++) {
			if (j == 1 || j == 2 * (h - i) - 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
int HalfDiamond() {
	cout << "Enter the height\n";
	int h;
	cin >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "* ";
		}
		cout << endl;
	}
	for (int i = 1; i < h; i++) {
		for (int j = h; j > i; j--) {
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}
int Pyramid() {
	cout << "Enter the height\n";
	int h;
	cin >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "* ";
		}
		cout << endl;

	}
	return 0;
}
int HollowPyramid() {
	cout << "Enter the height\n";
	int h;
	cin >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i || i == h) {
				cout << "* ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;

	}
	return 0;
}

int HollowSquare() {
	cout << "Enter the height\n";
	int h;
	cin >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= h; j++) {

			if (i == h || j == 1 || j == h || i == 1) {
				cout << "* ";
			}
			else {
				cout << "  ";
			}

		}
		cout << endl;
	}
	return 0;
}
int naturaltriangle() {

	cout << "enter height \n";
	int h;
	cin >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}

int Hollownaturaltriangle() {
	cout << "enter height\n";
	int h;
	cin >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= i; j++) {
			if (j ==1||j==i||i==h) {
				cout << j<<" ";
			}
			else {
				cout<< "  ";
			}
		}
		cout << endl;
	}
	return 0;
}

int palindromepyramid() {
	cout << "Enter the height\n";
	int h;
	cin >> h;
	int space = h - 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= space; j++) {
			cout << "  ";
		}
		space--;
		char k = 'a';

		for (int j = 1; j <= 2 * i - 1; j++) {
			if (j <= i) {
				cout << k << " ";
				if (j < i) {
					k++;
				}
			}
			else {
				k--;
				cout << k << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
int pascaltriangle() {
	cout << "Enter height of triangle";
	int h, factorial = 1, product = 1, product1 = 1, product2 = 1, k, j;
	cin >> h;

	for (int i = 0; i < h; i++) {

		for (int j = 0; j <= i; j++) {
			for (factorial = 1, product = 1; factorial <= i; factorial++) {
				product = product * factorial;
			}
			//cout << product <<" " << endl;
			for (factorial = 1, product1 = 1; factorial <= i - j; factorial++) {
				product1 = product1 * factorial;
			}
			//cout << product1 << endl;

			for (factorial = 1, product2 = 1; factorial <= j; factorial++) {
				product2 = product2 * factorial;
			}
			//cout << product2 << endl;
			cout << (product) / (product1 * product2) << " ";
		}
		cout << endl;
	}
	return 0;
}

void main() {

	cout << "Select what you want to print\n";
	cout << "For Diamond(1)\n" << "For Hollow Diamond(2)\n" << "For Half Diamond(3)\n" << "For Pyramid(4)\n"
		<< "For Hollow Pyramid(5)\n" << "For Hollow Square(6)\n" << "For Natural number Triangle(7)\n"
		<< "For Hollow Natural number Triangle(8)\n"<<"For Palindrome pyramid(9)\n" << "For Pascal Triangle(10)\n";
	int a;
	cin >> a;
	if (a == 1) {
		Diamond();
	}
	else if (a == 2) {
		HollowDiamond();
	}
	else if (a == 3) {
		HalfDiamond();
	}
	else if (a == 4) {
		Pyramid();
	}
	else if (a == 5) {
		HollowPyramid();
	}
	else if (a == 6) {
		HollowSquare();
	}
	else if (a == 7) {
		naturaltriangle();
	}
	else if (a == 8) {
		Hollownaturaltriangle();
	}
	else if (a == 9) {
		palindromepyramid();
	}
	else if (a == 10) {
		pascaltriangle();
	}
}