#include<iostream>
using namespace std;
void main() {
	int max1 = INT_MIN;
	int max2 = INT_MIN;
	int arr[7];
	int index1 = -1;
	int index2 = -1;
	cout << "Enter array of 6 size\n";
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
		if (arr[i]>max1 ) {
			max1 = arr[i];
			index1 = i;
		}

	}
	for (int i = 0; i < 6; i++) {
		if (arr[i] > max2 && arr[i] < max1) {
			max2 = arr[i];
			index2 = i;

		}
	}
	
	for (int i = 6; i >index1; i--) {
		arr[i] = arr[i - 1];
	}
	arr[index1 + 1] = arr[index1] - arr[index2];
	arr[index1] = arr[index2];
	

	for (int i = 0; i <= 6; i++) {
		cout << arr[i]<<" ";
	}

}