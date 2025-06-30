#include<iostream>
using namespace std;
void main() {
	int arr[5][5];
	int rsize = 5;
	int csize = 5;
	int temp;
	for (int i = 0; i < rsize; i++) {
		for (int j = 0; j < csize; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < rsize; i++) {
		for (int j = i; j < csize; j++) {
			temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
	
	for (int i = 0; i < rsize; i++) {
		int k = csize - 1;
		for (int j = 0; j < k; j++) {
			temp = arr[i][j];
			arr[i][j] = arr[i][k];
			arr[i][k] = temp;
			k--;
		}
	}
	cout << endl;
	for (int i = 0; i < rsize; i++) {
		for (int j = 0; j < csize; j++) {
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
}