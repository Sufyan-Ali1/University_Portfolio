#include<iostream>
using namespace std;
int main() {
	int* p;
	int* q;

	int size = 0;
	p = new int[size + 1];
	
	int a;
	cin >> a;
	while (a != -1) {
		if (a != -1) {
			p[size] = a;
			size++;
		}
		cin >> a;
		
		if (a != -1) {
			q = new int[size];
			for (int i = 0; i < size; i++) {
				q[i] = p[i];
			}
			delete[]p;
			p = new int[size + 1];
			for (int i = 0; i < size; i++) {
				p[i] = q[i];
			}
			delete[]q;		
		}
		

	}
	
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";
	}
	cout << endl << size << endl;
}