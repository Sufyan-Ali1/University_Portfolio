#include<iostream>
using namespace std;
class student {
	int* arr;
public:
	student() {
		arr = new int[5];
	}
	student(const student &a) {
		arr = new int[5];
		for (int i = 0; i < 5; i++) {
			arr[i] = a.arr[i];
		}
	}

	void set_in(int marks, int index) {
		arr[index] = marks;
	}
	void display()
	{
		for (int i = 0; i < 5; i++) {
			cout << "Marks of subject " << i + 1 <<": " << arr[i] << endl;;
		}
	}

};
void main() {
	student student1;
	int marks;
	for (int i = 0; i < 5; i++) {
		cout << "Enter marks of subject " << i + 1 << ": ";
		cin >> marks;
		student1.set_in(marks, i);
	}
	cout << "Data of subject 1\n";
	student1.display();
	student student2(student1);
	cout << "Data of subject 2\n";
	student2.display();
	student1.~student();
	cout << "After delete of object1 data\n";
	student2.display();
	
}