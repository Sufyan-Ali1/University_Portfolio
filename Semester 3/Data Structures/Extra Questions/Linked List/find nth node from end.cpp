#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* next;
	node * findnthnode(int n) {
		//----------------------------METHOD 1-----------------------------
		/*node* ptr = this;
		int i = 1;
		while (ptr->next != 0) {
			i++;
			ptr = ptr->next;
		}
		if (n > i) {
			return 0;
		}
		cout << i << endl;
		i = i-n;
		ptr = this;
		cout << this->data<<" a\n";
		while (i > 0&&ptr->next!=0) {
			ptr = ptr->next;
			i--;
		}
		return ptr;*/

		//----------------------------METHOD 2-----------------------------
		node* p;
		node* nth;
		p = this;
		nth = this;
		for (int i = 1; p->next != 0; i++) {
			p = p->next;
			if (i >= n) {
				nth = nth->next;
			}
		}
		return nth;
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
	ptr->next = new node;
	ptr = ptr->next;
	ptr->data = 8;
	ptr->next = 0;
	ptr = head->findnthnode(3);
	cout << ptr->data;
}