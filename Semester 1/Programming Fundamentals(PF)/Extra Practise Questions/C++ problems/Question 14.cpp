#include<iostream>
using namespace std;
void main() {
	cout << "Enter a number\n";
	int x, count = 0, max = 0, pos = 1, position;
	cin >> x;
	while (x > 1) {
		if (max < x) {
			max = x;
			position = pos;
		}
		cout << x << " ";
		if (x % 2 == 0) {
			x = x / 2;
		}
		else {
			x = 3 * x + 1;
		}
		
		count++;
		pos++;
	}
	cout << x;

	cout << "\nx is equal to 1 at " << count << endl;
	cout << "Maximum number in the sequence is " << max << " and its position is " << position << endl;
}
