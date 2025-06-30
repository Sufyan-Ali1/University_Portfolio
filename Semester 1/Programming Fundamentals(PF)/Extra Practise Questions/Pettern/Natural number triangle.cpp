#include<iostream>
using namespace std;
void main() {
	cout << "enter height \n";
	int h;
	cin >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << " ";
		}
		cout << endl;
	}
}