#include<iostream>
using namespace std;
template<typename T>
T shift(T** arry, int rows, int col) {
	T a;
	T b;
	int j;
	cout << "Before shift\n";
	for (int i = 0; i < rows; i++) {

		for (j = 0; j < col ; j++) {
			cout << arry[i][j] << " ";
		}
		cout << endl;
	}
	cout << "After shift\n";
	for (int i = 0; i < rows; i++) {
		T temp = arry[i][col-1];
		for (j = col - 1; j > 0; j--) {
			arry[i][j] = arry[i][j-1];
		}
		arry[i][j] = temp;
	}
	
	for (int i = 0; i < rows; i++) {
	
		for (j = 0; j < col ; j++) {
			cout << arry[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
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
    shift(arr, a, b);

}