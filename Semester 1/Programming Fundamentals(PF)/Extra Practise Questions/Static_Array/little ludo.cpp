#include<iostream>
#include<time.h>
using namespace std;
int main() {
	srand(time(0));
	int y = rand() % 6;
	int z = rand() % 6;
	int a, b;
	if (z == 0)
		z = 6;
	if (y == 0)
		y = 6;
	cout << z << " " << y << endl;
	cout << "Enter two numbers\n";
	cin >> a >> b;
	bool istrue = false;
	while (!istrue) {
		if (a == y && b == z && (a + b) % 2 == 0 || a + b == 3) {
			cout << "you win\n";
			istrue = true;
		}
		else if (a == y && b == z && a + b == 11) {
			cout << "You have lose the game\n";
			istrue = true;
		}
		else if (a == y && b == z && a + b == 5 || a + b == 7 || a + b == 9) {
			cout << "Carry on\n";
			cout << "again enter\n";
			int y = rand() % 6;
			int z = rand() % 6;
			cin >> a >> b;
		}
		else if (a != y || b != z) {
			cout << "invalid dice number\n";
			cout << "Try again\n";
			cin >> a >> b;
		}
	}
	return 0;
}

