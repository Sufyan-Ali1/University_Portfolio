#include<iostream>
using namespace std;

int func(int num, int base1, int base2) {
	
	int num1[10], num2[10];
	int a;
	int nm = num;
	int count = 1;
	int len = 0, len1 = 0;


	for (int i = 0; i < 10&& num > 0;i++) {
		a = num % base1;
		num1[i] =  a;
		len++;
		num=num / base1;
	}
	
	for (int i = 0; i < 10 && nm > 0; i++) {
		a = nm % base2;
		num2[i] =  a;
		len1++;
		nm = nm / base2;
	}
	cout << endl;
	for (int i = 0; i < len; i++) {
		cout << num1[i];
	}
	cout << endl;
	for (int i = 0; i < len1; i++) {
		cout << num2[i];
	}
	cout << endl;
	for (int i = 0; i < len--; i++) {
		if (num1[i] != num1[len ]) {
			count = 0;
			
	    }
	}
	if (count) {
		for (int i = 0; i < len1--; i++) {
			if (num2[i] != num2[len1 ]) {
				count = 0;
				
			}
			
		}
		if (count) {
			cout << "\nnumber is macro palindrome\n";
		}
		else {
			cout << "\nnumber is not macro palindrome\n";
		}
	}
	else {
		cout << "\nnumber is not macro palindrome\n";
	}
	
	

	return 0;
}
int main() {
	int num;
	cout << "Enter a number\n";
	cin >> num;
	
	int base1;
	cout << "Enter Base 1: ";
	cin >> base1;
	int base2;
	cout << "Enter Base 2: ";
	cin >> base2;
	func(num, base1, base2);

}