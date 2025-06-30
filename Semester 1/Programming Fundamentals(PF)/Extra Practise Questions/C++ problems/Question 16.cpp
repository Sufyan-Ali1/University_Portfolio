#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void main() {
	int guessnumber, num, diff,count=1;
	bool istrue=false;
	srand(time(0));
	num = rand() % 100;
	cout << "You have 5 chance to Guess number between 1 and 100\nGuess ";
	cin >> guessnumber;
	while (!istrue) {
		diff = num - guessnumber;
		if (diff == 0) {
			cout << "You Win\n";
			istrue = true;
		}
		else if (num > guessnumber) {
			if (diff >= 50) {
				cout << "Your guess is very Low Try again\n";
			}
			else if (diff >= 30 && diff < 50) {
				cout << "Your guess is Low Try again\n";
			}
			else if (diff >= 15 && diff < 30) {
				cout << "Your guess is moderately Low Try again\n";
			}
			else if (diff >= 0 && diff < 15) {
				cout << "Your guess is somewhat Low Try again\n";
			}

		}
		else if (num < guessnumber) {
			diff = -1 * diff;
				if (diff >= 50) {
					cout << "Your guess is very High Try again\n";
				}
				else if (diff >= 30 && diff < 50) {
					cout << "Your guess is High Try again\n";
				}
				else if (diff >= 15 && diff < 30) {
					cout << "Your guess is moderately High Try again\n";
				}
				else if (diff >= 0 && diff < 15) {
					cout << "Your guess is somewhat High Try again\n";
				}

		}
		cin >> guessnumber;
		if (count >=4) {
			cout << "you lose\n\a";
			istrue = true;
		}
		count++;
	}

}