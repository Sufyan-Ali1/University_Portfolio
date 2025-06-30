#include<iostream>
using namespace std;
void allocatememory(int*& Ar, int size) {
	
	Ar = new int[size];
}
void store(int* ar, int size) {
	cout << "Enter " << size << " elements of row\n";
	for (int i = 0; i < size; i++) {
		cin >> ar[i];
	}
}
void print(int *ar, int size) {
	for (int i = 0; i < size; i++) {
		cout << ar[i]<<" ";
	}
	cout << endl;
}
void main() {
	int** D2;
	int *size;
	size = new int;
	cout << "Enter the number of rows of 2D array\n";
	cin >> *size;
	D2 = new int* [*size];
	for (int i = 0; i < *size; i++) {
		allocatememory(D2[i], i+1);		
	}
	for (int i = 0; i < *size; i++) {
		store(D2[i], i + 1);
	}
	for (int i = 0; i < *size; i++) {
		print(D2[i], i + 1);
	}
	
	for (int i = 0; i < *size; i++) {
		delete[]D2[i];
	}
	delete[]D2;
	delete size;
}