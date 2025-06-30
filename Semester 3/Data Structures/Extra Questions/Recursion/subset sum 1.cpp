#include<iostream>
#include<vector>
using namespace std;
void f(int ind, int arr[],  int n,int sum) {
	if (ind == n) {
		cout << sum << " ";
		return;
	}
	//sd.push_back(arr[ind]);
	f(ind + 1, arr, n, sum);

	f(ind + 1, arr, n, sum + arr[ind]);
	//sd.pop_back();
	
}
void main() {
	int arr[] = { 2,3 };
	int n = 2;
	f(0, arr,  n, 0);
}