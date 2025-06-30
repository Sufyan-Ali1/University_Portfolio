#include<iostream>
using namespace std;
int binarysearch(int arr[], int key,int n) {
	int s = 0;
	int e = n-1 ;
	int check = 0;
	int index = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] == key) {
			check=1;
			index = mid;
			break;
		}
		else if (arr[mid] > key) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	if (check) {
		cout << "Index is " << index<<endl;
	}
	else {
		cout << "not found\n";
	}
	return 0;
}
void main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	int key;
	cin >> key;
	binarysearch(arr, key,10);
}