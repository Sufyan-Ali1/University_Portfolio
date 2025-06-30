#include<iostream>
using namespace std;
void main() {
	cout << "Size of array\n";
	int size;
	cin >> size;
	
	int arr[10];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];

	}
	int c = 9;
	int count = 1;
	for (int i = 0; i < c; i++) {
		if (arr[i] != arr[c-1]) {
			count = 0;
			break;
		}
		c--;
		
	}
	if (count == 1) {
		cout << "element are same for start and end\n";
	}
	else {
		cout << "element are not same for start and end\n";
	}

}