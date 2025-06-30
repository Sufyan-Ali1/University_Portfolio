#include<iostream>
using namespace std;
//Function for insert number
int Insert(int a[], int b) { //b--> Number of elements in array
	int j = 1;
	int nmbrs;
	cout << "How many numbers you want to insert\n";
	cin >> nmbrs;
	while (j <= nmbrs) {
		cout << "Inserting Number\n";
		int num;
		cin >> num;
		int index = -1;
		if (b == 0) {
			a[0] = num;
			b++;
		}
		else if (b == 20) {
			cout << "Your array is already full\n";
		}
		else {
			for (int i = 0; i < b; i++) {
				if (a[i] > num) {
					index = i;
					break;
				}
			}
			if (index != -1) {
				for (int i = index; i < b; i++) {
					int prev = a[i];
					for (i; i < b; i++) {

						int next = a[i + 1];
						a[i + 1] = prev;
						prev = next;
					}
					a[index] = num;
					b++;
				}
			}
			else {
				a[b] = num;
				b++;
			}
		}
		j++;
	}
	return b;
}
//int Delete(int a[];)
void main() {
	int arr[20];
	int s = 0;
	bool istrue = false;
	while (!istrue) {
		cout << "select fucntion\n";
		cout << "Update(U)\nDelete(D)\nInsert(I)\n";
		char a;

		cin >> a;

		/*if (a == 'U') {
			update();
		}
		else if (a == 'D') {
			Delete();
		}*/

		if (a == 'I') {
			s = Insert(arr, s);
		}
		cout << "For performing more operation(C)\nElse(Q)\n ";
		char b;
		cin >> b;
		if (b == 'Q')
			istrue = true;
		
	}
	for (int i = 0; i < s; i++) {
		cout<<arr[i]<<" ";
	}
	
}