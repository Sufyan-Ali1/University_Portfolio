#include "UnderGraduate.h"
#include<string>
#include"Person.h"
#include<iostream>
using namespace std;

int UnderGraduate::getage() {
	return age;
}
int UnderGraduate::getcgpa() {
	return cgpa;
}
string UnderGraduate::getfyp() {
	return fyp;
}
string UnderGraduate::getsupname() {
	return supname;
}
int UnderGraduate::getrolno() {
	return rollno;
}
void UnderGraduate::setrolno(int a) {
	rollno = a;
}
void UnderGraduate::setcgpa(int a) {
	cgpa = a;
}
void UnderGraduate::setfyp(string a) {
	fyp = a;
}
void UnderGraduate::setsupname(string a) {
	supname = a;
}
