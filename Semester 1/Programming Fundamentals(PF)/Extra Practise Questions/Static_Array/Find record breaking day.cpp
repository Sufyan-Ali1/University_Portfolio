#include<iostream>
using namespace std;
void main() {
	int arr[8];
	int size = 8;
	int check = 0;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	int index = -1, prmax = INT_MIN, max = INT_MIN, no = 0;

	for (int i = 0; i < size; i++) {
		check = 0;
		
			if (i == 0) {
				if (arr[i] > arr[i + 1]) {
					prmax = arr[i];
					index = i;
					no++;
					check = 1;
				}
			}
			else if (i == size - 1) {
				if (arr[i] > prmax) {
					prmax = arr[i];
					index = i;
					no++;
					check = 1;
				}
			}
			else {
				if (arr[i] > prmax) {
					if (arr[i] > arr[i + 1]) {
						prmax = arr[i];
						index = i;
						no++;
						check = 1;
					}
					
				}
				
			}
		
		if(check==1)
		cout << "record break number is " << prmax << " index is " << index << endl;;
	}
	cout << " total record break number is " << no;
}