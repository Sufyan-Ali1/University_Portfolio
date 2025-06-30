#include<iostream>
using namespace std;
void main() {
	char arr[30];
	cin.getline(arr, 30);
	
	int count = 0;
	for (int i = 0; arr[i] != '\0'; i++) {
		count++;
	}
	cout << count << endl;
	int maxst = 0,st = 0;
	int maxlength = 0, currentlength = 0;
	for (int i = 0; 1; i++) {
		if (arr[i] == ' ' || arr[i] == '\0') {
			if (currentlength > maxlength) {
				maxlength = currentlength;
				maxst = st;
			}
			currentlength = 0;
			st = i+1;
		}
		else {
			currentlength++;
		}
		if (arr[i] == '\0') {
			break;
		}
	}
	cout << "Max length " << maxlength<<endl;
	for (int i = 0; i <= maxlength; i++) {
		cout << arr[maxst+i];
	}
}