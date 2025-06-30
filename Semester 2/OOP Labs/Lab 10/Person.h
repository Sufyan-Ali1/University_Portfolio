#pragma once

class Person
{
private:
	string Fname;
	string Lname;
protected:
	int age;
public:
	void setage(int a);
	void setFname(string);
	void setLname(string);
	string getFname();
	string getLname();

};

