#include<iostream>
using namespace std;
void main() {
	cout << "Enter 8 didgit\n";
	int n[8],sum=0,product=1;
	for (int i = 0; i < 8; i++) {
		cin >> n[i];
		sum = sum + n[i];
		product = product * n[i];
	}
	cout << "Sum of 8 digits is " << sum << endl;
	cout << "product of 8 digits is " << product << endl;


}