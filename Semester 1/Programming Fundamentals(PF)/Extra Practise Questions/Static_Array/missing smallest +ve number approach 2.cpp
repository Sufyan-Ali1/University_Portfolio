#include<iostream>
using namespace std;
void main() {

	int arr[10];

	cout << "Enter array of 10 elements including zero\n";

	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	const int N = 1e6;
	bool arry[1000000];

	for (int i = 0; i < N; i++) {
		arry[i] = 0;
	}

	for (int i = 0; i < 10; i++) {
		if (arr[i] >= 0) {
			arry[arr[i]] = 1;
		}
	}
	int ans = -1;
	for (int i = 0; i < 10; i++) {
		if (arry[i] == 0) {
			ans = i;
			i = 12;
		}
	}
	cout << endl<<ans;
}