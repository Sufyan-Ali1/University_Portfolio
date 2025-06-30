#include<iostream>
using namespace std;
class integer
{
	int arr[10];
public:
	integer();
	friend void lrg(integer);
	friend void small(integer);
	friend void rep(integer);
	friend void srt(integer&);
	~integer();
};
integer::integer() {
	cout << "Enter 10 elements of array\n";
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

}
integer::~integer() {
	for (int i = 0; i < 10; i++) {
		arr[i] = 0;
	}
}
void lrg(integer a) {
	int max = a.arr[0];
	for (int i = 0; i < 10; i++) {
		if (a.arr[i] > max) {
			max = a.arr[i];
		}
	}
	cout << "Largest element in array is: " << max << endl;
}
void small(integer a) {
	int min = a.arr[0];
	for (int i = 0; i < 10; i++) {
		if (a.arr[i] < min) {
			min = a.arr[i];
		}
	}
	cout << "Smallest element in array is: " << min << endl;
}
void rep(integer a) {
	int check = 0;
	int count = 0;
	for (int i = 0; i < 10 - 1; i++) {
		check = 0;
		for (int j = i + 1; j < 10; j++) {
			if (a.arr[i] == a.arr[j]) {
				check = 1;
				a.arr[j] = INT_MIN+i+j;
			}

		}
		if (check) {
			cout << a.arr[i] << " is Repeated element in array\n";
			count++;
		}
		
	}
	if (!count) {
		cout << "There is not any repeating element in array\n";
	}
}
void srt(integer& a) {
	for (int i = 0; i < 10-1; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (a.arr[i] > a.arr[j]) {
				swap(a.arr[i], a.arr[j]);
			}
		}
	}
	cout << "Array after sorting\n";
	for (int i = 0; i < 10; i++) {
		cout << a.arr[i] << " ";
	}
	cout << endl;
}
void main()
{
	integer x;
	lrg(x);
	small(x);
	rep(x);
	srt(x);
}