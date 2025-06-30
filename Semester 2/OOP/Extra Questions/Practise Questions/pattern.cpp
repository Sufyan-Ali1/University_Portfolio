#include<iostream>
using namespace std;
void main() {
	cout << "Enter highest number of pattern\n";
	int n;
	cin >> n;
	int size = (2 * n) - 1;
	int l = n;
	int count = 0;
	for (int i = 0; i < n; i++) {
		l = n;
		count = 0;
		for (int j = 0; j < size; j++) {
			if (i == 0 || j == 0 || j == size - 1) {
				//cout << 'a' << " ";
				cout << n<<" ";
			}
			else {
				if (i >= j) {
					l--;
				}
				if (i <= j) {
					count ++;
				}
				if (count >= (l * 2) - 1) {
					l++;
				}
				//cout << 'b' << " ";
				cout << l<<" ";
			}
		}
		cout << endl;
	}
}