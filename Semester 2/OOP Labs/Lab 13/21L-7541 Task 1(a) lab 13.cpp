#include<iostream>
using namespace std;
template<typename T>
T range(T** array, int rows, int col) {
	T a;
	T b;
	a = array[0][0];
	b = array[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < col; j++) {
			if (array[i][j] > a) {
				a = array[i][j];
			}
			if (b > array[i][j]) {
				b = array[i][j];
			}
		}
	}
	return ((a - b) / 4) + b;
}
void main() {
	int a = 5, b = 5;

	int** arr;
	arr = new int* [a];
	for (int i = 0; i < a; i++) {
		arr[i] = new int[b];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][j] = i + j;
		}
	}
	int x = range(arr, a, b);
	cout << x;
}