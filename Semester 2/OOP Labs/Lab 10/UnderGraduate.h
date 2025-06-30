#pragma once
#include"Person.h"

class UnderGraduate :public Person {
private:
	float cgpa;
	int rollno;
	string fyp; //Final Year Project
	string supname;//supervisor name
public:
	int getage();
	int getcgpa();
	string getfyp();
	string getsupname();
	int getrolno();
	void setrolno(int a);
	void setfyp(string);
	void setsupname(string);
	void setcgpa(int a);
};


