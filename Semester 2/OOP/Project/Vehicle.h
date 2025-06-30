#pragma once
#include"Date.h"
#include"Feature.h"
#include"Service.h"
#include<iostream>
using namespace std;
class Vehicle
{
	int vId;//vehicle id
	int regno;//registeration no
	float avgmil;//average milage
	char* lsctype;//lisence type
	int status;
	char* fueltype;
	float Orank;//over all ranking
	Date mfg;//manufacturing date
	Feature* list;
	Service** serHis;//service history
	Ride* R;
	Delivery* D;
	
	int Rlen;//no of rides
	int Flen;
	int Dlen;//no of delivery
public:
	//Vehicle(int, int, float, char*, bool, char*, float, Date, Feature&, Service**);
	Vehicle();
	Vehicle(Vehicle&);
	void operator=(const Vehicle&);
	void setvid(int);
	void setregno(int);
	void setavgmil(float);
	void setlsctyp(char*);
	void setstatus(int);
	void setfueltype(char*);
	void setOrank(float);
	void setride(const Ride&);
	void setdel(const Delivery&);
	void setmfg(Date);
	void setfeature(Feature);
	void setlis(Feature*);
	void setFlen(int);
	void printvehicle();


	int getstatusR(int );
	int getstatusD(int );
	int getvid();
	int getregno();
	float getavgmil();
	char* getlsctyp();
	int getstatus();
	char* getfueltype();
	float getOrank();
	int getRlen();
	int getDlen();
	int getFlen();
	Date getmfg();
	friend ostream& operator<<(ostream& ob, Vehicle& a);
	Feature getFeat(int);
	Ride getride(int i)const {
		return R[i];
	}
	Delivery getdelivery(int i)const {
		return D[i];
	}
	void removevehicle();
	~Vehicle();
};

Vehicle::Vehicle() {
	vId = 0;
	regno = 0;
	avgmil = 0;
	status = 0;
	lsctype = new char[20];
	fueltype = new char[10];
	Orank = 0;
	serHis = new Service*[2];
	list = new Feature[10];
	R = new Ride[10];
	D = new Delivery[10];
	serHis[0] = R;
	serHis[1] = D;
	Rlen = 0;
	Dlen = 0;
	Flen = 0;
}
Vehicle::~Vehicle() {
	if (fueltype != nullptr) {
		delete[]fueltype;
		fueltype = nullptr;
	}
	if (lsctype != nullptr) {
		delete[]lsctype;
		lsctype = nullptr;
	}
}
//--------------------SETTER----------------------------
void Vehicle::setavgmil(float a) {
	avgmil = a;
}
void Vehicle::setfueltype(char* a) {
	int i=0;
	fueltype = new char[10];
	for (; a[i] != '\0'; i++) {
		fueltype[i] = a[i];
	}
	fueltype[i] = '\0';
}
void Vehicle::setlsctyp(char* a) {
	int i = 0;
	lsctype = new char[20];
	for (; a[i] != '\0'; i++) {
		lsctype[i] = a[i];
	}
	lsctype[i] = '\0';
}
void Vehicle::setOrank(float a) {
	Orank = a;
}
void Vehicle::setregno(int a) {
	regno = a;
}
void Vehicle::setstatus(int a) {
	status = a;
}
void Vehicle::setvid(int a) {
	vId = a;
}
void Vehicle::setdel(const Delivery& a) {
	D[Dlen] = a;
	Dlen++;
	serHis[1] = D;
}
void Vehicle::setride(const Ride& a) {
	R[Rlen] = a;
	Rlen++;
	serHis[0] = R;
}
void Vehicle::setmfg(Date a) {
	mfg = a;
}
void Vehicle::setfeature(Feature a) {
	list[Flen] =a;
	Flen++;
}
//--------------------------------GETTER-------------------------------
float Vehicle::getavgmil() {
	return avgmil;
}
int Vehicle::getvid() {
	return vId;
}
int Vehicle::getregno() {
	return regno;
}

