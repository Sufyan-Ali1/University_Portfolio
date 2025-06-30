#include "Person.h"
#include<string>
#include<iostream>
using namespace std;

void Person::setage(int a) {
	age = a;
}
void Person::setFname(string a) {
	Fname = a;
}
void Person::setLname(string a) {
	Lname = a;
}
string Person::getLname() {
	return Lname;
}
string Person::getFname() {
	return Fname;
}
