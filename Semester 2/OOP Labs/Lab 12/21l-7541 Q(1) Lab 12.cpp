#include<iostream>
#include<string>
using namespace std;
class person{
	string fullname;
	int height;
public:
	person(string = "\0", int = 0);
	virtual ~person();
	virtual void printInfo();
};
person::person(string name, int height){
	this->fullname = fullname;
	this->height = height;
	cout << "constructor of person\n";
}
person::~person(){
	cout << "Destructor of person\n";
}
void person::printInfo(){
	cout << "Name:" << fullname << endl;
	cout << "Height:" << height << endl;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Student :public person
{
public:
	Student(string= "" , string="\0",int=0);
	~Student();

private:
	string schoolname;
};

Student::Student(string fullname, string schoolname, int id) :person(fullname,id)
{
	this->schoolname;
}

Student::~Student()
{
	cout << "Destructor of student\n";
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class employee:public person
{
public:
	employee(string = "", string = "\0", int = 0, int = 0);
	~employee();
	void printInfo();
private:
	string department;
	int id;
};

employee::employee(string name, string departement, int	height, int id) :person(name,height)
{
	this->department = departement;
	this->id = id;
	cout << "Construnctor of employee\n";
}
void employee::printInfo(){
	person::printInfo();
	cout << "Department:" << department << endl;
	cout << "Id: " << id << endl;
}
employee::~employee()
{
	cout << "Destructor of employee\n";
}

void main(){
	
	person *p1,*p2;
	p1 = new employee("Sufyan", "BSCS", 3, 2567);
	p1->~person();
	p2 = new Student("Roohan", "OPF", 8);
	p2->~person();
	system("pause");
}