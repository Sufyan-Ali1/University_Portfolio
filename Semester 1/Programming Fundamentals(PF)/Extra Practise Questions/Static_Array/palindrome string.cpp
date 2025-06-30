#include<iostream>
using namespace std;
void main(){
	char a[30];
	int count = 0;
	cin.getline(a, 30);
	for (int i = 0; a[i] != '\0'; i++) {
		count++;
	}
	int check = 1;
	for (int i = 0; i < count;i++) {
		if (a[i] != a[count - 1 - i]) {
			check = 0;
	    }
	}
	if (check == 1) {
		cout << "the sentence is palindrome\n";
	}
	if (check == 0) {
		cout << "the sentence is not palindrome\n";
	}
	
}