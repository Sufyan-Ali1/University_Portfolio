#include<iostream>
using namespace std;
void fillwithmean(float in[], float out[], int n, int size) {
	int leftsum = 0, rightsum = 0;
	int terms = n * 2 + 1;
	for (int i = 0; i < size; i++) {
		rightsum = 0;
		leftsum = 0;
		for (int j = i; j <= i +( terms / 2)&&j<size; j++) {
			rightsum += in[j];
		}
		for (int j = i; j > i - terms / 2 && j > 0; j--) {
			leftsum += in[j - 1];
		}
		out[i] = (leftsum + rightsum) / terms;
	}
	for (int i = 0; i < size; i++) {
		cout << out[i] << " ";
	}
}
void main() {
	float in[10];
	float out[10];
	int n;
	int size = 10;
	cout << "Enter array\n";
	for (int i = 0; i < size; i++) {
		cin >> in[i];
	}
	cout << "Enter n";
	cin >> n;
	fillwithmean(in, out, n, size);
}