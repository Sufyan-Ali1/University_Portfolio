#include<iostream>
using namespace std;
void f(int ind, int n, int arr[]) {
	if (ind == n) {
		for (int i = 0; i < n;i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = ind; i < n; i++) {
		swap(arr[ind], arr[i]);
		f(ind + 1, n, arr);
		swap(arr[ind], arr[i]);
	}
}
void main() {
	int arr[] = { 1,2,3 };
	int n = 3;
	f(0, n, arr);
}