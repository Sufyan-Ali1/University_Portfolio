#include<iostream>
using namespace std;
template<class T>
class DList {

	class DNode {
	public:
		T data;
		DNode* next;
		DNode* prev;

	};
	DNode* head;
	DNode* tail; 
public:
	DList() {
		head = new DNode;
		tail = new DNode;
		head->next = tail;
		head->prev = nullptr;
		tail->prev = head;
		tail->next = nullptr;
	}
	~DList() {
		DNode* temp = head->next;
		while (head->next != tail) {
			deleteatstart();
		}
		delete head;
		delete tail;
	}
	void insertatstart(T data) {
		DNode* temp = new DNode;
		temp->data = data;
		temp->next = head->next;
		temp->prev = head;
		head->next->prev = temp;
		head->next = temp;
		

	}
	bool isempty() {
		if (head->next = tail) {
			return 1;
		}
		return 0;
	}
	bool isfull() {
		DNode* temp = new DNode;
		if (temp == nullptr) {
			return 1;
		}
		return 0;
	}
	void insertatend(T data) {
		DNode* temp = new DNode;
		temp->data = data;
		temp->next = tail;
		temp->prev = tail->prev;
		tail->prev->next = temp;
		tail->prev = temp;

	}
	void deleteatstart() {
		if (head->next != tail) {
			DNode* temp = head->next;
			head->next = temp->next;
			temp->next->prev = head;
			delete temp;

		}

	}
	bool deletevalue(T data) {
		DNode* temp;
		int check = 0;
		temp = head->next;
		while (temp!=tail) {
			if (temp->data==data) {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				check = 1;
				
            }
			temp = temp->next;
		}
		return check;
	}
	void deleteatend() {
		if (head->next != tail) {
			DNode* temp = tail->prev;
			tail->prev = temp->prev;
			temp->prev->next = tail;
			delete temp;
		}

	}
	void reverselist() {
		int count = 0;
		DNode* temp = head->next;
		while (temp->next != tail) {
			count++;
		}
		temp = head->next;
		DNode* temp1
		for (int i = 0; i < n / 2; i++) {

		}
	}

	void reversetraverse() {
		DNode* temp = tail->prev;
		while (temp!=head) {
			cout << temp->data << " ";
			temp = temp->prev;
		}
		cout << endl;
	}
	void print() {
		DNode* temp;
		temp = head->next;
		while (temp != tail) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

};
void main() {
	DList<int> a;
	int x;
	cout << "Enter ten elements for insert in list\n";
	for (int i = 0; i < 10; i++) {
		cin >> x;
		a.insertatstart(x);
	}
	cout << "Forwand Printing\n";
	a.print();
	cout << "Reverse Printing\n";
	a.reversetraverse();

	cout << "Enter a value for delete from list\n";
	cin >> x;
	int c=a.deletevalue(x);
	
	
	if (c) {
		cout << "Successfully Deleted\n";
		cout << "New List is :";
	    a.print();
	}
	else {
		cout << "Element Not Exist\n";
	}

}