char* Vehicle::getlsctyp() {
	return lsctype;
}
int Vehicle::getstatus() {
	return status;
}
char* Vehicle::getfueltype() {
	return fueltype;
}
float Vehicle::getOrank() {
	return Orank;
}
int Vehicle::getRlen() {
	return Rlen;
}
int Vehicle::getDlen() {
	return Dlen;
}
Date Vehicle::getmfg() {
	return mfg;
}
//-----------------------------------COPY CONSTRUCTOR-----------------------------
Vehicle::Vehicle(Vehicle& a) {
	avgmil = a.avgmil;
	vId = a.vId;
	regno = a.regno;
	status = a.status;
	Rlen = a.Rlen;
	Dlen = a.Dlen;
	Flen = a.Flen;
	Orank = a.Orank;
	mfg = a.mfg;
	
	list = new Feature[10];
	int i;
	for ( i = 0; i < Flen; i++) {
		list[i] = a.list[i];
	}

	lsctype = new char[20];
	for ( i = 0; a.lsctype[i] != '\0'; i++) {
		lsctype[i] = a.lsctype[i];
	}
	lsctype[i] = '\0';

	fueltype = new char[10];
	for ( i = 0; a.fueltype[i] != '\0'; i++)
	{
		fueltype[i] = a.fueltype[i];
	}
	fueltype[i] = '\0';

	serHis = new Service * [2];
	serHis[0] = new Ride[10];
	serHis[1] = new Delivery[10];

	for (int i = 0; i < Dlen; i++) {
		D[i] = a.D[i];

	}
	for (int i = 0; i < Rlen; i++) {
		R[i] = a.R[i];

	}
	serHis[0] = R;
	serHis[1] = D;
}
//----------------------------ASSIGNMENT OPERATOR------------------------------
void Vehicle::operator=(const Vehicle& a) {
	avgmil = a.avgmil;
	vId = a.vId;
	regno = a.regno;
	status = a.status;
	Rlen = a.Rlen;
	Dlen = a.Dlen;
	Flen = a.Flen;
	Orank = a.Orank;
	mfg = a.mfg;

	list = new Feature[10];
	int i;
	for (i = 0; i < Flen; i++) {
		list[i] = a.list[i];
	}

	lsctype = new char[20];
	for (i = 0; a.lsctype[i] != '\0'; i++) {
		lsctype[i] = a.lsctype[i];
	}
	lsctype[i] = '\0';

	fueltype = new char[10];
	for (i = 0; a.fueltype[i] != '\0'; i++)
	{
		fueltype[i] = a.fueltype[i];
	}
	fueltype[i] = '\0';

	serHis = new Service * [2];
	serHis[0] = new Ride[10];
	serHis[1] = new Delivery[10];

	for (int i = 0; i < Dlen; i++) {
		D[i] = a.D[i];

	}
	for (int i = 0; i < Rlen; i++) {
		R[i] = a.R[i];

	}
	serHis[0] = R;
	serHis[1] = D;
}
void Vehicle::setFlen(int a) {
	Flen = a;
}
void Vehicle::setlis(Feature* a) {
	
	for (int i = 0; i < Flen; i++) {
		list[i] = a[i];
	}
}
void Vehicle::removevehicle() {
	vId = -1;
	regno = 0;
	avgmil = 0;
}
int Vehicle::getFlen() {
	return Flen;
}
Feature Vehicle::getFeat(int a) {
	return list[a];
}
void Vehicle::printvehicle() {
	cout << "Vehicle has Total " << Rlen << " Rides and " << Dlen << " Deliveries\n";
	for (int i = 0; i < Rlen; i++) {
		cout << "Ride " << i + 1 << ":" << endl;
		if (i == 0) {
			serHis[0][i].printservice();
			cout << endl;
		}
		else {
			R[i].printservice();
			cout << endl;
		}

	}
	for (int i = 0; i < Dlen; i++) {
		cout << "Delivery " << i + 1 << ":" << endl;
		if (i == 0) {
			serHis[1][i].printservice();
			cout << endl;
		}
		else {
			D[i].printservice();
			cout << endl;
		}

	}
}
ostream& operator<<(ostream& ob, Vehicle& a) {
	Date b = a.getmfg();

	ob << "Vehicle Detail\n";
	ob << "Vehicle Id:" << a.vId << endl << "Registeration Number:" << a.regno << endl;
	ob << "Manufacturing Date:" << b;
	ob << "Total Features:" << a.Flen;
	ob << "Feature Name" << endl;
	for (int i = 0; i < a.Flen; i++) {
		ob << i + 1 << ")" << a.list[i] ;
	}
	ob << "Average Mileage:" << a.avgmil << endl << "License Required:" << a.lsctype << endl << "Overall Rating:" << a.Orank << endl;
	ob << "Fuel Type:" << a.fueltype << endl;
	if (a.status) {
		cout << "Vehicle is Booked\n";
	}
	else {
		cout << "Vehicle is Free\n";
	}
	return ob;
}
int Vehicle::getstatusR(int a){
	return R[a].getstatus();
}
int Vehicle::getstatusD(int a) {
	return D[a].getstatus();
}
