#pragma once
#include"UnderGraduate.h"
#include"Person.h"

class Graduate : public UnderGraduate,public Person {
private:
	float cgpa;
	int rollno;
	string thetop;//theisis topic
	string supname;//supervisor name
public:
	int getage();
	
	int getcgpa();
	string getthetop();
	string getsupname();
	int getrolno(); 
	void setrolno(int a);
	void setthetop(string);
	void setsupname(string);
	void setcgpa(int a);
};

