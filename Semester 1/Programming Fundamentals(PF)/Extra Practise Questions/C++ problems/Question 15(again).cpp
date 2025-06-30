#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void main() {
	int guessnumber, num, count = 1;
	srand(time(0));
	num = rand() % 100;
	cout << "You have 5 chance to Guess a number b/w 1 and 100 \nGUESS ";
	cin >> guessnumber;
	while (count < 5) {
		if (num == guessnumber) {
			cout << " you win \n";
			break;
		}
		
		if (num < guessnumber) {
			cout << "Your number is greater Try again\n";
		}
		else if (num > guessnumber) {
			cout << "Your number is smaller Try again\n";
		}
		cin >> guessnumber;
		if (count == 4) {
			cout << "You Lose\n";
		}
		count++;
	}
}