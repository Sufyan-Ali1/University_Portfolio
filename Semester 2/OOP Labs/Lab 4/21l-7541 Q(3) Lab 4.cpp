#include<iostream>
using namespace std;
class date{
private:
	int day;
	int month, year;
public:
	void def(){
		day = 1;
		month = 1;
		year = 1996;
	}
	void print(){
		cout << day << "/" << month << "/" << year << endl;

	}
	void inpt(){
		cout << "Enter day: ";
		cin >> day;
		while (day > 31){
			cout << "Enter correct day: ";
			cin >> day;
		}
		cout << "Enter month: ";
		cin >> month;
		while (month > 12){
			cout << "Enter correct month: ";
			cin >> month;
		}
		cout << "Enter year: ";
		cin >> year;
	}
	void settersday(){
		int dat;
		cout << "Enter day: ";
		cin >> dat;
		while (dat > 31){
			cout << "Enter correct day: ";
			cin >> dat;
		}
		day = dat;
	}
	void settersmnth(){
		int mnth;
		cout << "Enter month: ";
		cin >> mnth;
		while (mnth > 12){
			cout << "Enter correct month: ";
			cin >> mnth;
		}
		month = mnth;
	}
	void settersyear(){
		int y;
		cout << "Enter year: ";
		cin >> y;n
		
		year = y;
	}

	void gettersday(){
		cout << day<<"/";
	}
	void gettersmonth(){
		cout << month<<"/";
	}
	void gettersyear(){
		cout << year<<endl;
	}

};
void main(){
	date date1;
	date1.def();
	date1.print();
	date1.inpt();
	date1.print();
	cout << "Now for Xmasday\n";
	date xmasday;
	xmasday.def();
	xmasday.print();
	xmasday.settersday();
	xmasday.settersmnth();
	xmasday.settersyear();
	
	xmasday.gettersday();
	xmasday.gettersmonth();
	xmasday.gettersyear();
	system("pause");
}