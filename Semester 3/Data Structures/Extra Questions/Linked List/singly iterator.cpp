#include<iostream>
using namespace std;
template<class t>
class list {
	class node {
	public:
		t data;
		node* next;
	};
	node* head;
	node* tail;
public:
	class iterator {
		node* curr;
		friend class list<t>;
	public:
		iterator() {
			curr = nullptr;
		}

		t& operator*() {
			return curr->data;
		}
		iterator& operator++() {
			curr = curr->next;
			return *this;

		}
		iterator& operator++(int) {
			iterator old;
			old.curr = curr;
			curr = curr->next;
			return old;

		}
		bool operator!=(iterator it) {
			if (curr != it.curr) {
				return true;

			}
			return false;
		}
	};
	list() {
		head = new node;
		tail = new node;
		head->next = tail;
		tail->next = nullptr;
	}
	iterator begin() {
		iterator it;
		it.curr = head->next;;
		return it;
	}
	iterator end() {
		iterator it;
		it.curr = tail;
		return it;
	}
	void sort() {
		list<t>a;
		node* temp = head->next;
		while (temp != tail) {
			if (a.head->next == a.tail || a.head->next->data >= temp->data) {
				a.insertatstart(temp->data);

			}
			else {
				node* ptr = a.head->next;
				while (ptr != a.tail) {
					if (ptr->data > temp->data) {
						break;

					}
					ptr = ptr->next;
				}
				iterator it;
				it.curr = ptr;
				a.insert(it, temp->data);

			}
			temp = temp->next;
		}
		head = a.head;
		tail = a.tail;
	}
	void reverse() {
		node* ptr = head;
		node* ptr1 = head->next;
		node* ptr2;
		while (ptr1 != tail) {
			ptr2 = ptr1->next;
			ptr1->next = ptr;
			ptr = ptr1;
			ptr1 = ptr2;
		}
		ptr1->next = ptr;
		head->next = nullptr;
		ptr = head;
		head = tail;
		tail = ptr;
	}
	void insert(iterator t1, t data) {
		node* ptr = t1.curr;
		node* ptr2 = new node;
		ptr2->data = ptr->data;
		ptr->data = data;
		ptr2->next = ptr->next;
		ptr->next = ptr2;
		if (tail == t1.curr) {
			tail = ptr2;
		}
	}
	void merge(list l1) {
		node* temp = head;
		node* temp1 = head->next;
		node* ptr = l1.head->next;
		node* ptr1;
		while (temp1 != tail && ptr != l1.tail) {
			if (temp1->data >= ptr->data) {
				ptr1 = ptr->next;
				ptr->next = temp1;
				temp->next = ptr;
				temp = ptr;
				ptr = ptr1;
				
			}
			else {
				temp = temp1;
				temp1 = temp1->next;
			}
		}
		if (ptr != l1.tail) {
			
			temp->next = ptr;
			tail = l1.tail;
		}
	}
	iterator remove(iterator it) {
		node* pt = it.curr;
		node* ptr = pt->next;
		pt->data = ptr->data;
		pt->next = ptr->next;
		if (tail == ptr) {
			tail = pt;
		}
		delete ptr;
		it.curr = pt;
		return it;
	}
	void insertatstart(t data) {
		insert(begin(), data);
	}
	void insertatend(t data) {
		insert(end(), data);
	}
	void traverse() {
		node* temp = head->next;;
		while (temp != tail) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
void main() {
	list<int> l1;
	l1.insertatstart(19);
	l1.insertatstart(14);
	l1.insertatstart(7);
	l1.insertatstart(4);
	l1.insertatstart(1);
	l1.traverse();
	list<int> l2;
	l2.insertatstart(25);
	l2.insertatstart(21);
	l2.insertatstart(15);
	l2.insertatstart(11);
	l2.insertatstart(9);
	l2.insertatstart(6);
	l2.insertatstart(0);
	l2.traverse();
	l1.merge(l2);
	l1.traverse();
	list<int>::iterator it;
	for (it = l1.begin(); it != l1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	l1.sort();

	for (it = l1.begin(); it != l1.end(); it++) {
		cout << *it << " ";
	}
	l1.reverse();
	for (it = l1.begin(); it != l1.end(); it++) {
		cout << *it << " ";
	}
}