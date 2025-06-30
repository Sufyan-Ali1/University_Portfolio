#pragma once
#include"Service.h"
#include<iostream>
using namespace std;
class Ride :public Service
{
	int nop;//no of passengers
	char* ridetype;//intercity intracity
	float DriverRank;
	float VehicleRank;
public:
	Ride() {
		ridetype = new char[20];
		DriverRank = 0;
		VehicleRank = 0;
		nop = 0;
	}
	~Ride();
	void setnop(int);
	void setRtype(char*);
	void setD_rank(float);
	void setV_rank(float);
    int getnop()const;
	char* getRtype()const;
	float getD_rank()const;
	float getV_rank()const;
	Ride(const Ride&);
	Ride operator=(const Ride&);
	friend ostream & operator<<(ostream&, Ride&);
	void printservice();
	
};

//------------------------Setter--------------
void Ride::setD_rank(float a) {
	DriverRank = a;

}
void Ride::setV_rank(float a) {
	VehicleRank = a;

}

void Ride::setRtype(char * a) {
	int i = 0;
	for (; a[i] != '\0'; i++) {
		ridetype[i] = a[i];
	}
	ridetype[i] = '\0';

}
void Ride::setnop(int a) {
	nop = a;

}
//--------------------------GETTER---------------------
int Ride::getnop()const{
	return nop;

}
float Ride::getD_rank()const {
	return	DriverRank;

}
float Ride::getV_rank()const{
	return	VehicleRank;

}

char* Ride::getRtype()const {	
	return ridetype;

}
//--------------------Copy Constructor-----------------
Ride::Ride(const Ride& a) {
	ridetype = new char[20];

	nop = a.getnop();
	char* v;	
	v=a.getRtype();
	int i;
	for ( i = 0; v[i] != '\0'; i++) {
		ridetype[i] = v[i];
	}
	ridetype[i] = '\0';
	
	DriverRank = a.getD_rank();	
	VehicleRank = a.getV_rank();
	setsource(a.getsource());
	setdestination(a.getdestination());
	setbokdate(a.getbokdate());
	setboktime(a.getboktime());
	setdid(a.getdid());
	setcid(a.getcid());
	setvid(a.getvid());
	setdistance(a.getdistance());
	setstatus(a.getstatus());
	setfuelrate(a.getfuelrate());
	
}
//--------------------ASSIGNMENT OPERATOR---------------------
Ride Ride::operator=(const Ride& a) {
	ridetype = new char[20];

	nop = a.getnop();
	char* v;

	v = a.getRtype();
	int i;
	for (i = 0; v[i] != '\0'; i++) {
		ridetype[i] = v[i];
	}
	ridetype[i] = '\0';

	DriverRank = a.getD_rank();
	VehicleRank = a.getV_rank();
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
ostream& operator<<(ostream& ob, Ride& a) {
	Date c = a.getbokdate();
	mTime b = a.getboktime();
	cout << "Ride Detail\n";
	cout << "Ride Type:" << a.ridetype << endl;
	cout << "No of Person: " << a.nop << endl;
	cout << "Ride Book Date: " <<c << "Ride Book Time: " << b;
	cout << "Source:" << a.getsource() << " and Destination: " << a.getdestination() << endl;
	cout << "Fuel Rate:" <<a. getfuelrate() << endl;
	cout << "Distance:" << a.getdistance() << endl;
	cout << "Vehicle Id:" << a.getvid() << "," << "Driver Id:" << a.getdid() << "," << "Customer Id:" << a.getcid() << endl;
	/*if (a.getstatus() == 1) {
		cout << "Ride Complete\n";
	}
	else {
		cout << "Ride in pending\n";
	}*/

	return ob;

}
void Ride::printservice(){
	Date a=getbokdate();
	mTime b=getboktime();
	cout << "Ride Detail\n";
	cout << "Ride Type:" << ridetype << endl;
	cout << "No of Person: " << nop << endl;
	cout << "Ride Book Date: " << a << "Ride Book Time: " << b;
	cout << "Source:" << getsource() << " and Destination: " << getdestination() << endl;
	cout << "Fuel Rate:" << getfuelrate() << endl;
	cout << "Distance:" << getdistance() << endl;
	cout << "Vehicle Id:" << getvid() << "," << "Driver Id:" << getdid() << "," <<"Customer Id:"<<getcid() << endl;
	if (getstatus() == 1) {
		cout << "Ride Complete\n";
	}
	else {
		cout << "Ride in pending\n";
	}

}
//-------------DESTRUCTOR--------------
Ride::~Ride() {
	if (ridetype != nullptr) {
		delete[]ridetype;
		ridetype = nullptr;
	}
	
}

