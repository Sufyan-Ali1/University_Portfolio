#include<iostream>
#include<string>
using namespace std;
class person{
	string name;
	int yob;//year of birth
public:
	person(string = "", int = 0);
	int getyob();
	string getname();
};
person::person(string a,int b){
	name = a;
	yob = b;

}
string person::getname(){
	return name;
}
int person::getyob(){
	return yob;
}

class student :public person
{
	int studid;
	int enrlsem;
public:
	student(string="", int = 0, int = 0,int =0);
	void display();
};
student::student(string a, int b,int c,int d):person(a,b){
	studid = c;
	enrlsem = d;
}
void student::display(){
	cout << "Name: " << getname();
	cout << "Student id: " << studid;
	cout << "Year of Birth: " << getyob();
	cout << "Enrolled Semester: " << enrlsem;
}

class employee 
{
protected:
	int emloyeeid;
	int jyear;//joining year
	string jobttl;// job title
	int courseid;
	string coursettl;//course title

	employee( int = 0, int = 0, int = 0, string = "", string = "");
	employee(string = "", string = "",int = 0, int = 0, int = 0);
};
employee::employee(int c, int d, int e, string f, string g)
{
	emloyeeid = c;
	jyear = d;
	courseid = e;
		jobttl = f;
		coursettl = g;
			
}
employee::employee(string f, string g, int c, int d, int e )
{
	emloyeeid = c;
	jyear = d;
	courseid = e;
	jobttl = f;
	coursettl = g;

}
class administration:public employee
{
public:
	administration(int a , int b , int c, string d , string e ) :employee(a, b, c)
	{

	}
	void setjobttl(string a){
		jobttl = a;
	}
	string getjobttl(){
		return jobttl;
	}

};
class academic :public employee
{
public:
	academic(int , int  , int  , string , string );
	void setcourseid(int a){
		emloyeeid = a;
	}
	void setcoursettl(string a){
		coursettl = a;
	}
};
academic::academic(int a , int b , int c , string d , string e ) : employee(a, b, c, d, e)
{

}
void main(){
	system("pause");
}