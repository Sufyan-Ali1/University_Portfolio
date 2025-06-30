#include<iostream>
#include<vector>
using namespace std;
void f(int arr[], vector<int> ds, int map[], int n, int ind) {
	//cout << ds.size() << endl;
	if (ds.size() == n) {
		for (auto it : ds) {
			cout << it<<" ";
			
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (map[i] == 0) {
			ds.push_back(arr[i]);
			map[i] = 1;
			f(arr, ds, map, n, i + 1);
			ds.pop_back();
			map[i] = 0;
		}
		
		//if (sizeof(ds) == n - 1&&x!=n)i = 0;
	}
}
void main() {
	int arr[] = { 1,2,3 };
	vector<int>ds;
	int n = 3;
	int map[] = { 0,0,0 };
	f(arr, ds, map, n, 0);
}