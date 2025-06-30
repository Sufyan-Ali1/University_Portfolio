#include<iostream>
#include<string>
using namespace std;
class person{
protected:
	string name;
	int age;
public:
	virtual void print()= 0;
	person(string a = "", int b = 0){
		name = a;
		age = b;
	}
};
class patient :public person
{
protected:
	string disease;
	string recom_medicine;
public:
	void print(){
		cout << "Name:" << name << " age " << age << " Diesease Type: " << disease << " required medicine " << recom_medicine;
	}
	patient() :person("Ali",20)
	{
		disease = "Headache";
		recom_medicine = "panadol";
	}
};
class MedicarePatient :public patient
{
	string hsptlname;
	string wardname;
	int rno;
public:
	void print(){
		patient::print();
		cout << " " << hsptlname << " " << wardname << endl;
	}
	MedicarePatient() :patient()
	{
		hsptlname = "Doctors";
		wardname = "abcd";
	}
};
void main(){
	person *p;
	patient p1;
	p = &p1;
	p->print();
	cout << endl;
	MedicarePatient p2;
	p = &p2;
	p->print();
	system("pause");
}