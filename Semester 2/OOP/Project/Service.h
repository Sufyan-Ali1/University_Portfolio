#pragma once
#include"Date.h"
#include"mTime.h"
class Service
{
	char* source;
	char* destination;
	float distance;
	Date bokdate;//booking date
	mTime boktim;//booking time
	int status;
	float fuelrate;
	int cId;
	int dId;
	int vId;
public:
	Service();
	~Service();
	void setsource(char*);
	void setdestination(char*);
	void setdistance(float);
	void setbokdate(Date);
	void setboktime(mTime);
	void setstatus(int);
	void setcid(int);
	void setdid(int);
	void setvid(int);
	void setfuelrate(float);
	

	char* getsource()const;
	char* getdestination()const;
	float getdistance()const;
	Date getbokdate()const;
	mTime getboktime()const;
	int getstatus()const;
	int getcid()const;
	int getdid()const;
	int getvid()const;
	float getfuelrate()const;
	virtual void printservice(){};
};
//-----------------------SETTER----------------------
void Service::setsource(char* a) {
	
	source = new char[30];
	int i = 0;
	
	for (; a[i] != '\0'; i++) {
		
		source[i] = a[i];
	}
	source[i] = '\0';
	
}
void Service::setdestination(char* a) {
	destination = new char[30];
	int i = 0;
	for (; a[i] != '\0'; i++) {
		destination[i] = a[i];
	}
	destination[i] = '\0';
}
void Service::setdistance(float a) {
	distance = a;
}
void Service::setfuelrate(float a) {
	fuelrate = a;
}
void Service::setstatus(int a) {
	status = a;
}
void Service::setcid(int a) {
	cId = a;
}
void Service::setdid(int a) {
	dId = a;
}
void Service::setvid(int a) {
	vId = a;
}
void Service::setbokdate(Date a) {
	bokdate = a;
}
void Service::setboktime(mTime a) {
	boktim = a;
}
//-----------------GETTER-------------------
char* Service::getsource()const {
	return source;
}
char* Service::getdestination()const {
	return destination ;
}
float Service::getdistance()const {
	return distance;
}
float Service::getfuelrate()const {
	return fuelrate ;
}
int Service::getstatus()const {
	return status;
}
int Service::getcid()const {
	return cId;
}
int Service::getdid()const {
	return dId;
}
int Service::getvid()const {
	return vId;
}
Date Service::getbokdate()const {
	return bokdate;
}
mTime Service::getboktime() const {
	return boktim;
}
//----------------CONSTRUCTOR--------------------
Service::Service() {
	source = new char[30];
	destination = new char[30];
distance=0;
	
	status=0;
	fuelrate=0;
	 cId=0;
	 dId=0;
	vId=0;
}
//----------------------DESTRUCTOR-------------------
Service::~Service() {
	if (source != nullptr) {
		delete[]source;
		source = nullptr;
	}
	if (destination != nullptr) {
		delete[]destination;
		destination = nullptr;
	}
}