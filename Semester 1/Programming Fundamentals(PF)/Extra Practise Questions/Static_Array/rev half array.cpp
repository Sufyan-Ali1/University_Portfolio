#include<iostream>
using namespace std;
bool isbool(int arr[], int siz, int ind) {
	int b = ind % 2;
	
	for (int i = 0; i <= ind;i++) {
		int temp = arr[i];
		arr[i] = arr[ind];
		arr[ind] = temp;
		ind--;
		}
	for (int i = 0; i < siz; i++) {
		cout << arr[i] << " ";
	}
	return true;
	}

void main() {
	int arr[8];
	int size = 8;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		
	}
	cout << "Enter the index you want to rev\n";
	int index;
	cin >> index;
	isbool(arr, size, index);
}