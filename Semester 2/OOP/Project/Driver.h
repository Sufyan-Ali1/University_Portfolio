#pragma once
#include"Person.h"
#include"Service.h"
#include<iostream>
using namespace std;
class Driver :public Person
{
	int dId;
	char** Lisencelist;
	int noofl;//no of lisence
	float Orank;//Over all ranking
	float Salary;
	int exp;//experience
	int status;
	Service** serhis;//Service History
	Ride* R;
	Delivery* D;

	int Rlen;//no of rides

	int Dlen;//no of delivery
public:
	
	Driver();
	Driver(Driver&);
	//-----setter
	void operator=(const Driver&);
	void setdid(int);
	void setnoofl(int);
	void setOrank(float);
	void setsal(float);//set salary
	void setexp(int);
	void setstatus(int);
	void setLislist(char**);
	void setRlen(int);
	void setDlen(int);
	void setride(const Ride& a);
	void setdel(Delivery);
	void printdriver();
	void printlislist();
	//--------getter
	char** getLislist()const;
	int getdid()const;
	int getnoofl()const;
	float getOrank()const;
	int getstatusR(int);
	int getstatusD(int);
	float getsal()const;//set salary
	int getexp()const;
	int getstatus()const;
	int getRlen()const;
	int getDlen()const;
	Ride getride(int i)const {
		return R[i];
	}
	Delivery getdelivery(int i)const {
		return D[i];
	}
	friend ostream& operator<<(ostream&, Driver&);
	void removedriver();
	~Driver();

};

//-------------CONSTRUCTOR------------------
Driver::Driver() {
   
   noofl = 0;
   status = 0;
   exp = 0;
   Salary = 0;
   Orank = 0;
	R = new Ride[10];
	D = new Delivery[10];
	Lisencelist = new char*[noofl];
	
	for (int i = 0; i < noofl; i++) {
		Lisencelist[i] = new char[20];
		Lisencelist[i][0] = '\0';
	}
	serhis = new Service * [2];
	serhis[0] = R;
	serhis[1] = D;
	Rlen = 0;
	Dlen = 0;
	dId = 0;
}
//------------------COPY CONSTRUCTOR--------------
Driver::Driver(Driver& A) {
	int j;
	setage(A.getage());
	
	setid(A.getid());
	Rlen = A.Rlen;
	Dlen = A.Dlen;
	noofl = A.getnoofl();

	status = A.getstatus();
	exp = A.getexp();
	Salary = A.getsal();
	Orank = A.getOrank();
	serhis = new Service * [2];
	serhis[0] = new Ride[10];
	serhis[1] = new Delivery[10];

	setdob(A.getdob());
	setname(A.getFname(), A.getLname());
	Lisencelist = new char* [noofl];
	for (int i = 0; i < noofl; i++) {
		Lisencelist[i] = new char[20];
		for (j = 0; A.Lisencelist[i][j] != '\0'; j++) {
			Lisencelist[i][j] = A.Lisencelist[i][j];

		}
		Lisencelist[i][j] = '\0';
	}
	
	for (int i = 0; i < Dlen; i++) {
		D[i] = A.D[i];

	}
	for (int i = 0; i < Rlen; i++) {
		R[i] = A.R[i];

	}
	serhis[0] = R;
	serhis[1] = D;
}
//-------------------------ASSIGNMENT OPERATOR-------------------------
void Driver::operator=(const Driver& A) {
	int j;
	setage(A.getage());

	setid(A.getid());
	Rlen = A.Rlen;
	Dlen = A.Dlen;
	noofl = A.getnoofl();

	status = A.getstatus();
	exp = A.getexp();
	Salary = A.getsal();
	Orank = A.getOrank();
	serhis = new Service * [2];
	serhis[0] = new Ride[10];
	serhis[1] = new Delivery[10];

	setdob(A.getdob());
	setname(A.getFname(), A.getLname());
	Lisencelist = new char* [noofl];
	for (int i = 0; i < noofl; i++) {
		Lisencelist[i] = new char[20];
		for (j = 0; A.Lisencelist[i][j] != '\0'; j++) {
			Lisencelist[i][j] = A.Lisencelist[i][j];

		}
		Lisencelist[i][j] = '\0';
	}

	for (int i = 0; i < Dlen; i++) {
		D[i] = A.D[i];

	}
	for (int i = 0; i < Rlen; i++) {
		R[i] = A.R[i];

	}
	serhis[0] = R;
	serhis[1] = D;
}
Driver::~Driver() {
	if (Lisencelist != nullptr) {
		for (int i = 0; i < noofl; i++) {
			delete[]Lisencelist[i];
		}
		Lisencelist = nullptr;
		
	}
	if (R != nullptr) {
		delete[]R;
		R = nullptr;
		
	}
	if (D != nullptr) {
		delete[]D;
		D = nullptr;
	}
	if (serhis != nullptr) {
		delete[]serhis[0];
		delete[]serhis[1];
		serhis[0] = nullptr;
		serhis[1] = nullptr;

	}
	
}
void Driver::setdid(int a) {
	dId = a;
	setid(a);
}
void Driver::setnoofl(int a) {
	noofl = a;
}
void Driver::setOrank(float a) {
	Orank = a;
}
void Driver::setsal(float a) {//set salary
	Salary= a;
}
	
