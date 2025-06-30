#include<iostream>
#include<vector>
using namespace std;

void f(int ind, int arr[], vector<int> ds, int sum, int n) {
	//if (ind == n) {
		cout << sum << " ";
		//return;
	//}
	 
	for (int i = ind; i < n; i++) {
		if (arr[i] == arr[i - 1] && ind < i)continue;
		f(i + 1, arr, ds, sum + arr[i], n);

			//f(i + 1, arr, ds, sum , n);
	}
}
void main() {
	int arr[] = { 1,1,3 };
	int n = 3;
	vector<int> ds;
	f(0, arr, ds, 0, n);
}