#pragma once
#include"Person.h"
#include"Name.h"
#include"Service.h"
#include<iostream>
#include"Date.h"
#include<ctime>
#include"Delivery.h"
#include"Ride.h"
using namespace std;
class Customer :public Person
{
private:
	int cid;
	Service** bookhis;//booking history
	Ride *R;
	Delivery* D;

	int Rlen;//no of rides

	int Dlen;//no of delivery
public:
	Customer();

	Customer(Customer& A);
	void operator=(Customer&);
	void setcid(int);
	int getcid();
	int getRlen();
	int getDlen();
	int getstatusR(int);
	int getstatusD(int);

	Ride getride(int i)const {
		return R[i];
	}
	Delivery getdelivery(int i)const {
		return D[i];
	}
	friend ostream& operator<<(ostream&, Customer&);
	void setstatusR(int a) {
		R[0].setstatus(a);
	}
	void setride(const Ride& a);
	void setdel(Delivery);
	void printcustom();
	~Customer();

};

Customer::Customer() {
	bookhis = new Service * [2];
	
	
	R = new Ride[10];
	D = new Delivery[10];
   bookhis[0] = R;
	bookhis[1] = D;
	Rlen = 0;
	Dlen = 0;
	cid = 0;
}
Customer::Customer( Customer& A) {
	setage(A.getage());
	cid = A.getid();
	setid(cid);
	Rlen = A.Rlen;
	Dlen = A.Dlen;
	bookhis = new Service * [2];
	bookhis[0] = new Ride[10];
	bookhis[1] = new Delivery[10];
	
	setdob(A.getdob());
	setname(A.getFname() , A.getLname());
	
	for (int i = 0; i < Dlen; i++) {
		D[i] = A.D[i];
		
	}
	for (int i = 0; i < Rlen; i++) {
		R[i] = A.R[i];
		
	}
	bookhis[0] = R;
	bookhis[1] = D;
}
void Customer::operator=(Customer& A) {
	setage(A.getage());
	cid = A.getid();
	setid(cid);
	Rlen = A.Rlen;
	Dlen = A.Dlen;
	bookhis = new Service * [2];
	bookhis[0] = new Ride[10];
	bookhis[1] = new Delivery[10];

	setdob(A.getdob());
	setname(A.getFname(), A.getLname());

	for (int i = 0; i < Dlen; i++) {
		D[i] = A.D[i];

	}
	for (int i = 0; i < Rlen; i++) {
		R[i] = A.R[i];

	}
	bookhis[0] = R;
	bookhis[1] = D;
}
Customer::~Customer() {
	delete[]bookhis[0];
	delete[]bookhis[1];
	delete[]bookhis;
}

int Customer::getcid() {
	return cid;
}
int Customer::getRlen() {
	return Rlen;
}
int Customer::getDlen() {
	return Dlen;
}
void Customer::setcid(int a) {
	cid = a;
	setid(cid);
}

void Customer::setride(const Ride& a) {
	
	R[Rlen] = a;
	Rlen++;
	bookhis[0] = R;

	
}
void Customer::setdel(Delivery a) {
	D[Dlen] = a;
	Dlen++;
	
	bookhis[1] = D;

	
}
ostream& operator<<(ostream& ob, Customer& a) {
	Date b;
	b = a.getdob();
	cout << "Customer Detail\n";
	ob << "Name:" << a.getFname() << " " << a.getLname() << endl << "ID: " << a.cid << endl << "Date of Birth:" << b << endl;
	ob << "Age:" << a.getage() << endl<<"Customer has "<<a.Rlen<<" Rides and "<<a.Dlen<<" Deliveries"<<endl;
	int x=0, y=0;
	for (int i = 0; i < a.Rlen; i++) {
		if (a.bookhis[0][i].getstatus()) {
			x++;
		}
		else {
			y++;
		}
	}
	ob << "Customers complete " << x << " rides and " << y << " Rides in pending\n";
	x = 0;
	y = 0;
	for (int i = 0; i < a.Dlen; i++) {
		if (a.bookhis[1][i].getstatus()) {
			x++;
		}
		else {
			y++;
		}
	}
	ob << "Customers complete " << x << " deliveries and " << y << " deliveries in pending\n";
	x = 0;
	y = 0;

	return ob;
}
void Customer::printcustom() {
	cout << "Customer has Total " << Rlen << " Rides and " << Dlen << " Deliveries\n";
	for (int i = 0; i < Rlen; i++) {
		cout << "Ride "<<i+1 <<":" << endl;
		if (i == 0) {
			bookhis[0][i].printservice();
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
			bookhis[1][i].printservice();
			cout << endl;
		}
		else {
			D[i].printservice();
			cout << endl;
		}

	}
}
int Customer::getstatusR(int a) {
	return R[a].getstatus();
}
int Customer::getstatusD(int a) {
	return D[a].getstatus();
}

