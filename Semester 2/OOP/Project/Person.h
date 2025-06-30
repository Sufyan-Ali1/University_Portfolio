#pragma once
#include"Name.h"
#include"Date.h"
#include<iostream>
using namespace std;
class Person
{
	Name pName;
	Date DOB;//Date of Birth
	int age;
	int Nid;
public:
	Person(Name, Date, int, int);
	Person();
	Person(const Person&);
	void setname(char* a, char* b);
	void setnames(const Name&);
	void setdob(const Date);
	void setage(int);
	void setid(int);
	Name getname()const;
	Date getdob()const;
	int getage()const;
	int getid()const;
	char* getFname()const;
	char* getLname()const;
	Person operator=(const Person&);
	void removeperson();
	friend ostream& operator<<(ostream& , Person&);

};
Person::Person() {
	age = 0;
	Nid = 0;
}
Person::Person(Name A, Date B, int c, int d) {
	pName = A;
	DOB = B;
	age = c;
	Nid = d;

}
Person::Person(const Person& ob) {
	pName = ob.pName;
	DOB = ob.DOB;
	age = ob.age;
	Nid = ob.Nid;
}

void Person::setname(char* a, char* b) {
	pName.setFname(a);
	pName.setLname(b);
	
}
void Person::setdob(const Date a) {
	DOB = a;
	
}
Person Person::operator=(const Person& ob) {
	pName = ob.pName;
	DOB = ob.DOB;
	age = ob.age;
	Nid = ob.Nid;
	return ob;
}
ostream& operator<<(ostream& ob, Person& a) {
	ob << a.pName << endl << a.DOB << endl << "Age=" << a.age << endl << "Id= " << a.Nid << endl;
	return ob;
}
void Person::setage(int a) {
	age = a;
}
void Person::setid(int a) {
	Nid = a;
}
int Person::getid() const {
	return Nid ;
}
int Person::getage() const {
	return age;
}
Name Person::getname() const {
	return pName;
}
Date Person::getdob() const {
	return DOB;
}
void Person::setnames(const Name& a) {
	pName = a;
}
char* Person::getFname() const {
	return pName.getFname();
}
char* Person::getLname() const {
	return pName.getLname();
}
void Person::removeperson() {
	DOB.setday(0);
	DOB.setmonth(0);
	DOB.setyear(0);
	pName.setFname(nullptr);
	pName.setLname(nullptr);
}