#include<iostream>
using namespace std;
class memorymanagementsys {
	class block;
	class program;
	template<class t>
	class singlylinkedlist {
		class node {
		public:
			t data;
			node* next;
		};

		node* head;
		node* tail;
		int size;
	public:
		singlylinkedlist() {
			head = tail = nullptr;
			size = 0;
		}
		void setsize(int x) {

			size += x;//set size-----------------------------------
		}
		void insert(t data) {
			node* temp;
			temp = new node;
			temp->data = data;

			temp->next = nullptr;
			if (head == nullptr) {
				head = tail = temp;

			}
			else {
				tail->next = temp;
				tail = temp;
			}
		}
		singlylinkedlist<block> removes(int& x) {
			//if (head =!nullptr) {
			singlylinkedlist<block> a;
			int chk = 0;
			node* temp;
			temp = head;
			node* temp1 = head;
			while (temp != nullptr) {
				if (x == temp->data.id) {
					chk = 1;
					break;
				}
				temp1 = temp;
				temp = temp->next;
			}
			if (chk == 1) {
				if (temp == temp1) {
					if (temp->next == nullptr) {
						head = tail = nullptr;
					}
					else {
						head = head->next;
					}
					a = temp1->data.b;
					x = temp1->data.size;
					size = x;
					delete temp1;
					return a;
				}
				else {
					a = temp->data.b;
					x = temp1->data.size;
					if (temp->next == nullptr) {
						tail = temp1;
					}
					temp1->next = temp->next;
					size = size - temp->data.size;
					delete temp;
					return a;
				}
			}

			x = -1;
			return a;
			//}
		}
		singlylinkedlist < block> operator+(singlylinkedlist < block> a) {
			if (head != nullptr) {
				tail->next = a.head;
				tail = a.tail;
			}
			else {
				head = a.head;
				tail = a.tail;
			}
			//a.traverse();
			size = size + a.size;
			return *this;
		}

