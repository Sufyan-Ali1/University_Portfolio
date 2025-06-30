#include<iostream>
#include<vector>
using namespace std;
void f(int ind, int arr[], vector<int>& ds, int n, int k,int sum) {
	if (ind == n) {
		
		if (k == 0) {
			
			for (auto it : ds) {
				cout << it << " ";
			}
			if (ds.size() == 0) {
				cout << "{}";
			}
			cout << endl;
			
		}
		return;
	}
	
	
	
	if (k >= arr[ind]) {
		ds.push_back(arr[ind]);
		k = k - arr[ind];
		f(ind, arr, ds, n, k, sum);
		ds.pop_back();
		k = k + arr[ind];
	}
	
	
	f(ind + 1, arr, ds, n, k, sum);
	
}
void main() {
	int arr[] = { 2,4,1,3,5 };
	int n = 5;
	vector<int>ds;
	int k;
	cout << "enter\n";
	cin >> k;
	f(0, arr, ds, n, k,0);
}