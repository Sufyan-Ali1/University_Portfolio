#include<iostream>
using namespace std;
int input(int arr[],int n) {
	cout << "enter twenty integer\n";
	int i = 0;
	while (i < n) {
		cin >> arr[i];
		i++;
	}
	return 0;
}
void main() {
	int arr[20];
	int pos=0, neg=0, zero=0, even=0, odd=0;
	input(arr, 20);
	for (int i = 0; i < 20; i++) {
		if (arr[i] > 0) {
			pos++;
		}
		else if (arr[i] < 0) {
			neg++;
		}
		else if (arr[i] == 0) {
			zero++;
		}

		if (arr[i] %2 == 0) {
			even++;
		}
		else if (arr[i] % 2 != 0) {
			odd++;
		}
	}
	cout << "Number of even  numbers"<<even<<endl;
	cout << "Number of odd  numbers" << odd<<endl;
	cout << "Number of zero  numbers" << zero<<endl;
	cout << "Number of positive  numbers" << pos<<endl;
	cout << "Number of negative  numbers" << neg<<endl;

}