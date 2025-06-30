#pragma once
#include"Service.h"
#include<iostream>
using namespace std;
class Delivery:public Service
{
	float gweight;//goods weight
	char* gtype;//goods type

public:
	
	Delivery();
	Delivery(const Delivery &);
	Delivery operator=(const Delivery&);
	void setGw8(float);
	void setGtype(char*);
	void printservice();
	float getGw8()const;
	char* getGtype()const;
	friend ostream& operator<<(ostream&, Delivery&);
	~Delivery();
};
//------------CONSTRUCTOR--------------
Delivery::Delivery() {

	gtype = new char[20];
	gweight = 0;
}
//------------------COPY CONSTRUCTOR---------------
Delivery::Delivery(const Delivery& a) {
	gtype = new char[20];
	gweight = a.getGw8();

	char* x = a.getGtype();
	int i = 0;
	
	for (; x[i] != '\0'; i++) {
		gtype[i] = x[i];
	}                              ////
	gtype[i] = '\0';


	setsource(a.getsource());//
	setdestination(a.getdestination());//
	setbokdate(a.getbokdate());
	setboktime(a.getboktime());
	setdid(a.getdid());
	setcid(a.getcid());
	setvid(a.getvid());
	setdistance(a.getdistance());
	setstatus(a.getstatus());
	setfuelrate(a.getfuelrate());

	
}
//-----------------DESTRUCTOR------------------------
Delivery::~Delivery() {
	if (gtype != nullptr) {
		delete[]gtype;
		gtype = nullptr;
	}
}
//-----------------ASSIGNMENT OPERATOR-----------------
Delivery Delivery::operator=(const Delivery& a) {
	gtype = new char[20];
	gweight = a.getGw8();
	char* x=a.getGtype();
	int i = 0;
	
	for (; x[i] != '\0'; i++) {
		gtype[i] = x[i];
	}
	gtype[i] = '\0';
	

	setbokdate(a.getbokdate());
	setboktime(a.getboktime());
	setdid(a.getdid());
	setcid(a.getcid());
	setvid(a.getvid());
	setdistance(a.getdistance());
	setstatus(a.getstatus());
	setfuelrate(a.getfuelrate());
	
	setsource(a.getsource());
	
	setdestination(a.getdestination());
	
	return a;
}
//----------------SETTER---------------------------
void Delivery::setGw8(float a) {
	gweight = a;
}
void Delivery::setGtype(char* a) {
	int i = 0;
	gtype = new char[25];
	for (; a[i] != '\0'; i++) {
		gtype[i] = a[i];
	}
	gtype[i] = '\0';
}
//----------------GETTER-------------------
float Delivery::getGw8()const {
	return gweight;
}
char* Delivery::getGtype()const {
	return gtype;

}
void Delivery::printservice() {
	Date a = getbokdate();
	mTime b = getboktime();
	cout << "Delivery Detail\n";
	cout << "Goods Type:" <<gtype  << endl;
	cout << "Goods Weight: " << gweight << endl;
	cout << "Delivery Book Date: " << a << "Delivery Book Time: " << b;
	cout << "Source:" << getsource() << " and Destination: " << getdestination() << endl;
	cout << "Fuel Rate:" << getfuelrate() << endl;
	cout << "Distance:" << getdistance() << endl;
	cout << "Vehicle Id:" << getvid() << "," << "Driver Id:" << getdid() << "," << "Customer Id:" << getcid() << endl;
	if (getstatus() == 1) {
		cout << "Delivery Complete\n";
	}
	else {
		cout << "Delivery in pending\n";
	}

}
ostream& operator<<(ostream& ob, Delivery& a) {
	Date c = a.getbokdate();
	mTime b = a.getboktime();
	cout << "Delivery Detail\n";
	cout << "Goods Type:" << a.gtype << endl;
	cout << "Goods Weight: " << a.gweight << endl;
	cout << "Delivery Book Date: " <<c << "Delivery Book Time: " << b;
	cout << "Source:" << a.getsource() << " and Destination: " << a.getdestination() << endl;
	cout << "Fuel Rate:" << a.getfuelrate() << endl;
	cout << "Distance:" << a.getdistance() << endl;
	cout << "Vehicle Id:" << a.getvid() << "," << "Driver Id:" << a.getdid() << "," << "Customer Id:" << a.getcid() << endl;

	/*if (a.getstatus() == 1) {
		cout << "Delivery Complete\n";
	}
	else {
		cout << "Delivery in pending\n";
	}*/
	return ob;
}

