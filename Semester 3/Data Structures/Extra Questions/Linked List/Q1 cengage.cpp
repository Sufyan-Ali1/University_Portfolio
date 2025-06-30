#include<iostream>
using namespace std;
template<class T>
class list {
	class node {
	public:
		T ndata;
		T ddata;
		node* next;
	};
	node* head;
	node* tail;

public:
	list() {
		head = new node;
		tail = new node;
		head->next = tail;
		tail->next = nullptr;
	}
	node* insert(T data,T data1,node *ptr) {
		node* temp = new node;
		temp->ddata = ptr->ddata;
		temp->ndata = ptr->ndata;
		ptr->ddata = data1;
		ptr->ndata = data;
		temp->next = ptr->next;
		ptr->next = temp;
		if (ptr == tail) {
			tail = temp;
		}
		
			return temp;
		
	}
	void nlevel() {
		node* temp=head->next;
		node* temp1 = temp->next;
		while (temp1 != tail) {
			
			temp1=insert(temp->ndata + temp1->ndata, temp->ddata + temp1->ddata,temp1);
			
			temp = temp1;
			temp1 = temp1->next;
		}
	}
	void start( T d,T d1) {
		insert(d, d1, tail);
	}
	void traverse() {
		node* temp = head->next;
		if (temp != tail) {
			cout << "(";
		}
		while (temp != tail) {
			cout << temp->ndata << "/" << temp->ddata;
			if (temp->next != tail) {
				cout << ",";
			}
			temp = temp->next;
		}
		cout << ")"<<endl;

	}
};
void main() {
	list<int> a;
	a.start(0, 1 );
	a.start(1, 1);
	a.traverse();
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		a.nlevel();

	}
	a.traverse();

	
}