		void traverse() {
			node* temp = head;
			if (temp == nullptr) {
				cout << "Oops Empty\n";
			}
			while (temp != nullptr) {
				
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		void pprint(int id) {
			node* temp = head;
			
			while (temp != nullptr) {

				if (id == temp->data.id) {
					break;
				}
				temp = temp->next;
			}
			if (temp != nullptr) {
				cout << temp->data;
				int x;
				cout << "Press 1 for print all Memory Blocks of this program else 0\n";
				cin >> x;
				if (x == 1) {
					temp->data.b.traverse();
				}
			}
			else {
				cout << "Program of id " << id << " is not exist\n";
			}
			cout << endl;
		}

		bool findtr(int x, block a) {
			node* temp = head;
			while (temp != nullptr) {
				if (temp->data.id == x) {
					temp->data.b.insert(a);
					temp->data.b.setsize(a.Tot_bytes);
					temp->data.size += a.Tot_bytes;
					return 1;
				}
				temp = temp->next;
			}
			return 0;
		}
		void remfree(node*& tem, node*& x) {//remove the node which is free
			node* temp = tem;
			if (temp == x) {
				cout << "#$%-------------------\n";
				head = tem->next;
			}
			else {

				tem->next = tem->next->next;
			}


			delete x;
		}
		void remall() {
			node* temp = head;
			while (head != nullptr) {
				head = head->next;

				delete temp;
				temp = head;
			}
		}
		
		void merge() {
			node* ptr = head;
			node* ptr1 = head->next;
			int x = 0;
			while (ptr1 != nullptr) {

				x = ptr->data.S_ID + ptr->data.Tot_bytes;

				if (ptr1->data.S_ID == x) {

					ptr->data.Tot_bytes += ptr1->data.Tot_bytes;

					ptr->next = ptr1->next;

					delete ptr1;
					if (ptr->next == nullptr) {
						tail = ptr;
					}
					ptr1 = ptr->next;
					continue;
				}


				ptr = ptr->next;
				ptr1 = ptr->next;

			}
		}
		singlylinkedlist<block>  sort() {
			singlylinkedlist<block> temp;
			node* curr = head;

			node* ext = curr->next;
			while (curr != nullptr) {
				ext = curr->next;
				if (temp.head == nullptr || temp.head->data.S_ID >= curr->data.S_ID) {
					if (temp.head == nullptr) {
						temp.head = temp.tail = curr;
						temp.tail->next = nullptr;
					}
					else {
						curr->next = temp.head;
						temp.head = curr;

					}
				}
				else {
					node* ptr = temp.head;

					while (ptr->next != nullptr && ptr->next->data.S_ID < curr->data.S_ID) {
						ptr = ptr->next;
					}
					curr->next = ptr->next;
					ptr->next = curr;
					if (ptr->next == nullptr) {
						tail = curr;
					}

				}
				curr = ext;
			}
			temp.merge();

			return temp;
		}

		int freememB(int x) {//for check free memory in pool
			node* temp = head;
			node* temp1 = head;
			node* min = head;
			node* prev = head;
			int start = -1;
			while (temp != nullptr) {
				if (temp->data.Tot_bytes < min->data.Tot_bytes && temp->data.Tot_bytes >= x) {
					prev = temp1;
					min = temp;
				}
				temp1 = temp;
				temp = temp->next;
			}
			if (min != nullptr) {
				if (min->data.Tot_bytes >= x) {
					size = size - x;
					start = min->data.S_ID;
					min->data.Tot_bytes = min->data.Tot_bytes - x;
					min->data.S_ID = min->data.S_ID + x;
					if (min->data.Tot_bytes == 0) {
						remfree(prev, min);
					}

				}
			}


			return start;
		}

		int freemem(int x) {//for check free memory in pool
			node* temp = head;
			node* temp1 = head;
			int start = -1;

			while (temp != nullptr) {
				if (temp->data.Tot_bytes >= x) {
					size = size - x;
					start = temp->data.S_ID;
					temp->data.Tot_bytes = temp->data.Tot_bytes - x;
					temp->data.S_ID = temp->data.S_ID + x;
					if (temp->data.Tot_bytes == 0) {
						remfree(temp1, temp);
					}
					break;
				}
				temp1 = temp;
				temp = temp->next;
			}
			return start;
		}
		void print() {
			cout << "Total Memory that taken by whole system\n";
			cout << size << endl;
		}

	};

	class block {
	public:
		int S_ID;
		int Tot_bytes;
		friend ostream& operator<<(ostream& ob, block& b) {
			ob << "Block Data\n";
			ob << "Starting Location of memory " << b.S_ID << "  Total Bytes of Block" << b.Tot_bytes << endl;
			return ob;
		}
		block operator=(const block& a) {
			S_ID = a.S_ID;
			Tot_bytes = a.Tot_bytes;
			return *this;
		}
	};
	class program {
	public:
		int id;
		int size;
		singlylinkedlist<block> b;
		void add(block a) {
			b.insert(a);
			b.setsize(a.Tot_bytes);
		}


		friend ostream& operator<<(ostream& ob, program& ba) {
			cout << "Program id:" << ba.id << endl;
			cout << " program Size:" << ba.size << endl;
			return ob;
		}
	};
	//Data members
	singlylinkedlist<block> pool;
	singlylinkedlist<program> progs;
	int somem;//size of memory
	char stat;//stategy


public:
	memorymanagementsys(char s) {
		block data;
		data.S_ID = 0;
		data.Tot_bytes = 10000;
		somem = 10000;
		stat = '-';
		pool.setsize(10000);
		pool.insert(data);
		stat = s;

	}
	bool getmem(int id, int size) {
		int x = -1;
		if (stat == 'f' || stat == 'F') {
			x = pool.freemem(size);
		}
		else if (stat == 'b' || stat == 'B') {
			x = pool.freememB(size);
		}
		else {
			cout << "You press incorrect character\n";
		}


		if (x != -1) {
			block data;
			data.S_ID = x;
			data.Tot_bytes = size;
			progs.setsize(size);

			int x1 = progs.findtr(id, data);
			if (!x1) {
				program dat;
				dat.id = id;
				dat.size = size;
				dat.add(data);

				progs.insert(dat);
				cout << "New program is created of " << size << " bytes of ID " << id << " starting memory location is " << x << endl;
				return 1;
			}
			cout << "New block of " << size << " bytes assign to the program " << id << endl;
			return 1;
		}
		cout << "Memory is full or Continuous memory block is not available of " << size << " bytes\n";
		return 0;
	}
	bool remove1(int x) {
		int id = x;
		singlylinkedlist<block> po = progs.removes(x);

		if (x != -1) {

			pool = pool + po;
			pool = pool.sort();
			cout << "Program Rmoved Successfully\n";
			return 1;
		}
		cout << "There is not any program exist of id " << id << endl;
		return 0;
	}
	void printpool() {
		cout << "Pool Information\n";
		pool.traverse();
	}
	void print() {
		progs.traverse();
	}
	void Pprint(int x) {
		progs.pprint(x);
	}


};
void main() {
	cout << "For which stategy you want to create memory management system\nPress (f) for First fit stategy\n"
		"Press(b) for Best fit stategy\n";
	char s;
	cin >> s;

	memorymanagementsys mem(s);
	int a = 0, id;
	cout << "\t\t----------------------------Welcome to Memory Management System----------------------------\n\n";
	while (a != -1) {
		cout << "\t\t\t\t--------------------------------------------------------\n\n";
		cout << "Press (1) For get Memory for existing program or new program\nPress (2) For remove any program\n"
			"Press (3) For Check Available Memory Blocks of Pool\nPress (4) For check all Programs Id and and memory blocks\n"
			"Press (5) For check Particular Program Data Block\nPress (-1) For Quit Memory Management system\n";
		cin >> a;
		if (a == 1) {
			int size;
			cout << "Enter Id of Program\n";
			cin >> id;
			cout << "Enter Size of Memory you want to get\n";
			cin >> size;
			mem.getmem(id, size);
		}
		else if (a == 2) {
			cout << "Enter id of program you want to remove\n";
			cin >> id;
			mem.remove1(id);

		}
		else if (a == 3) {
			mem.printpool();
		}
		else if (a == 4) {
			mem.print();
		}
		else if (a == 5) {
			cout << "Enter Id of Program\n";
			cin >> id;
			mem.Pprint(id);
		}
		else if(a!=-1) {
			cout << "Please enter correct value from below\n";
		}
	}
	cout << "Thank You\n";

}
