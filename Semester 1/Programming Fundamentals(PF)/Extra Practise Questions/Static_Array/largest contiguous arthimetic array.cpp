#include<iostream>
using namespace std;
void main() {
	int arr[20];
	int size = 20;
	int maxst = 0, st = 0, maxno = 0, no = 0;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	int diff = arr[0] - arr[1];
	
	for (int i = 0; i < size-1; i++) {
		for (int j = i + 1; j < i + 2; j++) {
			if (diff != arr[i] - arr[j]) {
				diff = arr[i] - arr[j];
				
				if (maxno < no) {
					maxno = no;
					maxst = st;
					
				}
				no = 1;
				st = i;
				
				
			}
			else {
				no++;
			}
		}
	}
	if (maxno < no) {
		maxno = no;
		maxst = st;
	}
	for (int i = 0; i < maxno + 1; i++) {
		cout << arr[maxst]<<" ";
		maxst++;
	}
	cout << endl << "Lenth of largest contiguous array is " << maxno + 1;
}