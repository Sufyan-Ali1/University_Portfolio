#include<iostream>
using namespace std;
void main() {
	int arr[3][3],arr1[3][2],c[3][2];
	int i = 3, j = 3, l = 2;
	cout << "Enter 1st array of 3x3\n";
	for (int k = 0; k < i; k++) {
		for (int m = 0; m < j; m++) {
			cin >> arr[k][m];
		}
	}
	cout << "Enter 2nd array of 3x2\n";
	for (int k = 0; k < j; k++) {
		for (int m = 0; m < l; m++) {
			cin >> arr1[k][m];
		}
	}
	for (int m = 0; m < i; m++) {
		for (int n = 0; n < l; n++) {
			c[m][n] = 0;
			for (int o = 0; o < j; o++) {
				c[m][n] = c[m][n] + arr[m][o] * arr1[o][n];
			}
		}
	}
	cout << "Multiplication of 1st and 2nd array is\n";
	for (int k = 0; k < j; k++) {
		for (int m = 0; m < l; m++) {
			cout<< c[k][m]<<" ";
		}
		cout << endl;
	}

}