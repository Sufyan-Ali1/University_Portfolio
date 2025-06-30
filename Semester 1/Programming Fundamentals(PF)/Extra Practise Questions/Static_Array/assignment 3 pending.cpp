#include<iostream>
using namespace std;
int unionof(int array1[], int array2[], int size) {
	int uniona[20];
	int b = 0;
	int siz = size;
	for (int i = 0; i < size; i++) {
		for (int j = 1 + i; j < size; j++) {
			if (array1[i] == array1[j]) {
				for (int k = j; k < size; k++) {
					array1[k] = array1[k + 1];
				}
				size--;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		cout << array1[i]<<" ";
	}
	for (int i = 0; i < siz; i++) {
		for (int j = 1 + i; j < siz; j++) {
			if (array2[i] == array2[j]) {
				for (int k = j; k < siz; k++) {
					array2[k] = array2[k + 1];
				}
				siz--;
			}
		}
	}
	for (int i = 0; i < siz; i++) {
		cout << array2[i] << " ";
	}
	return 0;
}

//int intersectionof(int array1[], int array2[], int size) {

//}

void main() {
	int arr1[10];
	int arr2[10];
	cout << "Enter the 1st array of 10 elements\n";
	for (int i = 0; i < 10; i++) {
		cin >> arr1[i];
	}
	cout << "Enter the 2nd array of 10 elements\n";
	for (int i = 0; i < 10; i++) {
		cin >> arr2[i];
	}
	unionof(arr1, arr2, 10);
	//intersectionof(arr1, arr2, 10);
}