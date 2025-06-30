#include<iostream>
using namespace std;

int unionof(int array1[], int array2[], int& size1, int& size2) {
	int uniona[20];
	int b = 0; //elements present in union array

	for (int i = 0; i < size1; i++) {
		uniona[i] = array1[i];
		b++;
	}
	for (int i = 0; i < size2; i++) {
		int count = 0;
		for (int j = 0; j < size1; j++) {
			if (array2[i] == array1[j]) {
				count++;
			}
		}
		if (count == 0) {
			uniona[b] = array2[i];
			b++;
		}
	}
	for (int i = 0; i < b - 1; i++) {//for sort the array of union
		for (int j = i + 1; j < b; j++) {
			if (uniona[i] > uniona[j]) {
				int temp = uniona[i];
				uniona[i] = uniona[j];
				uniona[j] = temp;
			}
		}
	}
	cout << "union of Array is\n";
	for (int i = 0; i < b; i++) {
		cout << uniona[i] << " ";
	}
	cout << endl;
	return 0;
}

int intersectionof(int array1[], int array2[], int size1, int size2) {
	int intersectiona[20];
	int b = 0;//elemrnts present in intersection array

	for (int i = 0; i < size2; i++) {
		for (int j = 0; j < size1; j++) {
			if (array2[i] == array1[j]) {
				intersectiona[b] = array2[i];
				b++;
			}
		}
	}

	for (int i = 0; i < b - 1; i++) {//for sort the array of intersection
		for (int j = i + 1; j < b; j++) {
			if (intersectiona[i] > intersectiona[j]) {
				int temp = intersectiona[i];
				intersectiona[i] = intersectiona[j];
				intersectiona[j] = temp;
			}
		}
	}

	cout << "Intersection of Array is\n";
	for (int i = 0; i < b; i++) {
		cout << intersectiona[i] << " ";

	}
	return 0;
}

void main() {
	int arr1[10];
	int arr2[10];
	int size = 10;
	cout << "Enter the 1st array of 10 elements\n";
	for (int i = 0; i < 10; i++) {
		cin >> arr1[i];
	}
	cout << "Enter the 2nd array of 10 elements\n";
	for (int i = 0; i < 10; i++) {
		cin >> arr2[i];
	}

	int size1 = size;//entities present in 1st array
	int size2 = size;//entities present in 2nd array

	for (int i = 0; i < size1; i++) {// for making 1st array distnict if it has any entry more than one
		for (int j = 1 + i; j < size1; j++) {
			if (arr1[i] == arr1[j]) {
				for (int k = j; k < size1; k++) {
					arr1[k] = arr1[k + 1];
				}
				j--;
				size1--;
			}
			
		}
	}

	for (int i = 0; i < size2; i++) {// for making 2nd array distnict if it has any entry more than one
		for (int j = 1 + i; j < size2; j++) {
			if (arr2[i] == arr2[j]) {
				for (int k = j; k < size2; k++) {
					arr2[k] = arr2[k + 1];
				}
				size2--;
				j--;
			}
			
		}
	}
	for (int i = 0; i < size1; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size2; i++) {
		cout << arr2[i] << " ";
	}

	unionof(arr1, arr2, size1, size2);
	intersectionof(arr1, arr2, size1, size2);
}