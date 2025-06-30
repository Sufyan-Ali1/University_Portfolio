#include<iostream>
using namespace std;
int input(int a[], int b) {
	for (int i = 0 ; i < b; i++) {
		cin >> a[i];
	}
	return 0;
}
int search(int b[],int c, int d){
	int index = 0;
	int f = index;
	for (int i = 0; i < c; i++) {
		if (b[i] == d) {
			index++;
			cout << "Number is found";
			cout << " at " << i << endl;
		}
		
	}
	
    if(index== f){
		cout << "Number is not found\n";
	}
	return 0;
}
void main() {

	int arr[6] = { 3, 5 ,4, 8, 5,2 };
	
	int k;
	cout << "Enter number for search\n";
	cin >> k;
	search(arr, 6,k);

}