#include<iostream>
using namespace std;
template<class T>
class list {
	class node {
	public:
		T data;
		node* next;
	public:
		node() {
			data = 0;//alaways change it w.r.t data type 
			next = 0;
		}
		node(T dat,node*p=0) {
			data = dat;
			next = p;
		}
	};
	node* head;
	node* tail;
	public:
		list() {
			tail = new node;
			T d1=0;
			head = new node(d1,tail);
		}
		bool insert(T dataa) {
			if (!isfull()) {
				head->next = new node(dataa, head->next);
				//head->next = p;
				return 1;
			}
			return 0;
	    }
		bool remove(T &d,T&p) {
			if (!isempty()) {
				node* temp = head->next;
				d = temp->data;
				head->next = temp->next;
				p = head->next->data;
				delete temp;
				return 1;
			}
			return 0;
		}
		bool isfull() {
			node* ptr = new node;
			return ptr == 0;
		}
		bool isempty() {
			
			return head->next==tail;
		}
		void traverse() {
			for (node* temp = head->next; temp != tail; temp = temp->next) {
				cout << temp->data << " ";
			}
			cout << endl;
		}
};
template<class T>
class stack {
	list<T>arr;
	T front;
	//T rear;
	int size;
public:
	stack() {
		size = 0;
		front = 0;
	}
	bool push(T data) {
		bool x = arr.insert(data);
		if (x) {
			front = data;
			size++;
		}
		return x;
	}
	bool pop(T &data) {
		T pr;
		bool x = arr.remove(data,pr);
		if (x) {
			front = pr;
			size--;
		}
		return x;
		
	}
	bool top() {
		if (size != 0) {
			return front;

		}
		return 0;
	}
	bool isempty() {
		return size == 0;
	}
	bool isfull() {
		return arr.isfull();
	}
	T fronts() {
		return front;
	}
	void print() {
		arr.traverse();

	}
	int sizes() {
		return size;
	}
};
void main() {
	stack<int>s;
	cout<<s.isfull()<<endl;
	cout << s.isempty() << endl;
	cout << s.sizes() << endl;
	for (int i = 0; i < 6; i++) {
		int y;
		cout << "Enter Data\n";
		cin >> y;
		y=s.push(y);
		if (y)
		cout << "Successfully pushed\n";
		else {
			cout << "Memory is full\n";
		}

	}
	cout << s.fronts() << endl;;
	s.print();
	int x;
	s.pop(x);
	cout << x << endl;
	s.pop(x);
	cout << x << endl;
	s.print();

}