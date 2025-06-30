#include "Graduate.h"
#include"UnderGraduate.h"
#include"Person.h"
#include<string>
#include<iostream>
using namespace std;

int Graduate::getage() {
	return Person::age;

}
int Graduate::getcgpa() {
	return cgpa;
}
string Graduate::getthetop() {
	return thetop;
}
string Graduate::getsupname() {
	return supname;
}
int Graduate::getrolno() {
	return rollno;
}
void Graduate::setrolno(int a) {
	rollno = a;
}
void Graduate::setcgpa(int a) {
	cgpa = a;
}
void Graduate::setthetop(string a) {
	thetop = a;
}
void Graduate::setsupname(string a) {
	supname = a;
}