void Driver::setexp(int a) {
	exp = a;
}
void Driver::setstatus(int a) {
	status = a;
}
void Driver::setRlen(int a) {
	Rlen=a;

}
void Driver::setDlen(int a) {
	Dlen = a;

}

int Driver::getdid() const {
	return dId ;
}
int Driver::getnoofl() const {
	return noofl ;
}
float Driver::getOrank() const {
	return Orank ;
}
float Driver::getsal()const {//set salary
	return Salary ;
}

int Driver::getexp()const {
	return exp ;
}
int Driver::getstatus()const {
	return status;
}
char** Driver::getLislist()const {
	return Lisencelist;
}
int Driver::getRlen()const {
	return Rlen;

}
int Driver::getDlen()const {
	return Dlen;

}

void Driver::removedriver() {

	dId = -1;
	
	Orank = 0;
	Salary = 0;
	exp = 0;
	status = 0;
	for (int i = 0; i < noofl; i++) {
		delete[]Lisencelist[i];
	}
	Lisencelist = nullptr;
	
	D = nullptr;
	R = nullptr;
	//delete[]serhis[0];
	//delete[]serhis[1];
	serhis = nullptr;
	
	//serhis[0] = nullptr;
	//serhis[1] = nullptr;

	removeperson();
	
}
void Driver::setLislist(char** list) {
	Lisencelist = new char* [noofl];
	int j;
	for (int i = 0; i < noofl; i++) {
		Lisencelist[i] = new char[20];

		for (j = 0; list[i][j] != '\0'; j++) {
			Lisencelist[i][j] = list[i][j];

		}
		Lisencelist[i][j] = '\0';
	}
	
}

//------------------SET RIDE----------------
void Driver::setride(const Ride& a) {
	
	R[Rlen] = a;
	Rlen++;
	serhis[0] = R;


}
//------------------SET DELIVERY----------------
void Driver::setdel(Delivery a) {

	D[Dlen] = a;
	Dlen++;

	serhis[1] = D;


}
void Driver::printdriver() {
	cout << "Driver has Total " << Rlen << " Rides and " << Dlen << " Deliveries\n";
	//------------------RIDES----------------
	for (int i = 0; i < Rlen; i++) {
		cout << "Ride " << i + 1 << ":" << endl;
		if (i == 0) {
			serhis[0][i].printservice();
			cout << endl;
		}
		else {
			R[i].printservice();
			cout << endl;
		}

	}
//----------------------DELIVERIS---------------
	for (int i = 0; i < Dlen; i++) {
		cout << "Delivery " << i + 1 << ":" << endl;
		if (i == 0) {
			serhis[1][i].printservice();
			cout << endl;
		}
		else {
			D[i].printservice();
			cout << endl;
		}

	}
}
ostream& operator<<(ostream& ob, Driver& a) {
	Date b;
	b = a.getdob();
	ob << "Driver Detail\n";
	ob << "Name:" << a.getFname() << " " << a.getLname() << endl << "ID: " << a.dId << endl << "Date of Birth:" << b ;
	ob << "Age:" << a.getage() << endl << "Number of Lisence " << a.noofl << endl;
	for (int i = 0; i < a.noofl; i++) {
		cout << i + 1 << "." << a.Lisencelist[i] << endl;
	}
	ob << endl;
	ob << "Experience: " << a.exp << " Years " << endl << "Salary:" << a.Salary << endl << "Over all Ranking:" << a.Orank << endl;


	ob << "Total Rides:" << a.Rlen << ", Total Deliveries: " << a.Dlen  << endl;
	int x = 0, y = 0;
	for (int i = 0; i < a.Rlen; i++) {
		if (a.serhis[0][i].getstatus()) {
			x++;
		}
		else {
			y++;
		}
	}
	ob << "Complete " << x << " rides and " << y << " Rides in pending\n";
	x = 0;
	y = 0;
	for (int i = 0; i < a.Dlen; i++) {
		if (a.serhis[1][i].getstatus()) {
			x++;
		}
		else {
			y++;
		}
	}
	ob << "Complete " << x << " deliveries and " << y << " deliveries in pending\n";
	x = 0;
	y = 0;
	
	return ob;
}
void Driver::printlislist() {
	cout << "Lisence Detail\n";
	for (int i = 0; i < noofl; i++) {
		cout << i + 1 << Lisencelist[i] << endl;
	}
}
int Driver::getstatusR(int a) {
	return R[a].getstatus();
}
int Driver::getstatusD(int a) {
	return D[a].getstatus();
}