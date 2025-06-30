#pragma once
#include<iostream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;
public:
	Date(int = 0, int = 0, int = 0);
	
	void setday(int a);
	void setmonth(int a);
	void setyear(int a);
    int getday();
	int getmonth();
	int getyear();
	friend ostream& operator<<(ostream & ob,  Date & a);
};

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;

}
void Date::setday(int a) {
	day = a;
}
void Date::setmonth(int a) {
	month = a;
}
void Date::setyear(int a) {
	year = a;
}
int Date::getday() {
	return day;
}
int Date::getmonth() {
	return month;
}
int Date::getyear() {
	return year;
}
ostream& operator<<(ostream& ob, Date& A) {
	ob << "Date: " << A.getday() << "/" << A.getmonth() << "/" << A.getyear() << endl;
	return ob;
}