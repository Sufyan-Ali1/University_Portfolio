#include<iostream>
using namespace std;
void main() {
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

		for (int j = 1; j <= 2*i-1; j++) {
			if (j <= i) {
				cout << k<<" ";
				if (j < i) {
					k++;
				}
			}
						else {
				k--;
				cout << k<<" ";
			}
		}
		cout << endl;
	}
}