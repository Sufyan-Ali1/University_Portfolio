#pragma once
#include<iostream>
using namespace std;
class Feature
{
	int fId;
	char* descrip;//description
	float cost;
public:
	//Feature(int, float, char* );
	Feature();
	Feature(Feature&);
	void setfid(int);
	void setcost(float);
	void setdescrip(char*);
	int getfid();
	float getcost();
	char* getdescrip();
	void operator=(const Feature&);
	friend ostream& operator<<(ostream&, Feature&);
	~Feature();
};
Feature::~Feature() {
	if (descrip != nullptr) {
		delete[]descrip;
		descrip = nullptr;
	}
	
}
Feature::Feature() {
	descrip = new char[50];
	cost = 0;
	fId = 0;
}
//----------------------SETTER-------------------------
void Feature::setcost(float a) {
	cost = a;
}
void Feature::setfid(int a) {
	fId = a;
}
void Feature::setdescrip(char *a) {
	int i;
	for (i = 0; a[i] != '\0'; i++) {
		descrip[i] = a[i];
	}
	descrip[i] = '\0';
}
//---------------------------GETTER-------------------------
int Feature::getfid() {
	return fId;
}
float Feature::getcost() {
	return cost;
}
char* Feature::getdescrip() {
	return descrip;
}
//---------------------------Copy Constructor---------------------
Feature::Feature(Feature& a) {
	fId = a.fId;
	cost = a.cost;
	char* b = a.descrip;
	int i;
	for (i = 0; b[i] != '\0'; i++) {
		descrip[i] = b[i];

	}
	descrip[i] ='\0';
}
void Feature::operator=(const Feature& a) {
	
		fId = a.fId;
		cost = a.cost;
		char* b = a.descrip;
		int i;
		for (i = 0; b[i] != '\0'; i++) {
			descrip[i] = b[i];

		}
		descrip[i] = '\0';
}

ostream& operator<<(ostream&ob, Feature& a) {
	ob << "Feature Id:" << a.fId << endl;
	ob << "Feature: " << a.descrip << endl << "Feature Price:" << a.cost << endl;
	return ob;
}


