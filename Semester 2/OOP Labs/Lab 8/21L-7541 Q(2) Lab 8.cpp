#include<iostream>
using namespace std;
class Duration {
	int day;
	int mon;
	int yr;
	int sal;
public:
	Duration();
	Duration(int, int, int);
	Duration &setdays(int);
	Duration &setmonth(int);
	Duration &setyear(int);
	int getemlydur(int, int, int);//get employ duration
	int newsal(int);
	int getday();
	int getmon();
	int getyear();
	int getsal();


};
Duration::Duration() {
	day = 0;
	mon = 0;
	yr = 0;
	sal = 50000;
}
Duration::Duration(int a, int b, int c) {
	day = a;
	mon = b;
	yr = c;
	sal = 50000;

}
int Duration::getemlydur(int a, int b, int c) {
	int dmon = 0;
	int dday = 0;
	int dyr = 0;
	dmon = 12 - this->mon;
	dday = 31 - this->day;
	dyr = c-this->yr-1;
	
	dday = a + dday;
	dmon = dmon + b-1;

	if (dday >= 31) {
		dmon++;
		dday = dday - 31;

	}
	if (dmon >= 12) {
		dyr++;
		dmon = dmon - 12;

	}
	
	return dyr;
}
int Duration::newsal(int a) {
	if (a >= 3 && a <= 5) {
		this->sal = this->sal + ((this->sal * 7) / 100);
		cout << this->sal << endl;
		return this->sal;
	}
	else if (a > 5) {
		this->sal = this->sal + ((this->sal * 10) / 100);
		
		return 0;
	}
	cout << this->sal << endl;
}
int Duration::getday() {

	return this->day;
}
int Duration::getmon() {

	return this->mon;
}
int Duration::getyear() {

	return this->yr;
}
int Duration::getsal() {

	return this->sal;
}
Duration &Duration::setdays(int day) {
	this->day = day;
	return *this;
}
Duration &Duration::setmonth(int mon) {
	this->mon = mon;
	return *this;
}
Duration& Duration::setyear(int yr) {
	this->yr = yr;
	return *this;
}
int main() {
	int day1;
	int mon1;
	int yr1;
	cout << "Enter current date \n";
	cout << "Enter day(1-31): ";

	cin >> day1;
	while (day1 > 31||day1<0) {
		cout << "Please Enter correct date\n";
		cout << "ReEnter: ";
		cin >> day1;

	}

	cout << "Enter month(1-12): ";
	cin >> mon1;
	while (mon1 > 12||mon1<0) {
		cout << "Please Enter correct month\n";
		cout << "ReEnter: ";
		cin >> mon1;

	}

	cout << "Enter year(0-2022): ";
	cin >> yr1;
	while (yr1 > 2022||yr1<0) {
		cout << "Please Enter correct year\n";
		cout << "ReEnter: ";
		cin >> yr1;

	}
	cout << "\t\t\t\tENTER DATA FOR OBJECT 1:\n";
	cout << "Enter starting date of object 1 \n";
	cout << "Enter day(1-31): ";
	int day;
	cin >> day;
	while (day > 31||day<0) {
		cout << "Please Enter correct date\n";
		cout << "ReEnter: ";
		cin >> day;

	}
	int mon;
	cout << "Enter month(1-12): ";
	cin >> mon;
	while (mon > 12||mon<0) {
		cout << "Please Enter correct month\n";
		cout << "ReEnter: ";
		cin >> mon;

	}
	int yr;
	cout << "Enter year(0-2022): ";
	cin >> yr;
	while (yr > 2022||yr<0) {
		cout << "Please Enter correct year\n";
		cout << "ReEnter: ";
		cin >> yr;

	}
	Duration ob1(day, mon, yr);

	
	int dyr = ob1.getemlydur(day1, mon1, yr1);
	ob1.newsal(dyr);
	cout << "\t\t\t\tDATA OF OBJECT 1:\n";
	day = ob1.getday();
	mon = ob1.getmon();
	yr = ob1.getyear();
	int sal = ob1.getsal();
	cout << "Starting Date of object 1 is: " << day << endl;
	cout << "Starting Month of object 1 is: " << mon << endl;
	cout << "Starting Year of object 1 is: " << yr << endl;
	cout << "New Salary of Object 1 is: " << sal << endl;
	
	//Object 2 start
	Duration ob2;
	cout << "\t\t\t\tENTER DATA FOR OBJECT 2:\n";
	cout << "Enter starting date of object 2 \n";
	cout << "Enter day(1-31): ";
	
	cin >> day;
	while (day > 31 ||day < 0) {
		cout << "Please Enter correct date\n";
		cout << "ReEnter: ";
		cin >> day;

	}
	
	cout << "Enter month(1-12): ";
	cin >> mon;
	while (mon > 12 || mon < 0) {
		cout << "Please Enter correct month\n";
		cout << "ReEnter: ";
		cin >> mon;

	}
	
	cout << "Enter year(0-2022): ";
	cin >> yr;
	while (yr > 2022 || yr < 0) {
		cout << "Please Enter correct year\n";
		cout << "ReEnter: ";
		cin >> yr;

	}
	ob2.setdays(day).setmonth(mon).setyear(yr);
	//--------------------
	
	dyr = ob2.getemlydur(day1, mon1, yr1);
	ob2.newsal(dyr);
	cout << "\t\t\t\tDATA OF OBJECT 1:\n";
	day = ob2.getday();
	mon = ob2.getmon();
	yr = ob2.getyear();
	sal = ob2.getsal();
	cout << "Starting Date of object 2 is: " << day << endl;
	cout << "Starting Month of object 2 is: " << mon << endl;
	cout << "Starting Year of object 2 is: " << yr << endl;
	cout << "New Salary of Object 2 is: " << sal << endl;
}