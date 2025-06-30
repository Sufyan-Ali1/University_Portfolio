#include<iostream>
using namespace std;
void main() {
	int arr[7];
	for (int i = 0; i < 7; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 7; i++) {
		int current = 0;
		for (int j = i; j < 7; j++) {
			current += arr[j];
			cout << current << endl;
		}
	}
}