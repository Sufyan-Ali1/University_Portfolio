#include<iostream>
using namespace std;
void main() {
	int arr[10] = { 2,3,4,5,6,5,3,1,4,0 };
	int arrb[5], arrc[5];
	int d = 0;
	for (int i = 0; i < 10; i++) {
		if (i < 5) {
		arrb[i] = arr[i];
	}
		else if(i>=5){
			arrc[d] = arr[i];
			d++;
		}
	}

	for (int i = 0; i < 5; i++) {
		cout << arrb[i] << "  ";
	}
	for (int d = 0; d < 5; d++) {
		cout << arrc[d] << "  ";
	}
}