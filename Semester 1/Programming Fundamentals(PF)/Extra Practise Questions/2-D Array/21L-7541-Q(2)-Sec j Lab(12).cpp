#include<iostream>
using namespace std;
char reversearray(char arr[][50], int rsize) {
	for (int i = 0; i < rsize; i++) {
		int j = 0;
		for (; arr[i][j] != '\0'; j++);
		for (int k = 0; k < j; k++) {
			char temp = arr[i][j-1];
			arr[i][j-1] = arr[i][k];
			arr[i][k] = temp;
			j--;
		}
	}
	return 0;
}

void main() {
	char arr[4][50];
	int rsize = 4;
	cout << "Enter 4 strings\n";
	for (int i = 0; i < rsize; i++) {
		cout << "Enter " << i + 1 << " string\t";
		cin.getline(arr[i], 50);
    }
	reversearray(arr, rsize);

	for (int i = 0; i < rsize; i++) {
		cout << "Enter " << i + 1 << " reverse string\t";
		cout << arr[i];
		cout << endl;
	}
}