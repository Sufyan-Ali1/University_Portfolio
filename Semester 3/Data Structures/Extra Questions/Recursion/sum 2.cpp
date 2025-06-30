#include<iostream>
#include<vector>
using namespace std;
void f(int ind, int arr[], vector<int>& ds, int tar, int n) {
	if (tar == 0) {
		for (auto it : ds) {
			cout << it << " ";
		}
		cout << endl;
		return;
	}
		
	for (int i = ind ; i < n; i++) {
		if (arr[i] == arr[i - 1]&& i>ind  )continue;
			if (arr[ind] > tar) {
				break;
			}
			
			ds.push_back(arr[i]);
			
			f(i + 1, arr, ds, tar-arr[i], n);
		
			ds.pop_back();
	}
}
void main() {
	int arr[] = { 1,1,2,2,4 };
	int n = 5;
	vector<int>ds;
	f(0, arr, ds, 4, n);
}