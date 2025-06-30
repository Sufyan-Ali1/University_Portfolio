// 29 Nov 2021
#include<iostream>
using namespace std;
void main() {
	int h;
	cout << "Enter height of pyramid\n";
		cin >> h;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= i; j++) {
				cout << "* ";
			}
			cout << endl;
		}
		for (int i = 1; i < h; h--) {
			for (int j=h; j > 1; j--) {
				cout << "* ";
			}
			cout << endl;
		}
}