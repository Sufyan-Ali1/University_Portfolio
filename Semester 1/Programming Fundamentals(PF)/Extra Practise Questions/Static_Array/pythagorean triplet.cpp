#include<iostream>
using namespace std;
bool pythagorean(int a,int b,int c) {
	int max = INT_MIN;
	int x, y;
	if (a > b) {
		if (a > c) {
			max = a;
		}
		else {
			max = c;
		}
	}
	else {
		if (c > b) {
			max = c;
		}
		else {
			max = b;
		}

	}
	if (max == a) {
		x = b;
		y = c;
	}
	else if (max == b) {
		x = a;
		y = c;
	}
	else if (max == c) {
		x = b;
		y = a;
    }
	if (max * max == x * x + y * y) {
		return true;
	}
	else {
		return false;
	}

}
void main() {
	cout << "Enter three numbers\n";
	int a, b, c;
	cin >> a >> b >> c;
	if (pythagorean(a, b, c)) {
		cout << "Pythagorean triplet\n";
	}
	else {
		cout << "Not pythagorean triplet\n";
	}

}