#include<iostream>
using namespace std;
int main() {

	int arr[7] = { 2,4,6,8,4,5 };


	cout << "Enter index and number that you add\n";
	int n, b;
	cin >> n;
	cin >> b;
	int i = 0, prev, next;
	while (i <= 6) {
		if (i == n) {
			prev = arr[i];
			arr[i] = b;
		}
		if (i >= n) {
			next = arr[i + 1];
			arr[i + 1] = prev;
			prev = next;
		}
		i++;
	}
	for (int j = 0; j <= 6; j++) {
		cout << arr[j] << " ";
	}
	return 0;

}