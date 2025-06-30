#include<iostream>
using namespace std;
void main() {
	int arr[15];
	int size = 15;
	cout << "Enter 15 number\n";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	cout << "Which number you want to update\n";
	int num;
	cin >> num;
	int num1;
	cout << "updated value\n";
	cin >> num1;
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == num) {
			arr[i] = num1;
			
		}
	}
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}