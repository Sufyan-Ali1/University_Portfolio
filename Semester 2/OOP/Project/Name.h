#pragma once
#include<iostream>
using namespace std;
class Name
{

	char* Fname;
	char* Lname;
public:
	Name(char * , char* );
	Name();
	
	void setFname(char*);
	void setLname(char*);
	char* getFname()const;
	char* getLname()const;
	void removename();
	Name operator=(const Name& a);
	Name(const Name& A);
	Name getname();
	friend ostream& operator<<(ostream &, Name&);
	~Name();



};

Name::Name(char* fn, char* ln) {
	Fname = new char[12];
	int i;
	for (i = 0; fn[i] != '\0'; i++) {
		Fname[i] = fn[i];
	}
	Fname[i] = '\0';
	Lname = new char[12];
	for (i = 0; ln[i] != '\0'; i++) {
		Lname[i] = ln[i];
	}
	Lname[i] = '\0';
	
}
Name::Name() {
	Fname = new char[12];
	Fname[0] = '\0';
	Lname = new char[12];
	Lname[0] = '\0';

}
void Name::setFname(char* fn) {
	int i;
	if (fn == nullptr) {
		Fname = nullptr;
		
	}
	else {
		for (i = 0; fn[i] != '\0'; i++) {
			Fname[i] = fn[i];
		}
		Fname[i] = '\0';
	}
	
}
void Name::setLname(char* ln) {
	int i;
	if (ln == nullptr) {
		Lname = nullptr;

	}
	else {
		for (i = 0; ln[i] != '\0'; i++) {
			Lname[i] = ln[i];
		}
		Lname[i] = '\0';
	}
}
char* Name::getFname()const {
	return Fname;
	
	
}
char* Name::getLname()const {
	return Lname;
}
Name::Name(const Name& A) {
	Fname = new char[12];
	Lname = new char[12];
	int i;
	for ( i = 0; A.Fname[i] != '\0'; i++) {
		Fname[i] = A.Fname[i];
	}
	Fname[i]='\0';
	for ( i = 0; A.Lname[i] != '\0'; i++) {
		Lname[i] = A.Lname[i];
	}
	Lname[i] = '\0';

}
Name Name::operator=(const Name& A) {
	Fname = new char[12];
	Lname = new char[12];
	int i;
	for (i = 0; A.Fname[i] != '\0'; i++) {
		Fname[i] = A.Fname[i];
	}
	Fname[i] = '\0';
	for (i = 0; A.Lname[i] != '\0'; i++) {
		Lname[i] = A.Lname[i];
	}
	Lname[i] = '\0';
	return *this;
}
ostream& operator<<(ostream& out,  Name& n) {
	out << "Name: " << n.getFname() << " " << n.getLname() << endl;
	return out;
}
Name Name::getname() {
	return *this;
}
Name::~Name() {
	if (Fname != nullptr) {
		delete[]Fname;
		Fname = NULL;
	}
	if (Lname != nullptr) {
		delete[]Lname;
		Lname = NULL;
	}
	
}
void Name::removename() {
	Fname = nullptr;
	Lname = nullptr;
}
