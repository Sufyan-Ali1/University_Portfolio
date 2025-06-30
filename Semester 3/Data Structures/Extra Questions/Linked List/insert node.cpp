#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
	node(int x = 0, node* ptr=0) {
		data = x;
		next = ptr;
	}
	void traverse() {
		node* ptr;

		ptr = this;
		while (ptr != 0) {
		
			cout << ptr->data << " ";
			ptr = ptr->next;;
		}
		cout << endl;
	}
	node * insertatbegin(int data) {
		node* ptr;
		ptr=new node;
		ptr->data = data;
		ptr->next = this;
		return ptr;
	}
	node* insertinb_w(int data,int ind) {
    	node* ptr;
		ptr = new node;
		ptr->data = data;
		node* p;
		
		p = this;
		for (int i = 1; i < ind; i++) {
			p = p->next;
		}
		ptr->next = p->next;
		p->next = ptr;
		return this;
	}
	node* insertatend(int data) {
		node* ptr;
		ptr = new node;
		ptr->data = data;
		node* p;

		p = this;
		for (int i = 1; p->next!=0; i++) {
			p = p->next;
		}
		ptr->next = p->next;
		p->next = ptr;
		
		return this;
	}
	node* insertafter(int data, node* x) {
		node* ptr;
		ptr = new node;
		ptr->data = data;
		ptr->next = x->next;
		x->next = ptr;
		return this;

	}
};
void main() {
	node* head;
	node* ptr;
	head = new node;
	ptr = head;
	ptr->data = 5;
	ptr->next = new node;
	ptr = ptr->next;
	ptr->data = 6;

	ptr->next = new node;
	ptr = ptr->next;
	ptr->data = 7;
	node* x = ptr;
	ptr->next = new node;
	ptr = ptr->next;
	ptr->data = 8;
	ptr->next = 0;
	head->traverse();
	//head=head->insertatbegin(1);
	//head = head->insertatend(1);
	head = head->insertafter(2, x);
	head->traverse();
}