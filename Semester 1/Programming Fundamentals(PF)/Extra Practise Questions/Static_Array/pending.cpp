#include<iostream>
using namespace std;
void main() {
	cout << "Enter the height\n";
	int h;
	cin >> h;
	int k = h;
	for (int i = 0; i < h; i++) {

		for (int j = 0; j < 2 * h; j++) {
			if (i+j < k) {
				cout << "*";
			}
			else {
				cout << " ";
			}
			if (i+k <=j) {
				cout << "*";
			}
			else {
				cout << " ";
			}
			
			
		}

		cout << endl;
	}

	

}