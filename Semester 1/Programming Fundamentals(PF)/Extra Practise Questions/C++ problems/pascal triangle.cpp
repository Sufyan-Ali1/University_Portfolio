#include<iostream>
using namespace std;
void main() {
	cout << "Enter height of triangle";
	int h, factorial = 1, product = 1, product1 = 1, product2 = 1, k,j=1;
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
			cout << (product) / (product1 * product2)<<" ";
		}
		cout << endl;
	}
}