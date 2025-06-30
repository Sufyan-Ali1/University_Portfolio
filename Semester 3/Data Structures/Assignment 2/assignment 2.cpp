#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define keyu 72
#define keyd 80
#define keyl 75
#define keyr 77
using namespace std;
class coordinates {
public:
	int x;
	int y;

	coordinates() {
		x = 0;
		y = 0;
	}
	void set(int a, int b) {
		x = a;
		y = b;
	}
};
//------------------------------------------SINGLY LINKED LIST------------------------------------------
template<class T>
class Slist {
	class node {
	public:
		T data;
		node* next;
	};
	node* head;
	node* tail;
public:
	Slist() {
		head = new node;
		tail = new node;
		tail->next = nullptr;
		head->next = tail;
	}
	bool insert(T dat) {
		if (!isfull()) {
			node* temp = new node;
			temp->data = dat;
			temp->next = head->next;
			head->next = temp;
			return 1;
		}
		return 0;
	}
	bool isfull() {
		node* temp = new node;
		return temp==nullptr;
	}
	bool isempty() {
		return head->next == tail;

	}
	bool remove(T& dat) {
		if (!isempty()) {
			node* temp = head->next;
			dat = temp->data;
			head->next = temp->next;
			return 1;
		}
		return 0;
	}
	~Slist() {
		node* temp = head->next;
		while (temp != tail) {
			head->next = temp->next;
			delete temp;
			temp = head->next;

		}
	}
	void top(T &dat ) {
		
	  dat = head->next->data;		
	}
};
//----------------------------------------------STACK-------------------------------------------
template<class T>
class stack {
	Slist<T> list;
	int size;

public:
	stack() {
		size = 0;
	}
	bool push(T data) {
		size++;
		return list.insert(data);
	}
	bool pop(T& data) {
		return list.remove(data);
	}
	bool isfull() {
		return list.isfull();
	}
	bool isempty() {
		return list.isempty();
	}
	int getsize() {
		return size;
	}
	bool top(T &dat) {
		if (!isempty()) {
			list.top(dat);
			return 1;
		}
		return 0;
	}
	~stack() {
		list.~Slist();
		size = 0;
	}
};
//--------------------------------------MAIN CLASS--------------------------------------
class hauntedhouses {
	int rooms;
	string* roomno;
	char** roomcells;
	stack<int>prroom;//previous room
	int croom;
	stack<coordinates>prmov;//previous move
	coordinates curr;
	coordinates total;
public:
	hauntedhouses() {

		ifstream input("hauntedhouse.txt", ios::in);//get input from file
		string a;
		input >> a;
		rooms = 0;
		rooms = a[0] - 48;//how many spooky rooms are there 
		croom = 0;
		roomno = new string[rooms];
		for (int i = 0; i < rooms; i++) {
			input >> roomno[i];
		}
		roomcells = nullptr;

	}
	bool load(int x) {
		prmov.~stack();
		bool k;
		if (roomcells != nullptr) {
			
			for (int i = 0; i < total.x; i++) {
				delete[]roomcells[i];
			}
			delete[]roomcells;
			total.x = 0;
			total.y = 0;
			curr.x = 0;
			curr.y = 0;
		}
		ifstream input;
		if (x == 0) {
			srand(time(0));
			int ind = rand() % 3;
			croom = ind;
			
			prroom.push(croom);
			input.open(roomno[ind], ios::in);
			
		}
		else if (x == -1) {
			croom = 2;
			prroom.push(croom);
			input.open(roomno[croom], ios::in);
		}
		else {
			k = prroom.pop(croom);
			k = prroom.top(croom);
			if (k) {
				input.open(roomno[croom], ios::in);
			}
			else {
				return 0;
			}
		}
		
		//----------------------------open the room and load the data------------------------
		if (input) {
			string a;
			input >> a;
			int i;

			//load no rows
			for (i = 0; a[i] != ','; i++) {
				total.x = total.x * 10 + (a[i] - 48);
			}
			i++;
			//load no colunms
			for (; a[i] != '.'; i++) {
				total.y = total.y * 10 + (a[i] - 48);
			}
			//declaring roomcells----
			roomcells = new char* [total.x];
			for (int i = 0; i < total.x; i++) {
				roomcells[i] = new char[total.y+1];
			}
			input >> a;


			//load starting coordinates
			for (i = 0; a[i] != ','; i++) {
				curr.x = curr.x * 10 + (a[i] - 48);
			}
			i++;
			//load no colunms
			for (; a[i] != '.'; i++) {
				curr.y = curr.y * 10 + (a[i] - 48);
			}
			prmov.push(curr);


			getline(input, a);
			//tokenization
			for (int i = 0; i < total.x; i++) {
				getline(input, a);
				token(roomcells, a, 0, i, 0, curr.x, curr.y);
			}

			return 1;
		}
		else {
			cout << "Next Room Not found\n";
			return 0;

		}

	}
	//tokeization recursive function
	void token(char** arr, string a, int i, int j, int k, int l, int m) {
		if (a[i] == '/') {
			arr[j][k] = '\0';
			return;
		}
		else if (j == l && k == m) {
			arr[l][m] = 229;
			token(arr, a, ++i, j, ++k, l, m);
		}
		else {
			arr[j][k] = a[i];
			token(arr, a, ++i, j, ++k, l, m);
		}

	}
	char instructions() {
		cout << "\t\t\t\t\t\tINSTRUCTIONS\n";
		cout << "X indicates = > a forbidden cell(Wall)\n";
		cout << "D = > Devil If you encounters a devil in the path then you will die, and game ends\n";
		cout << "G = > Gasper If yoi encounters a Gasper, then Gasper teleports you to a room with treasure\n";
		cout << "T = > Treasure that you have to find\n";
		cout << "P= > Portal teleports the user randomly to another room to a random cell\n"
		"it will flip the coin if there is head you will move in new room it there is tail then it will take you previuos room\n";
		cout << "Use arrow keys for movement\nUp key for upword\nDown key for downword\nLeft key for move keftword\n"
		"Right key for move Rightword\n";
		cout << "For start game press 1\n";
		char  x;
		x = _getch();
		return x;
		
		
	}
	//Start Game-----------------------------
	void load1() {

	}
	void load2() {

	}
	void start() {
		bool l;
		bool found=0;
		int check = 1;
		int check1 = 1;
		int ran;
		char y;
		system("cls");
		
		
			while (1) {

				for (int i = 0; i < total.x; i++) {
					cout << roomcells[i] << endl;;
				}
				cout << "Number of moves in Current Room: " << prmov.getsize() - 1 << endl;
				cout << "Current Room No: " << croom + 1 << endl;
				if (!check) {
					cout << "Died by Enemy\n";
					break;
				}
				if (!check1) {
					cout << "Game End there is not any previous room\n";
				}
				if (found) {
					break;
				}
				y = _getch();
				if (y == 'q') {

					cout << "Game Quit by Player\n";
					break;
				}
				switch (_getch()) {

				case 72://up
					if (curr.x - 1 >= 0) {
						if (roomcells[curr.x - 1][curr.y] != 'X') {
							if (roomcells[curr.x - 1][curr.y] == 'D') {
								check = 0;
							}
							
							else if (roomcells[curr.x - 1][curr.y] == 'P') {
								
								srand(time(0));
								ran = rand() % 2;
								l=load(ran);//head=0 ,tail=1
								if (!l) {
									check1 = 0;
									break;
								}
							}
							else if(roomcells[curr.x - 1][curr.y] == 'G') {
								
							}
							else if (roomcells[curr.x - 1][curr.y] == 'T') {
								found = 1;
							}
							
								roomcells[curr.x][curr.y] = ' ';
								roomcells[--curr.x][curr.y] = 229;
								prmov.push(curr);
							
							
						}

					}
					
					break;
				case 80://down
					cout << 3 << endl;
					if (curr.x + 1 < total.x) {
						if (roomcells[curr.x + 1][curr.y] != 'X') {
							if (roomcells[curr.x + 1][curr.y] == 'D') {
								check = 0;
							}
							else if (roomcells[curr.x + 1][curr.y] == 'P') {
								int ran;
								srand(time(0));
								ran = rand() % 2;
								l = load(ran);//head=0 ,tail=1
								if (!l) {
									check1 = 0;
									break;
								}
							}
							else if (roomcells[curr.x + 1][curr.y] == 'G') {
								l = load(-1);
								if (!l) {
									check1 = 0;
									break;
								}
							}
							else if (roomcells[curr.x + 1][curr.y] == 'T') {
								found = 1;
							}
						
								roomcells[curr.x][curr.y] = ' ';
								roomcells[++curr.x][curr.y] = 229;
								prmov.push(curr);
							
						}
						
					}
				
					break;
				case 75://left
					cout << 5 << endl;
					if ( curr.y - 2 >= 0) {
						if (roomcells[curr.x][curr.y - 2] != 'X') {
							if (roomcells[curr.x][curr.y - 2] == 'D') {
								check = 0;
							}
							else if (roomcells[curr.x][curr.y - 2] == 'P') {
								int ran;
								srand(time(0));
								ran = rand() % 2;
								l = load(ran);//head=0 ,tail=1
								if (!l) {
									check1 = 0;
									break;
								}
							}
							else if (roomcells[curr.x ][curr.y-2] == 'G') {
								l = load(-1);
								if (!l) {
									check1 = 0;
									break;
								}
							}
							else if (roomcells[curr.x][curr.y - 2] == 'T') {
								found = 1;
							}
							
								roomcells[curr.x][curr.y] = ' ';
								roomcells[curr.x][--(--curr.y)] = 229;
								prmov.push(curr);
							
						}
						
					}
					
					break;
				case 77://right
					if ( curr.y + 2 < total.y) {
						if (roomcells[curr.x][curr.y + 2] != 'X') {
							if (roomcells[curr.x][curr.y + 2] == 'D') {
								check = 0;

							}
							else if (roomcells[curr.x][curr.y + 2] == 'P') {
								int ran;
								srand(time(0));
								ran = rand() % 2;
								l = load(ran);//head=0 ,tail=1
								if (!l) {
									check1 = 0;
									break;
								}
							}
							else if (roomcells[curr.x ][curr.y+2] == 'G') {
								l = load(-1);
								if (!l) {
									check1 = 0;
									break;
								}
							}
							else if (roomcells[curr.x][curr.y + 2] == 'T') {
								found = 1;
							}
							
								roomcells[curr.x][curr.y] = ' ';
								roomcells[curr.x][++(++curr.y)] = 229;
								prmov.push(curr);
							
						}
						
					}
					break;
				}
				
				
				system("cls");
			
		    }
			if (found) {

				cout << "\n\nCongrats You found the Treasure\n";
			}
	}
};
void main() {

	hauntedhouses ob;
	char x=ob.instructions();
	if (x == '1') {
		int y=ob.load(0);
		if (y) {
			ob.start();
		}
	}
	


}