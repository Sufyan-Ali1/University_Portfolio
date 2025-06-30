//#include<iostream>
//#include<vector>
//using namespace std;
//void f(int ind, int arr[], vector<int>& ds, int n, int k) {
//	if (ind == n) {
//		int sum=0;
//		
//		for (auto it : ds) {
//			sum = sum + it;
//		}
//		if (sum == k) {
//			for (auto it : ds) {
//			     cout<<it<<" ";
//			}
//			if (ds.size() == 0) {
//				cout << "{}";
//			}
//			cout << endl;
//		}
//		return;
//	}
//	ds.push_back(arr[ind]);
//	f(ind + 1, arr, ds, n, k);
//	ds.pop_back();
//	f(ind + 1, arr, ds, n, k);
//}
//void main() {
//	int arr[] = { 2,4,1,3,1 };
//	int n = 5;
//	vector<int>ds;
//	int k;
//	cout << "Enter\n";
//	cin >> k;
//	f(0, arr, ds, n, k);
//}
// //------------------------
//#include<iostream>
//#include<vector>
//using namespace std;
//int f(int ind, int arr[], vector<int>& ds, int n, int k,int sum,int x) {
//	if (ind == n) {
//		
//		if (sum == k) {
//			x = 1;
//			for (auto it : ds) {
//				cout << it << " ";
//			}
//			if (ds.size() == 0) {
//				cout << "{}";
//			}
//			cout << endl;
//			return 1;
//		}
//		return 0;
//	}
//	
//	ds.push_back(arr[ind]);
//	
//	sum = sum + arr[ind];
//	if (f(ind + 1, arr, ds, n, k, sum, x)) {
//		return 1;
//	}
//
//	
//	
//	ds.pop_back();
//	sum = sum - arr[ind];
//	if (f(ind + 1, arr, ds, n, k, sum, x)) {
//		return 1;
//	}
//	return 0;
//}
//void main() {
//	int arr[] = { 2,4,1,3,1 };
//	int n = 5;
//	vector<int>ds;
//	int k;
//	cout << "enter\n";
//	cin >> k;
//	f(0, arr, ds, n, k,0,0);
//}
//---------------------------------------------------------
//#include<iostream>
//#include<vector>
//using namespace std;
//void f(int ind, int arr[], vector<int>& ds, int n, int k,int &x) {
//	if (ind == n) {
//		int sum = 0;
//
//		for (auto it : ds) {
//			sum = sum + it;
//		}
//		if (sum == k) {
//			x++;
//			for (auto it : ds) {
//				cout << it << " ";
//			}
//			if (ds.size() == 0) {
//				cout << "{}";
//			}
//			cout << endl;
//		}
//		return;
//	}
//	ds.push_back(arr[ind]);
//	f(ind + 1, arr, ds, n, k,x);
//	ds.pop_back();
//	f(ind + 1, arr, ds, n, k,x);
//}
//void main() {
//	int arr[] = { 2,4,1,3,1 };
//	int n = 5;
//	vector<int>ds;
//	int k;
//	cout << "Enter\n";
//	cin >> k;
//	int x=0;
//	f(0, arr, ds, n, k,x);
//	cout << x << " subsequence\n";
//}
//-----------------------------

#include<iostream>
#include<vector>
using namespace std;
int f(int ind, int arr[], vector<int>& ds, int n, int k, int sum) {
	if (ind == n) {

		if (sum == k) {
			
			return 1;
		}
		return 0;
	}

	ds.push_back(arr[ind]);

	sum = sum + arr[ind];
	int l = f(ind + 1, arr, ds, n, k, sum);
		



	ds.pop_back();
	sum = sum - arr[ind];
	int r=f(ind + 1, arr, ds, n, k, sum);
	return l+r;
}
void main() {
	int arr[] = { 2,4,1,3,1 };
	int n = 5;
	vector<int>ds;
	int k;
	cout << "enter\n";
	cin >> k;
	int x;
	x=f(0, arr, ds, n, k, 0);
	cout << x << " subsequences\n";
}