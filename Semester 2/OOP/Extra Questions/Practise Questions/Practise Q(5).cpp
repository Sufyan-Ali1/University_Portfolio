#include<iostream>
#include<string>
using namespace std;
 char nam[31];
 char dep_name[41];
class employee {
	int id;
	char nam[31];
	char dep_name[41];
public:
	employee();
	employee(int,string,string);
	employee(int, string);
	void setid(int);
	void setname(string);
	void setdep_nam(string);
	int getid();
	char* getname();
	char* getdep_nam();
	void display();
};
employee::employee() {
	id = 0;
	nam[0] = '\0';
	dep_name[0] = '\0';
}
employee::employee(int a, string b, string c) {
	id = a;
	//int len = size(b);
	for (int i = 0; b[i]!='\0'; i++) {
		nam[i] = b[i];
		
	}
	for (int i = 0; c[i] != '\0'; i++) {
		
		dep_name[i] = c[i];
	}

}
employee::employee(int a, string b) {
	id = a;
	//int len = size(b);
	for (int i = 0; b[i] != '\0'; i++) {
		nam[i] = b[i];

	}
	dep_name[0] = '\0';

}
void employee:: setid(int ids) {
	id = ids;
}
void employee::setname(string a) {
	//int len = size(b);
	int i;
	for ( i = 0; a[i] != '\0'; i++) {
		nam[i] = a[i];

	}
	nam[i] = '\0';
	cout << nam << endl;
}
void employee::setdep_nam(string a) {
	int i;
	for ( i = 0; a[i] != '\0'; i++) {

		dep_name[i] = a[i];
	}
	dep_name[i] = '\0';
	//cout << dep_name << endl;
}


int employee::getid() {
	return id;
}
char* employee::getname() {
	char* arr;
	arr = new char[31];
	int i;
	for ( i = 0; nam[i] != '\0'; i++)
	{
		arr[i] = nam[i];
	}
	arr[i] = '\0';
	return arr;
	
}
void employee::display() {
	int id;
	id = getid();
	char* arr;
	arr = new char[31];
	char* arr1;
	arr1 = new char[41];
	arr = getname();
	arr1 = getdep_nam();
	cout << "Id of user is " << id << endl;
	cout << "Name of user is " << *arr << endl;
	cout << "Department name of user is " << *arr1 << endl;
}
char* employee::getdep_nam() {
	char* arr;
	arr = new char[41];
	int i;
	cout << dep_name;
	for (i = 0; nam[i] != '\0'; i++)
	{
		arr[i] = dep_name[i];
	}
	arr[i] = '\0';
	return arr;
}
void main() {
	int siz;
	cout << "Enter the no of users\n";
	cin >> siz;
	employee *a;
	a = new employee[siz];
	for (int i = 0; i < siz; i++) {
		cout << "Enter the id of user " << i + 1 << ": ";
		int id;
		cin >> id;
		a[i].setid(id);
		cout << "Enter the name of user " << i + 1 << ": ";
		string nam;
		string name1;
		cin.ignore();
		getline(cin,nam);
		a[i].setname(nam);
		cout << "Enter the Department name of user " << i + 1 << ": ";
		//string nam;
		//cin.ignore();
		getline(cin, name1);
		//cout << name1 << endl;
		a[i].setdep_nam(name1);

	}
	for (int i = 0; i < siz; i++) {
		cout << "Data of user: " << i + 1 << endl;
		a[i].display();
	}
}