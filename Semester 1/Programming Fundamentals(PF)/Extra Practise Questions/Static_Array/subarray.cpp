#include<iostream>
using namespace std;
void main() {
	cout << "enter a sentence\n";
	char a[30];
	cin.getline(a, 30);
	char b[10];
	int count;
	cout << "which word you want to find\n";
	cin.getline(b, 10);
	for (count = 0; b[count] != '\0'; count++) {

	}
	
	bool A = false;
	int i = 0, j = 0, st = 0, maxst = 0, check = 0,count1=0;
	while (!A) {
		if (a[i] != ' ' && a[i] != '\0') {
			if (a[i] == b[j]) {
				j++;
				check = 1;
				count1++;
			}
			else {
				for (i; a[i] != ' ' && a[i] != '\0'; i++) {
					check = 0;
				}
				i--;
			}
		}
		else {
			if (check == 1) {
				maxst = st;
				if(count==count1)
				A = true;
			}
			else if (a[i] == '\0') {
				maxst = -1;
				A = true;
			}
			else {
				j = 0;
				count1 = 0;
				st = i + 1;
			}
		}
		
		i++;
	}

	cout << "starting " << maxst<<" ";
	if (maxst == -1) {
		cout << "Not any subarray exist\n";
	}
	else {
		for (int i = 0; i < count1; i++) {
			cout << a[i + maxst];
		}
		cout << endl;
	}
}