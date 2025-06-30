#include<iostream>
using namespace std;
void main() {
	int arr[10];
	cout << "Enter 1D array of 10 elements\n";
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	int count = 1;
	int rsum;
	int stpoint = -1, no = 0;
	int sum = 0, enpoint=-1;
	cout << "Enter given sum\n";
	cin >> rsum;
	
		stpoint = 0;
		int i = 0;
		for (int j = 0 ; j < 10 && count; j++) {
			sum = sum + arr[j];
			no++;
			if (sum > rsum) {            
				sum = 0; 
				no = 0;
				j = ++i-1;
				stpoint = i;			
			}
			else if (sum == rsum) {
				count = 0;
				enpoint = j;
			}
		}
		if (count == 0) {
			cout << "\nstarting point is " << stpoint << " and ending point is " << enpoint << endl;;
		for (int i = 0; i < no; i++) {
			cout << arr[stpoint]<<" ";
			stpoint++;
		}
		
	    }
}