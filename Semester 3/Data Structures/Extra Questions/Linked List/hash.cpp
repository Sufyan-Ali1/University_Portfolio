#include<iostream>
#include<unordered_map>
using namespace std;
class node {
public:
	int data;
	node* next;
	node(int x = 0, node* ptr = 0) {
		data = x;
		next = ptr;
	}
	bool traverse() {
		unordered_map<node*, int> x;
		node *ptr;

		ptr = this;
		while (ptr != 0) {
			x[ptr] = ptr->data;
			//cout << ptr->data << " ";
			ptr = ptr->next;;
			if (x.count(ptr)) {
				return 1;
			}
			
		}
		return 0;
	}
};
int main() {
	node* head;
	node* ptr;
	head = new node;
	ptr = head;
	ptr->data = 5;
	ptr->next = new node;
	ptr = ptr->next;
	ptr->data = 5;

	ptr->next = new node;
	ptr = ptr->next;
	ptr->data = 7;
	node* x = ptr;
	ptr->next = new node;
	ptr = ptr->next;
	ptr->data = 8;
	ptr->next = head;
	bool y=head->traverse();
	cout << y;
	
}
