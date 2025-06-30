#include<iostream>
#include<thread>

using namespace std;
int main() {
	int rowst = 0, colst = 0;
	int arr[5][9];
	int rowend = 5 - 1, colend = 9 - 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}
	while (rowst <= rowend && colst <= colend) {
		for (int i = colst; i <= colend; i++) {
			cout << arr[rowst][i]<<" ";
		}
		rowst++;
		for (int i = rowst; i <= rowend; i++) {
			cout << arr[i][colend]<<" ";
		}
		colend--;
		for (int i = colend; i >= colst; i--) {
			cout << arr[rowend][i]<<" ";
		}
		rowend--;
		for (int i = rowend; i >= rowst; i--) {
			cout << arr[i][colst]<<" ";
		}
		colst++;
	}
}