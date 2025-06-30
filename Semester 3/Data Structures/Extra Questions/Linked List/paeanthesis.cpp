#include<iostream>
#include<vector>
using namespace std;
class stack {
public:
	char* arr;
	int len;
	int top;
	stack(char *arr1) {
		len = sizeof(arr);
		top = 0;
		arr = new char[len];
	}
	void push() {
		
		arr[top] = '(';
		top++;
	}
	void pop() {
		arr[top-1] = '-';
		top--;
	}
	bool isempty() {
		if (top == 0) {
			return 1;
		}
		return 0;
	}
};
void main() {
	char* arr;
	int size;
	cin >> size;
	arr = new char[size];
	cin >> arr;
	cout << arr << endl;
	stack ab(arr);
	for (int i = 0; arr[i] != '\0'; i++) {
		if (arr[i] == '(') {
			ab.push();
		}
		else if (arr[i] == ')') {
			if (ab.isempty()) {
			 
				cout << "Unbalanced\n";
				return;
			}
			ab.pop();
		}
	}
	if (ab.isempty()) {
		cout << "balaned\n";
	}
	else {
		cout << "Unbalanced\n";
	}
	
}