#include<iostream>
using namespace std;
void main() {
	int arr[10];
	cout << "Enter 1D array of 10 elements one element should zero\n";
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];

	}
	int i = 1;
	for (int j = 0; j < 10;j++) {
		if (arr[j] == i) {
			i++;
			j = 0;
		}
	}
	cout << "Smallest positive missing number in the array is\t" << i;
}