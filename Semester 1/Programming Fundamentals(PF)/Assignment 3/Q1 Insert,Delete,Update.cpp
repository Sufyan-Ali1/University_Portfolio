#include<iostream>
using namespace std;
//Function for insert number
int Insert(int a[], int b) { //b--> Number of elements in array
	int nmbrs;//nmbrs is how many entity user want to insert
	cout << "How many numbers you want to insert\n";
	cin >> nmbrs;
	for (int j = 1; j <= nmbrs; j++) {
		cout << "Inserting Number\n";
		int num;
		cin >> num;

		if (b == 0) {
			a[0] = num;
			b++;
		}
		else if (b == 20) {
			cout << "Your array is already full\n";
		}
		else {
			int index = -1;//index is to check that the inserting entity is greater than all the entities in array or not
			for (int i = 0; i < b; i++) {
				if (a[i] > num) {
					int prev = a[i];
					for (index = i; index < b; index++) {
						int next = a[index + 1];
						a[index + 1] = prev;
						prev = next;
					}
					a[i] = num;
					b++;
					break;
				}
			}
			if (index == -1) {
				a[b] = num;
				b++;
			}
		}
	}
	return b;
}
int Delete(int a[], int b) {
	cout << "Your array is ";
	for (int i = 0; i < b; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	if (b == 0) {
		cout << "Your array is already empty\n";
	}
	else {
		cout << "Which number you want to delete from array\n";
		int num;
		cin >> num;
		int check = 0;//check is used for check that deleting element is occur in array or not
		cout << "For delete all entries of " << num << " Enter(A)\nFor delete some entries of " << num << " Enter(S) \n";
		char l;
		cin >> l;
		if (l == 'A') {
			for (int i = 0; i < b; i++) {
				if (a[i] == num) {
					while (a[i] == num) {
						for (int j = i; j < b; j++) {
							a[j] = a[j + 1];
							
						}
						a[b - 1] = 0;
						b--;
					}
					check = 1;
				}
			}

		}
		else if (l == 'S') {
			cout << "How many entries you want to delete\n";
			int entry;
			cin >> entry;
			for (int i = 0; i < b && entry > 0; i++) {
				if (a[i] == num) {
					while (a[i] == num && entry > 0) {
						for (int j = i; j < b; j++) {
							a[j] = a[j + 1];
				    	}
						a[b - 1] = 0;
						b--;
						entry--;
					}
					check = 1;
				}
			}
			
		}
		if (check == 0) {
			cout << "Element not found\n";
		}
			cout << "Your array is\n";
			for (int i = 0; i < b; i++) {
				cout << a[i] << " ";
			}

		
	}
	
	return b;
}
int update(int a[], int b) {//b-->check how many element exist in array
	cout << "Your array is ";
	for (int i = 0; i < b; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Which number you want to update from array\n";
	int num;
	cin >> num;
	cout << "Enter update value\n";
	int num1;
	cin >> num1;
	cout << "For update all entries of " << num << " Enter(A)\nFor update some entries of " << num << " Enter(S) \n";
	char l;
	cin >> l;
	int check = 0;
	if (l == 'A') {
		for (int i = 0; i < b; i++) {

			if (a[i] == num) {
				a[i] = num1;
				check = 1;
			}

		}
	}
	else if (l == 'S') {
		cout << "How many entries you want to update\n";
		int entry;
		cin >> entry;
		for (int i = 0; i < b && entry > 0; i++) {

			if (a[i] == num && entry > 0) {
				a[i] = num1;
				entry--;
				check = 1;
			}
		}

	}
	for (int i = 0; i < b - 1; i++) {//for sorting array
		for (int j = i + 1; j < b; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	if (check == 0) {
		cout << "Element not found\n";
	}
	cout << "Your array is\n";
	for (int i = 0; i < b; i++) {
		cout << a[i] << " ";
	}

	return b;

}
void main() {
	int arr[20];
	int s = 0;
	bool istrue = false;
	while (!istrue) {

		cout << "select fucntion\n";
		cout << "\nUpdate(U)\nDelete(D)\nInsert(I)\n";
		if (s == 0) {
			cout << "\nYour array is empty please first insert an entity in array\n";
		}
		char a;

		cin >> a;

		if (a == 'U') {
			s = update(arr, s);
		}

		else if (a == 'D') {
			s = Delete(arr, s);
		}

		else if (a == 'I') {
			s = Insert(arr, s);
		}
		cout << "\nFor performing more operation(C)\nElse(Q)\n ";
		char b;
		cin >> b;
		if (b == 'Q')
			istrue = true;

	}
	cout << "Your current array is" << endl;
	for (int i = 0; i < s; i++) {
		cout << arr[i] << " ";
	}

}