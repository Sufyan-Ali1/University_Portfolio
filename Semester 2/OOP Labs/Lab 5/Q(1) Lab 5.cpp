#include<iostream>
using namespace std;
void rotateOuterLayer(int** arr, const int& size) {
	int a;
	a = arr[0][0];
	for (int i = 0; i < size-1; i++) {
			arr[0][i] = arr[0][i + 1];
		
	}
	int newc = arr[1][0];

	for (int i = 1; i < size; i++) {
		arr[i][0] = a;
		a = newc;
		if (i == size - 1) {
			newc = arr[i][1];
		}
		else{
			newc = arr[i + 1][0];
		}
	
	}
	
	for (int i = 1; i < size ; i++) {
		arr[size - 1][i] = a;
		a = newc;
		if (i == size - 1) {
			newc = arr[size-2][size-1];
		}
		else {
			newc = arr[size-1][i+1];
		}
	}
	
	for (int i = size - 2; i >= 0; i--) {
		arr[i][size - 1] = a;
		a = newc;
		if(i!=0)
		newc = arr[i-1][size-1];
		
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j]<<"\t";

		}
		cout << endl;
	}
	
}
int main() {
	int** arry;
	cout << "Enter the size of Square Matrix\n";
	int size;
	cin >> size;
	arry = new int* [size];
	for (int i = 0; i < size;i++) {
		arry[i] = new int[size];

	}
	cout << "Enter elements of array\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> arry[i][j];
		}
	}
	rotateOuterLayer(arry, size);

		return 0;

}