#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void main() {
	int guessnumber, num, count = 1;
	bool istrue = false;
	srand(time(0));
	num = rand() % 100;
	cout << "Guess a number b/w 1 and 100\n";
	cin >> guessnumber;
	while (!istrue) {
		if (num == guessnumber) {
			cout << " you win \n";
			istrue = true;
		}
		else if (num < guessnumber) {
			cout << "Your number is greater Try again\n";
		}
		else if (num > guessnumber) {
			cout << "Your number is smaller Try again\n";
		}
		cin >> guessnumber;
		if (count >= 4) {
			cout << "you lose\n";
			istrue = true;
		}

		count++;
	}

}