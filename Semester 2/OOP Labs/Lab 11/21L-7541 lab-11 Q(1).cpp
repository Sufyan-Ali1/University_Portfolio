#include<iostream>
#include<string>
using namespace std;
class employee{
	int id;
	string name;
public:
	employee(string = "", int = 0);
};
employee::employee(string a, int b){
	name = a;
	id = b;
}
class permanentemploy:public employee
{
	int hourlyincome;
public:
	permanentemploy(string="",int=0,int = 0);
	void cal_total_inc();
};

class hourlyemploy: public employee
{
	int hourlyincome;
public:
	hourlyemploy(string = "", int = 0, int = 0);
	void cal_hourly_inc(int );
};


permanentemploy::permanentemploy(string  a, int  b, int  c) :employee{ a, b }
{
	hourlyincome = c;
}
hourlyemploy::hourlyemploy(string  a, int  b, int  c) : employee{ a, b }
{
	hourlyincome = c;
}
void permanentemploy::cal_total_inc(){
	int total; 
	total = 240 * hourlyincome;
	cout << "Total income of permanent employee is: " << total << endl;
}
void hourlyemploy::cal_hourly_inc(int a){
	int total;
	total = a * hourlyincome;
	cout << "Income of hourly employee is: " << total << endl;
}
void main(){
	cout << "Enter detail of Permanent Employee\n";
	cout << "Enter name\n";
	string a;
	getline(cin, a);
	int id;
	cout << "Enter your id\n";
	cin >> id;
	permanentemploy ob(a, id, 150);
	ob.cal_total_inc();

	cout << "\nEnter detail of Hourly Employee\n";
	cin.ignore();
	cout << "Enter name\n";
	
	getline(cin, a);
	
	cout << "Enter your id\n";
	cin >> id;
	hourlyemploy ob1(a, id, 150);
	int x;
	cout << "Enter number of hours that employee work\n";
	cin >> x;
	ob1.cal_hourly_inc(x);
	system("pause");
}