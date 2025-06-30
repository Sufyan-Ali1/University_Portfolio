#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

class Date;
class Service;
class Person;
class Customer;
class Driver;
class Vehicle;
class Feature;
class mTime;
class Name;
class Ride;
class Delivery;
class Name;
//-----------------------------------------------------CLASS TMS---------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------


// ------------------------------------------
class Name
{

	char* Fname;
	char* Lname;
public:
	Name(char*, char*);
	Name();

	void setFname(char*);
	void setLname(char*);
	char* getFname()const;
	char* getLname()const;
	void removename();
	Name operator=(const Name& a);
	Name(const Name& A);
	Name getname();
	friend ostream& operator<<(ostream&, Name&);
	~Name();



};

Name::Name(char* fn, char* ln) {
	Fname = new char[12];
	int i;
	for (i = 0; fn[i] != '\0'; i++) {
		Fname[i] = fn[i];
	}
	Fname[i] = '\0';
	Lname = new char[12];
	for (i = 0; ln[i] != '\0'; i++) {
		Lname[i] = ln[i];
	}
	Lname[i] = '\0';

}
Name::Name() {
	Fname = new char[12];
	Fname[0] = '\0';
	Lname = new char[12];
	Lname[0] = '\0';

}
void Name::setFname(char* fn) {
	int i;
	if (fn == nullptr) {
		Fname = nullptr;

	}
	else {
		for (i = 0; fn[i] != '\0'; i++) {
			Fname[i] = fn[i];
		}
		Fname[i] = '\0';
	}

}
void Name::setLname(char* ln) {
	int i;
	if (ln == nullptr) {
		Lname = nullptr;

	}
	else {
		for (i = 0; ln[i] != '\0'; i++) {
			Lname[i] = ln[i];
		}
		Lname[i] = '\0';
	}
}
char* Name::getFname()const {
	return Fname;


}
char* Name::getLname()const {
	return Lname;
}
Name::Name(const Name& A) {
	Fname = new char[12];
	Lname = new char[12];
	int i;
	for (i = 0; A.Fname[i] != '\0'; i++) {
		Fname[i] = A.Fname[i];
	}
	Fname[i] = '\0';
	for (i = 0; A.Lname[i] != '\0'; i++) {
		Lname[i] = A.Lname[i];
	}
	Lname[i] = '\0';

}
Name Name::operator=(const Name& A) {
	Fname = new char[12];
	Lname = new char[12];
	int i;
	for (i = 0; A.Fname[i] != '\0'; i++) {
		Fname[i] = A.Fname[i];
	}
	Fname[i] = '\0';
	for (i = 0; A.Lname[i] != '\0'; i++) {
		Lname[i] = A.Lname[i];
	}
	Lname[i] = '\0';
	return *this;
}
ostream& operator<<(ostream& out, Name& n) {
	out << "Name: " << n.getFname() << " " << n.getLname() << endl;
	return out;
}
Name Name::getname() {
	return *this;
}
Name::~Name() {
	if (Fname != nullptr) {
		delete[]Fname;
		Fname = NULL;
	}
	if (Lname != nullptr) {
		delete[]Lname;
		Lname = NULL;
	}

}
void Name::removename() {
	Fname = nullptr;
	Lname = nullptr;
}

// ----------------------------------------
class mTime
{
	int hour;
	int min;
	int sec;
public:
	mTime(int = 0, int = 0, int = 0);
	void setmin(int);
	void sethour(int);
	void setsec(int);
	int gethour();
	int getmin();
	int getsec();
	friend ostream& operator<<(ostream&, mTime&);
};
mTime::mTime(int a, int b, int c) {
	hour = a;
	min = b;
	sec = c;
}
void mTime::setmin(int a) {
	min = a;
}
void mTime::sethour(int a) {
	hour = a;
}
void mTime::setsec(int a) {
	sec = a;
}
int mTime::getmin() {
	return min;
}
int mTime::gethour() {
	return hour;
}
int mTime::getsec() {
	return sec;
}
ostream& operator<<(ostream& ob, mTime& a) {
	ob << "Time= " << a.hour << ":" << a.min << ":" << a.sec << endl;
	return ob;
}
//---------------------------------------------
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
	friend ostream& operator<<(ostream& ob, Date& a);
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
//------------------------------------------PERSON
class Person
{
	Name pName;
	Date DOB;//Date of Birth
	int age;
	int Nid;
public:
	Person(Name, Date, int, int);
	Person();
	Person(const Person&);
	void setname(char* a, char* b);
	void setnames(const Name&);
	void setdob(const Date);
	void setage(int);
	void setid(int);
	Name getname()const;
	Date getdob()const;
	int getage()const;
	int getid()const;
	char* getFname()const;
	char* getLname()const;
	Person operator=(const Person&);
	void removeperson();
	friend ostream& operator<<(ostream&, Person&);

};
Person::Person() {
	age = 0;
	Nid = 0;
}
Person::Person(Name A, Date B, int c, int d) {
	pName = A;
	DOB = B;
	age = c;
	Nid = d;

}
Person::Person(const Person& ob) {
	pName = ob.pName;
	DOB = ob.DOB;
	age = ob.age;
	Nid = ob.Nid;
}

void Person::setname(char* a, char* b) {
	pName.setFname(a);
	pName.setLname(b);

}
void Person::setdob(const Date a) {
	DOB = a;

}
Person Person::operator=(const Person& ob) {
	pName = ob.pName;
	DOB = ob.DOB;
	age = ob.age;
	Nid = ob.Nid;
	return ob;
}
ostream& operator<<(ostream& ob, Person& a) {
	ob << a.pName << endl << a.DOB << endl << "Age=" << a.age << endl << "Id= " << a.Nid << endl;
	return ob;
}
void Person::setage(int a) {
	age = a;
}
void Person::setid(int a) {
	Nid = a;
}
int Person::getid() const {
	return Nid;
}
int Person::getage() const {
	return age;
}
Name Person::getname() const {
	return pName;
}
Date Person::getdob() const {
	return DOB;
}
void Person::setnames(const Name& a) {
	pName = a;
}
char* Person::getFname() const {
	return pName.getFname();
}
char* Person::getLname() const {
	return pName.getLname();
}
void Person::removeperson() {
	DOB.setday(0);
	DOB.setmonth(0);
	DOB.setyear(0);
	pName.setFname(nullptr);
	pName.setLname(nullptr);
}

//--------------------------------------
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
	virtual void printservice() {};
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
	return destination;
}
float Service::getdistance()const {
	return distance;
}
float Service::getfuelrate()const {
	return fuelrate;
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
	distance = 0;

	status = 0;
	fuelrate = 0;
	cId = 0;
	dId = 0;
	vId = 0;
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
// -----------------------------------------
class Delivery :public Service
{
	float gweight;//goods weight
	char* gtype;//goods type

public:

	Delivery();
	Delivery(const Delivery&);
	Delivery operator=(const Delivery&);
	void setGw8(float);
	void setGtype(char*);
	void printservice();
	float getGw8()const;
	char* getGtype()const;
	friend ostream& operator<<(ostream&, Delivery&);
	~Delivery();
};
//------------CONSTRUCTOR--------------
Delivery::Delivery() {

	gtype = new char[20];
	gweight = 0;
}
//------------------COPY CONSTRUCTOR---------------
Delivery::Delivery(const Delivery& a) {
	gtype = new char[20];
	gweight = a.getGw8();

	char* x = a.getGtype();
	int i = 0;

	for (; x[i] != '\0'; i++) {
		gtype[i] = x[i];
	}                              ////
	gtype[i] = '\0';


	setsource(a.getsource());//
	setdestination(a.getdestination());//
	setbokdate(a.getbokdate());
	setboktime(a.getboktime());
	setdid(a.getdid());
	setcid(a.getcid());
	setvid(a.getvid());
	setdistance(a.getdistance());
	setstatus(a.getstatus());
	setfuelrate(a.getfuelrate());


}
//-----------------DESTRUCTOR------------------------
Delivery::~Delivery() {
	if (gtype != nullptr) {
		delete[]gtype;
		gtype = nullptr;
	}
}
//-----------------ASSIGNMENT OPERATOR-----------------
Delivery Delivery::operator=(const Delivery& a) {
	gtype = new char[20];
	gweight = a.getGw8();
	char* x = a.getGtype();
	int i = 0;

	for (; x[i] != '\0'; i++) {
		gtype[i] = x[i];
	}
	gtype[i] = '\0';


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
//----------------SETTER---------------------------
void Delivery::setGw8(float a) {
	gweight = a;
}
void Delivery::setGtype(char* a) {
	int i = 0;
	gtype = new char[25];
	for (; a[i] != '\0'; i++) {
		gtype[i] = a[i];
	}
	gtype[i] = '\0';
}
//----------------GETTER-------------------
float Delivery::getGw8()const {
	return gweight;
}
char* Delivery::getGtype()const {
	return gtype;

}
void Delivery::printservice() {
	Date a = getbokdate();
	mTime b = getboktime();
	cout << "Delivery Detail\n";
	cout << "Goods Type:" << gtype << endl;
	cout << "Goods Weight: " << gweight << endl;
	cout << "Delivery Book Date: " << a << "Delivery Book Time: " << b;
	cout << "Source:" << getsource() << " and Destination: " << getdestination() << endl;
	cout << "Fuel Rate:" << getfuelrate() << endl;
	cout << "Distance:" << getdistance() << endl;
	cout << "Vehicle Id:" << getvid() << "," << "Driver Id:" << getdid() << "," << "Customer Id:" << getcid() << endl;
	if (getstatus() == 1) {
		cout << "Delivery Complete\n";
	}
	else {
		cout << "Delivery in pending\n";
	}

}
ostream& operator<<(ostream& ob, Delivery& a) {
	Date c = a.getbokdate();
	mTime b = a.getboktime();
	cout << "Delivery Detail\n";
	cout << "Goods Type:" << a.gtype << endl;
	cout << "Goods Weight: " << a.gweight << endl;
	cout << "Delivery Book Date: " << c << "Delivery Book Time: " << b;
	cout << "Source:" << a.getsource() << " and Destination: " << a.getdestination() << endl;
	cout << "Fuel Rate:" << a.getfuelrate() << endl;
	cout << "Distance:" << a.getdistance() << endl;
	cout << "Vehicle Id:" << a.getvid() << "," << "Driver Id:" << a.getdid() << "," << "Customer Id:" << a.getcid() << endl;

	/*if (a.getstatus() == 1) {
		cout << "Delivery Complete\n";
	}
	else {
		cout << "Delivery in pending\n";
	}*/
	return ob;
}

// --------------------------------------
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
	friend ostream& operator<<(ostream&, Ride&);
	void printservice();

};

//------------------------Setter--------------
void Ride::setD_rank(float a) {
	DriverRank = a;

}
void Ride::setV_rank(float a) {
	VehicleRank = a;

}

void Ride::setRtype(char* a) {
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
int Ride::getnop()const {
	return nop;

}
float Ride::getD_rank()const {
	return	DriverRank;

}
float Ride::getV_rank()const {
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
	v = a.getRtype();
	int i;
	for (i = 0; v[i] != '\0'; i++) {
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
	cout << "Ride Book Date: " << c << "Ride Book Time: " << b;
	cout << "Source:" << a.getsource() << " and Destination: " << a.getdestination() << endl;
	cout << "Fuel Rate:" << a.getfuelrate() << endl;
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
void Ride::printservice() {
	Date a = getbokdate();
	mTime b = getboktime();
	cout << "Ride Detail\n";
	cout << "Ride Type:" << ridetype << endl;
	cout << "No of Person: " << nop << endl;
	cout << "Ride Book Date: " << a << "Ride Book Time: " << b;
	cout << "Source:" << getsource() << " and Destination: " << getdestination() << endl;
	cout << "Fuel Rate:" << getfuelrate() << endl;
	cout << "Distance:" << getdistance() << endl;
	cout << "Vehicle Id:" << getvid() << "," << "Driver Id:" << getdid() << "," << "Customer Id:" << getcid() << endl;
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

// ---------------------------------------------
//-----------------------------------------------
class Customer :public Person
{
private:
	int cid;
	Service** bookhis;//booking history
	Ride* R;
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
Customer::Customer(Customer& A) {
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
	ob << "Age:" << a.getage() << endl << "Customer has " << a.Rlen << " Rides and " << a.Dlen << " Deliveries" << endl;
	int x = 0, y = 0;
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
		cout << "Ride " << i + 1 << ":" << endl;
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
// -----------------------------------------------------------------------------------------
//------------------------------------------DRIVER------------------------------------------
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
	Lisencelist = new char* [noofl];

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
	Salary = a;
}

void Driver::setexp(int a) {
	exp = a;
}
void Driver::setstatus(int a) {
	status = a;
}
void Driver::setRlen(int a) {
	Rlen = a;

}
void Driver::setDlen(int a) {
	Dlen = a;

}

int Driver::getdid() const {
	return dId;
}
int Driver::getnoofl() const {
	return noofl;
}
float Driver::getOrank() const {
	return Orank;
}
float Driver::getsal()const {//set salary
	return Salary;
}

int Driver::getexp()const {
	return exp;
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
	
	//delete[]serhis[0];
	//delete[]serhis[1];


	//serhis[0] = nullptr;
	//serhis[1] = nullptr;

//	removeperson();

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
	ob << "Name:" << a.getFname() << " " << a.getLname() << endl << "ID: " << a.dId << endl << "Date of Birth:" << b;
	ob << "Age:" << a.getage() << endl << "Number of Lisence " << a.noofl << endl;
	for (int i = 0; i < a.noofl; i++) {
		cout << i + 1 << "." << a.Lisencelist[i] << endl;
	}
	ob << endl;
	ob << "Experience: " << a.exp << " Years " << endl << "Salary:" << a.Salary << endl << "Over all Ranking:" << a.Orank << endl;


	ob << "Total Rides:" << a.Rlen << ", Total Deliveries: " << a.Dlen << endl;
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
//-------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------FEATURE--------------------------------------------
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
void Feature::setdescrip(char* a) {
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
	descrip[i] = '\0';
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

ostream& operator<<(ostream& ob, Feature& a) {
	ob << "Feature Id:" << a.fId << endl;
	ob << "Feature: " << a.descrip << endl << "Feature Price:" << a.cost << endl;
	return ob;
}


//----------------------------------------------------
// ------------------------VEHICLE---------------------------------------
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


	int getstatusR(int);
	int getstatusD(int);
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
	serHis = new Service * [2];
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
	int i = 0;
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
	list[Flen] = a;
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
	if(a.vId!=-1){
		ob << "Vehicle Detail\n";
		ob << "Vehicle Id:" << a.vId << endl << "Registeration Number:" << a.regno << endl;
		ob << "Manufacturing Date:" << b;
		ob << "Total Features:" << a.Flen;
		ob << "Feature Name" << endl;
		for (int i = 0; i < a.Flen; i++) {
			ob << i + 1 << ")" << a.list[i];
		}
		ob << "Average Mileage:" << a.avgmil << endl << "License Required:" << a.lsctype << endl << "Overall Rating:" << a.Orank << endl;
		ob << "Fuel Type:" << a.fueltype << endl;
		if (a.status) {
			cout << "Vehicle is Booked\n";
		}
		else {
			cout << "Vehicle is Free\n";
		}
	}
	
	return ob;
}
int Vehicle::getstatusR(int a) {
	return R[a].getstatus();
}
int Vehicle::getstatusD(int a) {
	return D[a].getstatus();
}

//----------------------------------------------------
//-----------------------------------------------
class TMS {
	int Dno;//Number of Drivers
	int Cno;//Number of Customers
	int Vno;//Number of Vehicles

	Driver* D;
	Customer* C;
	Vehicle* V;

public:
	TMS();
	void Menu();
	void WriteData();
	void ReadData();
	void D_ReadData();
	void V_ReadData();
	void addcustomer();
	void add_driver();
	void remove_driver();
	void add_vehicle();
	void remove_vehicle();
	void printcustom();
	void printdriver();
	void printvehicle();
	void addservice();
	void reWritesdriver();
	void rewritevehicle();
	void printcustomhis();//print particular customer history
	void printdriverhis();//print particular driver history
	void printvehiclehis();
	void printrankdriver();
	void cancelservice();
	void printmultiplelis();
	void cancelRD();
	void completeRD();
	//void samedatedelivery();
	void printupdatesal();
	~TMS() {
		delete[]D;
		D = nullptr;
		delete[]C;
		C = nullptr;
		delete[]V;
		V = nullptr;
	}
	void Driverpendser();//pending services of patricular driver


};
TMS::TMS() {
	D = new Driver[10];
	Dno = 0;
	Cno = 0;
	Vno = 0;

	C = new Customer[15];
	V = new Vehicle[20];


}
//--------------------------------------------------------ADD CUSTOMER----------------------------------------
void TMS::addcustomer() {
	cout << "ADD CUSTOMER\n";

	int id = 0, m, d, y, age;
	Date D;
	Name N;
	char* Fn;
	char* Ln;
	Fn = new char[15];
	Ln = new char[15];
	cout << "Enter First Name:";
	cin >> Fn;
	cout << "Enter Last Name:";
	cin >> Ln;
	cout << "Enter ID\n";
	cin >> id;
	for (int i = 0; i < Cno; i++) {
		if (C[i].getcid() == id) {
			cout << "Id already exist please enter again\n";
			cin >> id;
			i = 0;
		}

	}
	cout << "Enter Date of Birth\n";
	cout << "Day:";
	cin >> d;
	cout << "Month:";
	cin >> m;
	cout << "Year:";
	cin >> y;
	D.setday(d);
	D.setmonth(m);
	D.setyear(y);
	cout << "Enter Age:";
	cin >> age;
	C[Cno].setage(age);
	C[Cno].setcid(id);
	C[Cno].setname(Fn, Ln);
	C[Cno].setdob(D);
	Cno++;
	ofstream out("Customer.txt", ios::app);
	out << 1 << "/" << id << "/" << Fn << "," << Ln << "/" << d << "," << m << "," << y << "/" << age << "." << "\n";
	out.close();
}
void TMS::addservice() {
	cout << "Enter Id of Customer\n";
	cout << "ID:";
	int id;
	cin >> id;
	int i;
	int check = 0;
	for (i = 0; i < Cno; i++) {
		if (C[i].getcid() == id) {
			check = 1;
			break;
		}
	}


	ofstream out("Customer.txt", ios::app);
	if (!check) {
		int id = 0, m, d, y, age;
		Date D;
		Name N;
		char* Fn;
		char* Ln;
		Fn = new char[15];
		Ln = new char[15];
		cout << "Enter First Name:";
		cin >> Fn;
		cout << "Enter Last Name:";
		cin >> Ln;


		cout << "Enter Date of Birth\n";
		cout << "Day:";
		cin >> d;
		cout << "Month:";
		cin >> m;
		cout << "Year:";
		cin >> y;
		D.setday(d);
		D.setmonth(m);
		D.setyear(y);
		cout << "Enter Age:";
		cin >> age;
		C[Cno].setage(age);
		C[Cno].setcid(id);
		C[Cno].setname(Fn, Ln);
		C[Cno].setdob(D);
		Cno++;

		out << 1 << "/" << id << "/" << Fn << "," << Ln << "/" << d << "," << m << "," << y << "/" << age << "." << "\n";

	}


	float* arr, * arr1;
	arr = new float[Vno];
	arr1 = new float[Dno];
	for (int j = 0; j < Dno; j++) {
		arr[j] = D[j].getOrank();
	}
	for (int j = 0; j < Vno; j++) {
		arr1[j] = V[j].getOrank();
	}

	for (int j = 0; j < Dno - 1; j++) {
		for (int k = j + 1; k < Dno; k++) {
			if (arr[j] < arr[k]) {
				float temp = arr[j];
				arr[j] = arr[k];
				arr[k] = temp;
			}
		}
	}

	for (int j = 0; j < Vno - 1; j++) {
		for (int k = j + 1; k < Vno; k++) {
			if (arr1[j] < arr1[k]) {
				float temp = arr1[j];
				arr1[j] = arr1[k];
				arr1[k] = temp;
			}
		}
	}

	cout << "Free Drivers\n";

	for (int j = 0; j < Dno; j++) {
		for (int k = 0; k < Dno; k++) {
			if (arr[j] == D[k].getOrank()) {
				if (D[k].getstatus() == 1) {
					cout << "ID:" << D[k].getdid() << ", Rating:" << D[k].getOrank() << endl;;
					break;
				}

			}
		}
	}
	cout << "Free Vehicles\n";
	for (int j = 0; j < Vno; j++) {
		for (int k = 0; k < Vno; k++) {
			if (arr1[j] == V[k].getOrank()) {
				if (V[k].getstatus() == 0) {
					cout << "ID:" << V[k].getvid() << ", Rating:" << V[k].getOrank() << endl;;
					break;
				}

			}
		}
	}
	cout << "Select Driver and Vehicle From above\n";
	int id1 = 0, id2 = 0;
	cout << "Enter id of Driver of four digit\n";
	cin >> id1;
	cout << "Enter id of Vehicle of four digit\n";
	cin >> id2;

	cout << "For Further Features of vehicle\n1) AC->Rs:50\n 2)LED->Rs:40\n 3)Music->Rs:30\n";
	int x, l, z;
	cout << "For Use Feature 1 press 1 else 0\n";
	cin >> x;
	cout << "For Use Feature 2 press 1 else 0\n";
	cin >> l;
	cout << "For Use Feature 3 press 1 else 0\n";
	cin >> z;

	Date d2;
	mTime t2;
	int y = 0, d1, m1, y2, n, hr, min, sec, f, s1 = 0;
	string a, s2, s3;
	float y1 = 0, y3, y4, d;
	if (1) {


		cout << "Press 1 for ride/Press 2 for delivery\n";

		cin >> y;

		if (y == 1) {

			cout << "Enter Ridetype (Intracity-Intercity)\n";
			cin >> a;

		}
		else if (y == 2) {

			cout << "Enter goodstype\n";
			cin >> a;

			cout << "Enter goodsweigth\n";
			cin >> y1;


		}





		if (y == 1) {
			cout << "Enter No of Passengers\n";
			cin >> n;
		}


		cout << "Enter Booking Date\n";
		cout << "Day:";

		cin >> d1;


		cout << "month:";
		cin >> m1;

		cout << "year:";

		cin >> y2;

		cout << "Enter Booking Time\n";

		cout << "Hours:";
		cin >> hr;

		cout << "Min:";
		cin >> min;

		cout << "Sec:";
		cin >> sec;

		cout << "Enter Distance \n";

		cin >> d;

		d2.setday(d1);
		d2.setmonth(m1);
		d2.setyear(y1);
		t2.sethour(hr);
		t2.setmin(min);
		t2.setsec(sec);

		cout << "Enter Fuel Rate of Ride\n";

		cin >> f;
		if (y == 1) {
			cout << "Enter Driver Ranking\n";

			cin >> y3;

			cout << "Enter Vehicle Ranking\n";
			cin >> y4;
		}



		cin.ignore();
		cout << "Enter Source of Ride or Deliver\n";
		getline(cin, s2);
		cin.ignore();
		cout << "Enter Destination\n";
		getline(cin, s3);

		out << 0 << "/" << id;
		out << "/" << y << "/";
		if (y == 1) {
			out << a << "/" << n << "/";
		}
		else if (y == 2) {
			out << a << "/" << y1 << "/";
		}
		out << id1 << "/" << id2 << "/";

		out << d1 << "," << m1 << "," << y2 << "/" << hr << ":" << min << ":" << sec << "/";
		out << d << "/" << s1 << "/" << f << "/";
		if (y == 1) {
			out << y3 << "/" << y4 << "/";
		}
		out << s2 << "/" << s3;


		out << "." << "\n";

	}
	float cost = 0;
	if (x) {
		cost += 50;
	}
	if (l) {
		cost += 40;
	}
	if (z) {
		cost += 30;
	}
	cost = cost + (f * d) / 5;

	cout << "Total Cost of service: " << cost << endl;

	ofstream outt("Vehicle.txt", ios::app);
	outt << 0 << "/" << id2;
	outt << "/" << y << "/";
	if (y == 1) {
		outt << a << "/" << n << "/";
	}
	else if (y == 2) {
		outt << a << "/" << y1 << "/";
	}
	outt << id << "/" << id1 << "/";

	outt << d1 << "," << m1 << "," << y2 << "/" << hr << ":" << min << ":" << sec << "/";
	outt << d << "/" << s1 << "/" << f << "/";
	if (y == 1) {
		outt << y3 << "/" << y4 << "/";
	}
	outt << s2 << "/" << s3;

	outt << "." << "\n";

	ofstream outp("Driver.txt", ios::app);
	outp << 0 << "/" << id1;
	outp << "/" << y << "/";
	if (y == 1) {
		outp << a << "/" << n << "/";
	}
	else if (y == 2) {
		outp << a << "/" << y1 << "/";
	}
	outp << id << "/" << id2 << "/";

	outp << d1 << "," << m1 << "," << y2 << "/" << hr << ":" << min << ":" << sec << "/";
	outp << d << "/" << s1 << "/" << f << "/";
	if (y == 1) {
		outp << y3 << "/" << y4 << "/";
	}
	outp << s2 << "/" << s3;
	outp << "." << "\n";
	out.close();
	outp.close();
	outt.close();

	char* destination, * source, * goodstype;
	destination = new char[20];
	goodstype = new char[20];
	source = new char[20];
	int j;
	for (j = 0; s2[j] != '\0'; j++) {
		source[j] = s2[j];
	}
	source[j] = '\0';
	for (j = 0; s3[j] != '\0'; j++) {
		destination[j] = s3[j];
	}
	destination[j] = '\0';

	for (j = 0; a[j] != '\0'; j++) {
		goodstype[j] = a[j];
	}
	goodstype[j] = '\0';


	Ride Rid;
	Delivery Del;

	for (i = 0; i < Vno; i++) {
		if (id2 == V[i].getvid()) {
			break;
		}
	}

	for (i = 0; i < Dno; i++) {
		if (id1 == D[i].getdid()) {
			break;
		}
	}
	int k;
	for (k = 0; i < Cno; i++) {
		if (id == C[i].getid()) {
			break;
		}
	}
	if (y == 1) {

		Del.setboktime(t2);
		Del.setcid(id);
		Del.setdestination(destination);
		Del.setdid(id1);
		Del.setdistance(d);
		Del.setstatus(0);
		Del.setsource(source);
		Del.setvid(id2);

		Del.setGtype(goodstype);
		Del.setGw8(y1);
		Del.setfuelrate(f);

		C[k].setdel(Del);
		D[j].setdel(Del);
		V[i].setdel(Del);


	}


	else if (y == 2) {


		Rid.setboktime(t2);

		Rid.setcid(id);

		Rid.setdestination(destination);

		Rid.setdid(id1);
		Rid.setdistance(d);
		Rid.setstatus(0);
		Rid.setsource(source);
		Rid.setvid(id1);
		Rid.setnop(n);
		Rid.setD_rank(y3);
		Rid.setV_rank(y4);
		Rid.setRtype(goodstype);
		Rid.setfuelrate(f);

		C[k].setride(Rid);
		D[j].setride(Rid);
		V[i].setride(Rid);

	}
	D[j].setstatus(0);
	V[i].setstatus(0);

}
//-------------------------------------------------ADD DRIVER-----------------------------------------
void TMS::add_driver() {

	cout << "ADD DRIVER\n";

	int id = 0, m, d, y, age, nl = 0;
	float r1 = 0, sal = 0;
	int i, e1, s1;
	Date D1;
	Name N;
	char* Fn;
	char* Ln;
	Fn = new char[15];
	Ln = new char[15];
	char** lis;
	lis = new char* [nl];
	for (i = 0; i < nl; i++) {
		lis[i] = new char[25];
	}



	cout << "Enter First Name:";
	cin >> Fn;
	cout << "Enter Last Name:";
	cin >> Ln;
	cout << "Enter ID\n";
	cin >> id;
	for (int i = 0; i < Dno; i++) {
		if (D[i].getdid() == id) {
			cout << "Id already exist please enter again\n";
			cin >> id;
			i = 0;
		}

	}
	cout << "Enter Date of Birth\n";
	cout << "Day:";
	cin >> d;
	cout << "Month:";
	cin >> m;
	cout << "Year:";
	cin >> y;
	D1.setday(d);
	D1.setmonth(m);
	D1.setyear(y);
	cout << "Enter Age:";
	cin >> age;
	D[Dno].setage(age);
	D[Dno].setdid(id);
	D[Dno].setname(Fn, Ln);
	D[Dno].setdob(D1);
	Dno++;

	cout << "How Many Lisence do You have\n";

	cin >> nl;

	lis = new char* [nl];
	cout << "Enter Type of Lisence\n";
	cin.ignore();
	for (i = 0; i < nl; i++) {
		lis[i] = new char[25];
		cin.getline(lis[i], 25);
	}
	cout << "Enter overall Ranking of Driver\n";

	cin >> r1;

	cout << "Enter Experience\n";

	cin >> e1;


	cout << "Enter Sallary\n";
	cin >> sal;


	ofstream out("Driver.txt", ios::app);
	out << 1 << "/" << id << "/" << Fn << "," << Ln << "/" << d << "," << m << "," << y << "/" << age << "/";

	out << nl << "/";
	for (int i = 0; i < nl; i++) {
		if (i > 0) {
			out << ",";
		}
		out << lis[i];
	}
	out << "/" << r1 << "/" << e1 << "/" << sal << "/" << 1 << "." << "\n";



}
//---------------------------------Add Vehicle----------------------------------
void TMS::add_vehicle() {
	cout << "ADD VEHICLE\n";


	int id = 0, m, d, y;
	float r1 = 0;
	int i;
	Date D1;





	cout << "Enter ID\n";
	cin >> id;
	for (int i = 0; i < Vno; i++) {
		if (V[i].getvid() == id) {
			cout << "Id already exist please enter again\n";
			cin >> id;
			i = 0;
		}

	}

	int regno, mon1, day1, year1, featno = 0;
	float avgmil;
	char* listype, * fueltype;
	int stat = 0;
	listype = new char[25];
	fueltype = new char[15];
	int* list;
	list = new int[featno];
	char** discrip;
	float* cost;
	cost = new float[featno];
	discrip = new char* [featno];
	for (int i = 0; i < featno; i++) {
		discrip[i] = new char[50];
	}


	cout << "Enter Registeration Number of Vehicle\n";
	cin >> regno;
	cout << "Enter Manufacturing Date\n";
	cout << "Day:";

	cin >> day1;
	cout << "month:";
	cin >> mon1;
	cout << "year:";
	cin >> year1;

	cout << "Enter Average Mileage\n";
	cin >> avgmil;

	cout << "Enter Which Lisence is required for this Vehicle\n";
	cin >> listype;
	cout << "Enter Fuel type\n";
	cin >> fueltype;
	cout << "Enter Status(1 For Booked 0 For Free)\n";
	cin >> stat;
	cout << "Enter How Many Feature this Vehcile has\n";
	cin >> featno;
	list = new int[featno];
	cost = new float[featno];
	discrip = new char* [featno];
	for (int i = 0; i < featno; i++) {
		discrip[i] = new char[50];
	}
	for (int i = 0; i < featno; i++) {
		cout << "Enter Id of Feature\n";
		cin >> list[i];
		cin.ignore();
		cout << "Enter Discription of this feature\n";
		cin.getline(discrip[i], 50);
		cout << "Enter cost of this feature\n";
		cin >> cost[i];
	}
	ofstream out("Driver.txt", ios::app);

	out << 1 << "/" << id << "/" << regno << "/" << day1 << "," << mon1 << "," << year1 << "/" << avgmil << "/";
	for (int i = 0; i < featno; i++) {
		out << list[i] << "," << discrip[i] << "," << cost[i] << "/";
	}
	out << 0 << "." << "\n";
	out.close();
}
//--------------------------------------------------------REMOVE DRIVER----------------------------------------
void TMS::remove_driver() {
	int id;
	cout << "Enter id of driver for remove\n";
	cin >> id;
	int i, check = 0;;
	for (i = 0; i < Dno; i++) {
		if (D[i].getdid() == id) {

			check = 1;
			break;
		}

	}
	if (check == 0) {
		cout << "There is not any driver exist of that id\n";

	}
	else {
		D[i].removedriver();
		reWritesdriver();

		Dno = Dno - 1;

	}

}

void TMS::reWritesdriver() {
	int i = 0;

	ofstream outp("Driver.txt");
	int Id, nol;
	char** lis;
	Date d;

	while (i < Dno) {
		cout << 1 << endl;
		Id = 0, nol = 0;
		lis = D[i].getLislist();
		d = D[i].getdob();
		Id = D[i].getdid();
		if (Id != -1) {
			outp << 1 << "/" << Id << "/";

			outp << D[i].getFname() << "," << D[i].getLname() << "/" << d.getday() << "," << d.getmonth() << "," << d.getyear() << "/" << D[i].getage() << "/";
			nol = D[i].getnoofl();
			outp << nol << "/";
			for (int i = 0; i < nol; i++) {
				if (i > 0) {
					outp << ",";
				}
				outp << lis[i];
			}
			outp << "/" << D[i].getOrank() << "/" << D[i].getexp() << "/" << D[i].getsal() << "/" << D[i].getstatus() << "." << "\n";

		}


		i++;
	}

	i = 0;
	int nr = 0, nd = 0;

	while (i < Dno) {
		nr = D[i].getRlen();
		nd = D[i].getDlen();
		Id = 0;
		mTime t1;
		Date d1;
		Id = D[i].getdid();
		Ride R1;
		Delivery D1;

		if (Id != -1) {



			cout << endl;
			for (int j = 0; j < nr; j++) {
				R1 = D[i].getride(j);
				t1 = R1.getboktime();
				d1 = R1.getbokdate();
				outp << 0 << "/" << Id << "/" << 1 << "/" << R1.getRtype() << "/" << R1.getnop() << "/";
				outp << R1.getcid() << "/" << R1.getvid() << "/";
				outp << d1.getday() << "," << d1.getmonth() << "," << d1.getyear() << "/" << t1.gethour() << ":" << t1.getmin() << ":" << t1.getsec() << "/";
				outp << R1.getdistance() << "/" << R1.getfuelrate() << "/" << R1.getstatus() << "/" << R1.getD_rank() << "/";
				outp << R1.getV_rank() << "/" << R1.getsource() << "/" << R1.getdestination() << "." << "\n";
			}
			for (int j = 0; j < nd; j++) {
				D1 = D[i].getdelivery(j);
				t1 = D1.getboktime();
				d1 = D1.getbokdate();
				outp << 0 << "/" << Id << "/" << 2 << "/" << D1.getGtype() << "/" << D1.getGw8() << "/";
				outp << D1.getcid() << "/" << D1.getvid() << "/";
				outp << d1.getday() << "," << d1.getmonth() << "," << d1.getyear() << "/" << t1.gethour() << ":" << t1.getmin() << ":" << t1.getsec() << "/";
				outp << D1.getdistance() << "/" << D1.getstatus() << "/" << D1.getfuelrate() << "/";
				outp << "/" << D1.getsource() << "/" << D1.getdestination() << "." << "\n";
			}

		}
		i++;
	}
}
//------------------------------------Rewrite Vehicle------------------------------------
void TMS::rewritevehicle() {
	ofstream outp("Vehicle.txt");

	int Id;
	Feature F;
	Date d;
	int i = 0;
	while (i < Dno) {
		cout << 1 << endl;
		Id = 0;

		d = V[i].getmfg();
		Id = V[i].getvid();
		if (Id != -1) {
			outp << 1 << "/" << Id << "/" << V[i].getregno() << "/";

			outp << d.getday() << "," << d.getmonth() << "," << d.getyear() << "/" << V[i].getavgmil() << "/";
			outp << V[i].getlsctyp() << "/" << V[i].getfueltype() << "/" << V[i].getOrank() << "/";
			for (int i = 0; i < V[i].getFlen(); i++) {
				F = V[i].getFeat(i);
				outp << F.getfid() << "," << F.getdescrip() << "," << F.getcost() << "/";
			}
			outp << "\n";

		}


		i++;
	}


	int nr = 0, nd = 0;
	i = 0;
	while (i < Vno) {
		nr = V[i].getRlen();
		nd = V[i].getDlen();
		Id = 0;
		mTime t1;
		Date d1;
		Id = V[i].getvid();
		Ride R1;
		Delivery D1;

		if (Id != -1) {

			for (int j = 0; j < nr; j++) {
				R1 = V[i].getride(j);
				t1 = R1.getboktime();
				d1 = R1.getbokdate();
				outp << 0 << "/" << Id << "/" << 1 << "/" << R1.getRtype() << "/" << R1.getnop() << "/";
				outp << R1.getcid() << "/" << R1.getdid() << "/";
				outp << d1.getday() << "," << d1.getmonth() << "," << d1.getyear() << "/" << t1.gethour() << ":" << t1.getmin() << ":" << t1.getsec() << "/";
				outp << R1.getdistance() << "/" << R1.getfuelrate() << "/" << R1.getstatus() << "/" << R1.getD_rank() << "/";
				outp << R1.getV_rank() << "/" << R1.getsource() << "/" << R1.getdestination() << "." << "\n";
			}
			for (int j = 0; j < nd; j++) {
				D1 = V[i].getdelivery(j);
				t1 = D1.getboktime();
				d1 = D1.getbokdate();
				outp << 0 << "/" << Id << "/" << 2 << "/" << D1.getGtype() << "/" << D1.getGw8() << "/";
				outp << D1.getcid() << "/" << D1.getdid() << "/";
				outp << d1.getday() << "," << d1.getmonth() << "," << d1.getyear() << "/" << t1.gethour() << ":" << t1.getmin() << ":" << t1.getsec() << "/";
				outp << D1.getdistance() << "/" << D1.getstatus() << "/" << D1.getfuelrate() << "/";
				outp << "/" << D1.getsource() << "/" << D1.getdestination() << "." << "\n";
			}

		}
		i++;
	}
}
//------------------------------------UPDATE SALLARY---------------------------
void TMS::printupdatesal() {
	int sal = 0;
	int Nsal = 0;
	for (int i = 0; i < Dno; i++) {
		Nsal = 0, sal = 0;
		float a = D[i].getOrank();
		if (a > 4.5) {
			sal = D[i].getsal();
			Nsal = sal + (sal * 15) / 100;
			D[i].setsal(Nsal);
			cout << "Salary Update of Driver, ID: " << D[i].getid() << endl;
			cout << "Old Salry:" << sal << endl;
			cout << "New Sal:" << Nsal << endl;
		}

	}
	reWritesdriver();
}
//-------------------------------REMOVE VEHICLE-------------------------------------
void TMS::remove_vehicle() {
	int id;
	cout << "Enter id of Vehicle for remove\n";
	cin >> id;
	int i, check = 0;;
	for (i = 0; i < Vno; i++) {
		if (V[i].getvid() == id) {

			check = 1;
			break;
		}

	}
	if (check == 0) {
		cout << "There is not any Vehicle exist of that id\n";

	}
	else {
		V[i].removevehicle();
		rewritevehicle();

		Vno = Vno - 1;

	}

}
//----------------------------------PRINT LIST OF ALL CUSTOMERS----------------------------------------
void TMS::printcustom() {
	if (Cno <= 0) {
		cout << "There is not any Customer exist\n";
	}
	else {
		cout << "CUSTOMERS LIST\n";
		for (int i = 0; i < Cno; i++) {

			cout << i + 1 << "." << "Name:" << C[i].getFname() << " " << C[i].getLname() << ", ID: " << C[i].getcid() << endl;
		}
	}
}
//----------------------------------PRINT LIST OF ALL DRIVERS----------------------------------------
void TMS::printdriver() {
	if (Dno <= 0) {
		cout << "There is not any Driver exist\n";
	}
	else {
		cout << "DRIVERS LIST\n";
		for (int i = 0; i < Dno; i++) {
			int id = D[i].getdid();
			if( id!=-1){
				cout << i + 1 << "." << "Name:" << D[i].getFname() << " " << D[i].getLname() << ", ID: " << D[i].getdid() << endl;
			}
			
		}
	}
}
//----------------------------------Print List of All Vehicles-----------------------------------------
void TMS::printvehicle() {
	char* a;

	int check1 = 0;

	if (Vno == 0) {
		cout << "There is not any Vehicle exist\n";
	}
	else {
		cout << "Vehicle LIST\n\n";
		cout << "HEAVY VEHICLE:\n\n";
		for (int i = 0; i < Vno; i++) {
			if (i == 0 || i == 11 || i == 5 || i == 10) {
				cout << V[i] << endl;
			}
		}
		cout << "LIGHT VEHICLE:\n\n";
		for (int i = 0; i < Vno; i++) {
			if (i == 3) {
				cout << V[i] << endl;
			}
		}
		cout << "SMALL VEHICLE:\n\n";
		for (int i = 0; i < Vno; i++) {
			if (i == 7 || i == 2 || i == 8 || i == 6) {
				cout << V[i] << endl;
			}
		}
		cout << "LARGE VEHICLE:\n\n";
		for (int i = 0; i < Vno; i++) {
			if (i != 0 && i != 11 && i != 5 && i != 10 && i != 7 && i != 2 && i != 8 && i != 6 && i != 3) {
				cout << V[i] << endl;
			}
		}
	}
}
//---------------------------Print Pending services of patricular driver------------------------------
void TMS::Driverpendser() {
	cout << "Enter Driver id\n";
	int id;
	cin >> id;
	int check = 0, check1 = 0;
	int i, id1;
	for (i = 0; i < Dno; i++) {
		id1 = D[i].getdid();
		if (id == id1) {
			check = 1;
			break;

		}
	}

	if (check) {
		for (int j = 0; j < D[i].getRlen(); j++) {
			Ride r;
			if (D[i].getstatusR(j) == 0) {
				r = D[i].getride(j);
				check1 = 1;
				cout << r;
			}
		}
		if (!check1) {
			cout << "There is not any Pending Ride Exist of this Driver\n";
		}
		check1 = 0;
		for (int j = 0; j < D[i].getDlen(); j++) {
			Delivery d;
			if (D[i].getstatusD(j) == 0) {
				d = D[i].getdelivery(j);
				check1 = 1;
				cout << d;
			}
		}
		if (!check1) {
			cout << "There is not any Pending Delivery Exist of this Driver\n";
		}
	}
	else {
		cout << "There is not any Driver Exist of this id\n";
	}
}
//----------------------------Print cancelled services by a customer-----------------------------------
void TMS::cancelservice() {
	cout << "Enter Customer id\n";
	int id;
	cin >> id;
	int check = 0, check1 = 0;
	int i, id1;
	for (i = 0; i < Cno; i++) {
		id1 = C[i].getcid();
		if (id == id1) {
			check = 1;
			break;

		}
	}

	if (check) {
		for (int j = 0; j < C[i].getRlen(); j++) {
			Ride r;
			if (C[i].getstatusR(j) == 2) {
				r = C[i].getride(j);
				check1 = 1;
				cout << r;
			}
		}
		if (!check1) {
			cout << "There is not cancelled Ride Exist of this Customer\n";
		}
		check1 = 0;
		for (int j = 0; j < C[i].getDlen(); j++) {
			Delivery d;
			if (C[i].getstatusD(j) == 0) {
				d = C[i].getdelivery(j);
				check1 = 1;
				cout << d;
			}
		}
		if (!check1) {
			cout << "There is not any Cencelled Delivery Exist of this Customer\n";
		}
	}
	else {
		cout << "There is not any Driver Exist of this id\n";
	}
}
//------------------Print Particular Customer Histor-----------------------------------------------
void TMS::printcustomhis() {
	cout << "Enter Customer id\n";
	int id;
	cin >> id;
	int check = 0;
	int i, id1;
	for (i = 0; i < Cno; i++) {
		id1 = C[i].getcid();
		if (id == id1) {
			check = 1;
			break;

		}
	}

	if (check) {
		C[i].printcustom();
	}
}
void TMS::printvehiclehis() {
	cout << "Enter Vehicle id\n";

	int id;
	cin >> id;
	int check = 0;
	int i, id1;
	for (i = 0; i < Vno; i++) {
		id1 = V[i].getvid();
		if (id == id1) {
			check = 1;
			break;

		}
	}
	if (check) {

		cout << V[i];
	}
	if (check) {
		cout << "Vehicle Services Detail\n";
		V[i].printvehicle();
	}
}
void TMS::printdriverhis() {
	cout << "Enter Driver id\n";
	int id;
	cin >> id;
	int check = 0;
	int i, id1;
	for (i = 0; i < Dno; i++) {
		id1 = D[i].getdid();
		if (id == id1) {
			check = 1;
			break;

		}
	}

	if (check) {
		D[i].printdriver();
	}
}
//---------------------
void TMS::printrankdriver() {
	int check = 0;
	int j = 1;
	cout << "\nList of Drivers have more than 4.5 rating\n\n";
	for (int i = 0; i < Dno; i++) {
		float a = D[i].getOrank();
		if (a > 4.5) {
			check = 1;

			cout << j << "." << "Name:" << D[i].getFname() << " " << D[i].getLname() << ", ID: " << D[i].getdid() << endl;
			j++;
		}
	}
	if (!check) {
		cout << "Not any Driver has more than 4.5 rating\n";
	}
}
//------------------------------------------
void TMS::printmultiplelis() {
	int check = 0, a;
	int j = 1;
	cout << "\nList of Driver have multiple license\n\n";
	for (int i = 0; i < Dno; i++) {
		a = D[i].getnoofl();
		if (a > 1) {
			check = 1;
			cout << j << "." << "Name:" << D[i].getFname() << " " << D[i].getLname() << ", ID: " << D[i].getdid() << endl;
			j++;
			D[i].printlislist();
			cout << endl;
		}
	}
	if (!check) {
		cout << "Not any driver has multiple license\n";
	}
}
//------------------------------------------------------MENU-------------------------------------------
void TMS::Menu() {
	cout << "[1]->Add a New Customer\n[2]->Add a New Driver\n[3]->Remove a Driver\n[4]->Add a New Vehicle\n[5]->Remove a Vehicle\n";
	cout << "[6]->Print List of All Customers\n[7]->Print List of All Drivers\n[8]->Print list of all Vehicles with Details by their Category\n";
	cout << "[9]->Print Detail and Service History of Particular Vehicle\n[10]->Print History of a Particluar Customer\n";
	cout << "[11]->Print History of a particular Driver with Servces\n[12]->Print list of all Drivers with Ranking 4.5+\n";
	cout << "[13]->Print list of all Drivers with Multiple Lisences\n[14]->Print Updated Salary of all Drivers\n[15]->Add a Service Request\n";
	cout << "[16]->Cancel a Service\n[17]->Complete a Service\n[18]->Print Details of all Customers who used same Vehicle\n";
	cout << "[19]->Print list of all Drivers who Completed Delivery Service at same Day\n[20]->Print Details of all Pending Services on a Particular Date\n";
	cout << "[21]->Print Details of all Pending Services of a Particluar Driver\n[22]->Print Details of all Cancelled Services by a Particluar Customer\n";
	cout << "[ ]->Any other Button to Exit the Program\n";
}
void TMS::WriteData() {

	int i = 0, j = 0;
	ofstream out("Customer.txt", ios::app);
	ofstream outp("Driver.txt", ios::app);
	ofstream outt("Vehicle.txt");
	while (j < 25) {
		int a1;
		cout << "For Customer Press 1/For Drivery Press 2/For Vehcile Press 3\n";
		cin >> a1;

		cout << "For New Press 1 else 0\n";
		int a2;
		cin >> a2;

		int id;
		cout << "Enter id of 4 digit integer\n";
		cin >> id;

		string x, x1;
		int day, month, year, age;
		if (a2 == 1 && a1 != 3) {
			cout << "Enter First Name\n";

			cin >> x;
			cout << "Enter Last Name\n";

			cin >> x1;

			cout << "Enter Date of Birth\n";
			cout << "Day:";


			cin >> day;

			cout << "month:";
			cin >> month;

			cout << "year:";
			cin >> year;

			cout << "Enter Age\n";

			cin >> age;


		}


		int s1 = 0, nl = 0, e1;
		char** lis;
		lis = new char* [nl];
		for (i = 0; i < nl; i++) {
			lis[i] = new char[25];
		}
		float r1, sal;
		if (a1 == 2 && a2 == 1) {
			cout << "How Many Lisence do You have\n";

			cin >> nl;

			lis = new char* [nl];
			cout << "Enter Type of Lisence\n";
			cin.ignore();
			for (i = 0; i < nl; i++) {
				lis[i] = new char[25];
				cin.getline(lis[i], 25);
			}
			cout << "Enter overall Ranking of Driver\n";

			cin >> r1;

			cout << "Enter Experience\n";

			cin >> e1;


			cout << "Enter Sallary\n";
			cin >> sal;

			cout << "Enter Status of Driver (1 for free, 2 for booked  And 3 For cancelled)\n";
			cin >> s1;
		}

		int regno, mon1, day1, year1, featno = 0;
		float avgmil;
		char* listype, * fueltype;
		int stat = 0;
		listype = new char[25];
		fueltype = new char[15];
		int* list;
		list = new int[featno];
		char** discrip;
		float* cost;
		cost = new float[featno];
		discrip = new char* [featno];
		for (int i = 0; i < featno; i++) {
			discrip[i] = new char[50];
		}
		bool status;
		if (a2 == 1 && a1 == 3) {
			cout << "Enter Registeration Number of Vehicle\n";
			cin >> regno;
			cout << "Enter Manufacturing Date\n";
			cout << "Day:";

			cin >> day1;
			cout << "month:";
			cin >> mon1;
			cout << "year:";
			cin >> year1;

			cout << "Enter Average Mileage\n";
			cin >> avgmil;

			cout << "Enter Which Lisence is required for this Vehicle\n";
			cin >> listype;
			cout << "Enter Fuel type\n";
			cin >> fueltype;
			cout << "Enter Status(1 For Booked 0 For Free)\n";
			cin >> stat;
			cout << "Enter How Many Feature this Vehcile has\n";
			cin >> featno;
			list = new int[featno];
			cost = new float[featno];
			discrip = new char* [featno];
			for (int i = 0; i < featno; i++) {
				discrip[i] = new char[50];
			}
			for (int i = 0; i < featno; i++) {
				cout << "Enter Id of Feature\n";
				cin >> list[i];
				cin.ignore();
				cout << "Enter Discription of this feature\n";
				cin.getline(discrip[i], 50);
				cout << "Enter cost of this feature\n";
				cin >> cost[i];
			}
		}

		int y = 0, id1 = 0, id2 = 0, d1, m1, y2, n, hr, min, sec, f;
		string a, s2, s3;
		float y1 = 0, y3, y4, d;
		if ((stat == 1 || s1 == 0 || s1 == 2 || s1 == 3) && !((a1 == 2 || a1 == 1 || a1 == 3) && a2 == 1)) {


			cout << "Press 1 for ride/Press 2 for delivery\n";

			cin >> y;

			if (y == 1) {

				cout << "Enter Ridetype (Intracity-Intercity)\n";
				cin >> a;

			}
			else if (y == 2) {

				cout << "Enter goodstype\n";
				cin >> a;

				cout << "Enter goodsweigth\n";
				cin >> y1;


			}


			if (a1 == 1) {
				cout << "Enter id of Driver of four digit\n";
				cin >> id1;
				cout << "Enter id of Vehicle of four digit\n";
				cin >> id2;
			}
			else if (a1 == 2) {
				cout << "Enter id of Customer of four digit\n";
				cin >> id1;
				cout << "Enter id of Vehicle of four digit\n";
				cin >> id2;
			}
			else if (a1 == 3) {
				cout << "Enter id of Customer of four digit\n";
				cin >> id1;
				cout << "Enter id of Driver of four digit\n";
				cin >> id2;

			}
			if (y == 1) {
				cout << "Enter No of Passengers\n";
				cin >> n;
			}


			cout << "Enter Booking Date\n";
			cout << "Day:";

			cin >> d1;


			cout << "month:";
			cin >> m1;

			cout << "year:";

			cin >> y2;

			cout << "Enter Booking Time\n";

			cout << "Hours:";
			cin >> hr;

			cout << "Min:";
			cin >> min;

			cout << "Sec:";
			cin >> sec;

			cout << "Enter Distance \n";

			cin >> d;
			if (a1 == 1) {
				cout << "Enter Status of Ride (0 for Pending And 1 For complete)\n";

				cin >> s1;
			}


			cout << "Enter Fuel Rate of Ride\n";

			cin >> f;
			if (y == 1) {
				cout << "Enter Driver Ranking\n";

				cin >> y3;

				cout << "Enter Vehicle Ranking\n";
				cin >> y4;
			}



			cin.ignore();
			cout << "Enter Source of Ride or Deliver\n";
			getline(cin, s2);
			cin.ignore();
			cout << "Enter Destination\n";
			getline(cin, s3);

		}

		if (a1 == 1) {

			out << a2 << "/" << id;
			if (a2 == 1) {
				out << "/" << x << "," << x1 << "/" << day << "," << month << "," << year << "/" << age;
			}
			if (!(a2 == 1)) {
				out << "/" << y << "/";
				if (y == 1) {
					out << a << "/" << n << "/";
				}
				else if (y == 2) {
					out << a << "/" << y1 << "/";
				}
				out << id1 << "/" << id2 << "/";

				out << d1 << "," << m1 << "," << y2 << "/" << hr << ":" << min << ":" << sec << "/";
				out << d << "/" << s1 << "/" << f << "/";
				if (y == 1) {
					out << y3 << "/" << y4 << "/";
				}
				out << s2 << "/" << s3;

			}
			out << "." << "\n";
		}

		else if (a1 == 2) {
			outp << a2 << "/" << id << "/";
			if (a2 == 1) {
				outp << x << "," << x1 << "/" << day << "," << month << "," << year << "/" << age << "/";

				outp << nl << "/";
				for (int i = 0; i < nl; i++) {
					if (i > 0) {
						outp << ",";
					}
					outp << lis[i];
				}
				outp << "/" << r1 << "/" << e1 << "/" << sal << "/" << s1;
			}

			if (!(a2 == 1)) {
				outp << "/" << y << "/";
				if (y == 1) {
					outp << a << "/" << n << "/";
				}
				else if (y == 2) {
					outp << a << "/" << y1 << "/";
				}
				outp << id1 << "/" << id2 << "/";

				outp << d1 << "," << m1 << "," << y2 << "/" << hr << ":" << min << ":" << sec << "/";
				outp << d << "/" << s1 << f << "/";
				if (y == 1) {
					out << y3 << "/" << y4 << "/";
				}
				outp << s2 << "/" << s3;

			}
			outp << "." << "\n";
		}
		else if (a1 == 3) {
			outt << a2 << "/" << id << "/";
			if (a2 == 1) {
				outt << regno << "/" << day1 << "," << mon1 << "," << year1 << "/" << avgmil << "/" << listype << "/" << fueltype;
				outt << "/" << featno << "/";
				for (int i = 0; i < featno; i++) {
					outt << list[i] << "," << discrip[i] << "," << cost[i] << "/";
				}
				outt << stat;

			}


			if (!(a2 == 1)) {
				outt << "/" << y << "/";
				if (y == 1) {
					outt << a << "/" << n << "/";
				}
				else if (y == 2) {
					outt << a << "/" << y1 << "/";
				}
				outt << id1 << "/" << id2 << "/";
				outt << d1 << "," << m1 << "," << y2 << "/" << hr << ":" << min << ":" << sec << "/";
				outt << d << "/" << s1 << f << "/";
				if (y == 1) {
					out << y3 << "/" << y4 << "/";
				}
				outt << s2 << "/" << s3;
			}

			outt << "." << "\n";
		}
		j++;
	}
	out.close();
	outp.close();
	outt.close();
}
void TMS::cancelRD() {
	float cost = 5000;
	cout << "Enter id of customer to cancel service\n";
	int id;
	cin >> id;
	int check = 0;
	int i;
	for (i = 0; i < Cno; i++) {
		if (id == C[i].getid()) {
			check = 1;
			break;
		}
	}
	if (!check) {
		cout << "There is not any customer exist of that id\n";
	}
	if (check) {
		C[i].setstatusR(1);
		cout << "Ride Cancelled\n";
		cout << "Fine for cancel Service is " << ((cost * 5) / 100) << endl;
	}
}
void TMS::completeRD() {
	cout << "Enter id of customer to complete service\n";
	int id;
	cin >> id;
	int check = 0;
	int i;
	for (i = 0; i < Cno; i++) {
		if (id == C[i].getid()) {
			check = 1;
			break;
		}
	}
	if (!check) {
		cout << "There is not any customer exist of that id\n";
	}
	if (check) {
		C[i].setstatusR(1);
		cout << "Ride Completed\n";
	}
}
void TMS::ReadData() {

	ifstream inp;
	inp.open("Customer.txt");
	string str;

	//x->New or Old, x2->Ride or Delivery
	int x = 0, x2 = 0, id = 0, D_id = 0, V_id = 0, Nop = 0, day1 = 0, mon1 = 0, year1 = 0, age = 0, stats = 0;
	int  hr = 0, min = 0, sec = 0, check = 0;

	float dist = 0, D_rank = 0, V_rank = 0, fuelrate = 0, G_W = 0;
	char* source;
	char* destination;
	source = new char[30];
	destination = new char[30];


	int i, j, k = 0;
	char* R_G_t;//Ride or good type

	char* Fn, * Ln;
	Fn = new char[15];
	Ln = new char[15];
	R_G_t = new char[20];
	int mn = 0;
	getline(inp, str);
	while (!inp.eof()) {
		Name N1;
		Date D1, D2, D3;
		mTime T1;
		Delivery Del;
		Ride Rid;
		x = 0, x2 = 0, id = 0, D_id = 0, V_id = 0, G_W = 0, Nop = 0, day1 = 0, mon1 = 0, year1 = 0, age = 0, stats = 0;
		dist = 0, hr = 0, min = 0, sec = 0, check = 0, D_rank = 0, V_rank = 0, fuelrate = 0;

		source = new char[30];
		destination = new char[30];
		R_G_t = new char[20];
		Fn = new char[15];
		Ln = new char[15];
		//cout << str << endl;
		//New or Old
		for (i = 0; str[i] != '/'; i++) {
			x = x * 10 + (str[i] - 48);
		}
		i++;

		//Id
		for (; str[i] != '/'; i++) {
			id = id * 10 + (str[i] - 48);
		}
		i++;


		if (x == 1) {
			//First Name
			for (j = 0; str[i] != ','; j++, i++) {
				Fn[j] = str[i];
			}
			Fn[j] = '\0';
			i++;

			//Last Name
			for (j = 0; str[i] != '/'; j++, i++) {
				Ln[j] = str[i];
			}
			Ln[j] = '\0';
			i++;

			//Date of Birth
			for (; str[i] != ','; i++) {
				day1 = day1 * 10 + (str[i] - 48);
			}
			i++;

			for (; str[i] != ','; i++) {
				mon1 = mon1 * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != '/'; i++) {
				year1 = year1 * 10 + (str[i] - 48);
			}
			i++;

			//Age
			for (; str[i] != '.'; i++) {
				age = age * 10 + (str[i] - 48);
			}
			i++;
			D1.setday(day1);
			D1.setmonth(mon1);
			D1.setyear(year1);


		}

		if (x == 0) {
			//Ride or Delivery
			for (; str[i] != '/'; i++) {
				x2 = x2 * 10 + (str[i] - 48);
			}
			i++;

			//Ride

			if (x2 == 1) {
				for (j = 0; str[i] != '/'; j++, i++) {
					R_G_t[j] = str[i];
				}
				R_G_t[j] = '\0';
				i++;
				for (; str[i] != '/'; i++) {
					Nop = Nop * 10 + (str[i] - 48);
				}
				i++;

			}//Delivery
			else if (x2 == 2) {
				for (j = 0; str[i] != '/'; j++, i++) {
					R_G_t[j] = str[i];
				}
				i++;
				R_G_t[j] = '\0';
				stringstream str4;
				for (j = 0; str[i] != '/'; i++, j++) {
					str4 << str[i];
				}
				str4 >> G_W;
				i++;


			}

			//Driver and Vehicle id
			for (; str[i] != '/'; i++) {
				D_id = D_id * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != '/'; i++) {
				V_id = V_id * 10 + (str[i] - 48);
			}
			i++;

			//Booking Date
			for (; str[i] != ','; i++) {
				day1 = day1 * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != ','; i++) {
				mon1 = mon1 * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != '/'; i++) {
				year1 = year1 * 10 + (str[i] - 48);
			}
			i++;
			D2.setday(day1);
			D2.setmonth(mon1);
			D2.setyear(year1);
			//Booking Time
			for (; str[i] != ':'; i++) {
				hr = hr * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != ':'; i++) {
				min = min * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != '/'; i++) {
				sec = sec * 10 + (str[i] - 48);
			}
			i++;
			T1.sethour(hr);
			T1.setmin(min);
			T1.setsec(sec);
			//Distance

			for (; str[i] != '/'; i++) {
				dist = dist * 10 + (str[i] - 48);
			}
			i++;
			//Status
			for (; str[i] != '/'; i++) {
				stats = stats * 10 + (str[i] - 48);
			}
			i++;

			//Fuel Rate
			stringstream str1;
			for (j = 0; str[i] != '/'; i++, j++) {
				str1 << str[i];
			}
			str1 >> fuelrate;
			i++;
			if (x2 == 1) {
				stringstream str2;

				//Driver Rank
				for (j = 0; str[i] != '/'; i++, j++) {
					str2 << str[i];
				}
				str2 >> D_rank;
				i++;
				//Vehicle Rank
				stringstream str3;
				for (j = 0; str[i] != '/'; i++, j++) {
					str3 << str[i];
				}
				str3 >> V_rank;
				i++;
			}


			//Source
			for (j = 0; str[i] != '/'; j++, i++) {
				source[j] = str[i];
			}
			source[j] = '\0';
			i++;

			//Destination
			for (j = 0; str[i] != '.'; j++, i++) {
				destination[j] = str[i];
			}
			destination[j] = '\0';
			i++;

			if (x == 0) {

				for (k = 0; k < Cno; k++) {

					if (C[k].getcid() == id) {

						break;
					}
				}
			}
		}


		if (x == 1) {
			C[Cno].setage(age);
			C[Cno].setcid(id);
			C[Cno].setname(Fn, Ln);
			C[Cno].setdob(D1);
			Cno++;


		}
		if (x2 == 2 && x == 0) {

			Del.setboktime(T1);
			Del.setcid(id);
			Del.setdestination(destination);
			Del.setdid(D_id);
			Del.setdistance(dist);
			Del.setstatus(stats);
			Del.setsource(source);
			Del.setvid(V_id);

			Del.setGtype(R_G_t);
			Del.setGw8(G_W);
			Del.setfuelrate(fuelrate);

			C[k].setdel(Del);

		}
		else if (x2 == 1 && x == 0) {


			Rid.setboktime(T1);

			Rid.setcid(id);

			Rid.setdestination(destination);

			Rid.setdid(D_id);
			Rid.setdistance(dist);
			Rid.setstatus(stats);
			Rid.setsource(source);
			Rid.setvid(V_id);
			Rid.setnop(Nop);
			Rid.setD_rank(D_rank);
			Rid.setV_rank(V_rank);
			Rid.setRtype(R_G_t);
			Rid.setfuelrate(fuelrate);

			C[k].setride(Rid);

		}

		delete[]source;
		delete[]destination;
		delete[]R_G_t;
		delete[]Fn;
		delete[]Ln;


		getline(inp, str);

	}
	;
	inp.close();



}
void TMS::D_ReadData() {
	//---------------------------------------DRIVER----------------------
	ifstream input;
	input.open("Driver.txt");

	string str;
	//x->New or Old, x2->Ride or Delivery
	int x = 0, x2 = 0, id = 0, D_id = 0, V_id = 0, Nop = 0, day1 = 0, mon1 = 0, year1 = 0, age = 0, stats = 0;
	int  hr = 0, min = 0, sec = 0, check = 0;

	float dist = 0, D_rank = 0, V_rank = 0, fuelrate = 0, G_W = 0;
	char* source;
	char* destination;
	source = new char[30];
	destination = new char[30];


	int i, j, k = 0;
	char* R_G_t;//Ride or good type

	char* Fn, * Ln;
	Fn = new char[15];
	Ln = new char[15];
	R_G_t = new char[20];

	float Orannk;
	i = 0, j = 0, k = 0;
	int Noofl = 0, exp = 0;
	float sal = 0;
	char** List;
	List = new char* [Noofl];

	getline(input, str);
	while (!input.eof()) {


		Name N1;
		Date D1, D2, D3;
		mTime T1;
		Delivery del;
		Ride Rid;
		x = 0, x2 = 0, id = 0, D_id = 0, V_id = 0, G_W = 0, Nop = 0, day1 = 0, mon1 = 0, year1 = 0, age = 0, stats = 0;
		dist = 0, hr = 0, min = 0, sec = 0, check = 0, D_rank = 0, V_rank = 0, fuelrate = 0, Orannk = 0, sal = 0, exp = 0, Noofl = 0;
		List = new char* [Noofl];
		source = new char[30];
		destination = new char[30];
		R_G_t = new char[20];
		Fn = new char[15];
		Ln = new char[15];

		//New or Old
		for (i = 0; str[i] != '/'; i++) {
			x = x * 10 + (str[i] - 48);
		}
		i++;

		//Id
		for (; str[i] != '/'; i++) {
			D_id = D_id * 10 + (str[i] - 48);
		}
		i++;


		if (x == 1) {
			//First Name
			for (j = 0; str[i] != ','; j++, i++) {
				Fn[j] = str[i];
			}
			Fn[j] = '\0';
			i++;

			//Last Name
			for (j = 0; str[i] != '/'; j++, i++) {
				Ln[j] = str[i];
			}
			Ln[j] = '\0';
			i++;

			//Date of Birth
			for (; str[i] != ','; i++) {
				day1 = day1 * 10 + (str[i] - 48);
			}
			i++;

			for (; str[i] != ','; i++) {
				mon1 = mon1 * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != '/'; i++) {
				year1 = year1 * 10 + (str[i] - 48);
			}
			i++;
			D1.setday(day1);
			D1.setmonth(mon1);
			D1.setyear(year1);

			//Age
			for (; str[i] != '/'; i++) {
				age = age * 10 + (str[i] - 48);
			}
			i++;
			//No of Lisence
			for (; str[i] != '/'; i++) {
				Noofl = Noofl * 10 + (str[i] - 48);
			}
			i++;
			//Lisence List
			List = new char* [Noofl];
			for (j = 0; j < Noofl; j++) {
				List[j] = new char[20];
			}
			for (j = 0; j < Noofl; j++) {
				for (k = 0; str[i] != ',' && str[i] != '/'; k++, i++) {
					List[j][k] = str[i];
				}
				List[j][k] = '\0';
				i++;
			}

			stringstream str5;

			for (j = 0; str[i] != '/'; i++, j++) {
				str5 << str[i];
			}
			str5 >> Orannk;
			i++;
			for (; str[i] != '/'; i++) {
				exp = exp * 10 + (str[i] - 48);
			}
			i++;
			stringstream str6;

			for (j = 0; str[i] != '/'; i++, j++) {
				str6 << str[i];
			}
			str6 >> sal;

			i++;
			for (; str[i] != '.'; i++) {
				stats = stats * 10 + (str[i] - 48);
			}
			i++;

		}

		if (x == 0) {
			//Ride or Delivery
			for (; str[i] != '/'; i++) {
				x2 = x2 * 10 + (str[i] - 48);
			}
			i++;

			//Ride

			if (x2 == 1) {
				for (j = 0; str[i] != '/'; j++, i++) {
					R_G_t[j] = str[i];
				}
				R_G_t[j] = '\0';
				i++;
				for (; str[i] != '/'; i++) {
					Nop = Nop * 10 + (str[i] - 48);
				}
				i++;

			}//Delivery
			else if (x2 == 2) {
				for (j = 0; str[i] != '/'; j++, i++) {
					R_G_t[j] = str[i];
				}
				i++;
				R_G_t[j] = '\0';

				stringstream str9;

				for (j = 0; str[i] != '/'; i++, j++) {
					str9 << str[i];
				}
				str9 >> G_W;

				i++;

			}

			//Customer and Vehicle id
			for (; str[i] != '/'; i++) {
				id = id * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != '/'; i++) {
				V_id = V_id * 10 + (str[i] - 48);
			}
			i++;

			//Booking Date
			for (; str[i] != ','; i++) {
				day1 = day1 * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != ','; i++) {
				mon1 = mon1 * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != '/'; i++) {
				year1 = year1 * 10 + (str[i] - 48);
			}
			i++;
			D2.setday(day1);
			D2.setmonth(mon1);
			D2.setyear(year1);
			//Booking Time
			for (; str[i] != ':'; i++) {
				hr = hr * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != ':'; i++) {
				min = min * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != '/'; i++) {
				sec = sec * 10 + (str[i] - 48);
			}
			i++;
			T1.sethour(hr);
			T1.setmin(min);
			T1.setsec(sec);
			//Distance

			for (; str[i] != '/'; i++) {
				dist = dist * 10 + (str[i] - 48);
			}
			i++;
			//Status
			for (; str[i] != '/'; i++) {
				stats = stats * 10 + (str[i] - 48);
			}
			i++;

			//Fuel Rate
			stringstream str1;
			for (j = 0; str[i] != '/'; i++, j++) {
				str1 << str[i];
			}
			str1 >> fuelrate;
			i++;
			if (x2 == 1) {
				stringstream str2;

				//Driver Rank
				for (j = 0; str[i] != '/'; i++, j++) {
					str2 << str[i];
				}
				str2 >> D_rank;
				i++;
				//Vehicle Rank
				stringstream str3;
				for (j = 0; str[i] != '/'; i++, j++) {
					str3 << str[i];
				}
				str3 >> V_rank;
				i++;

			}

			//Source
			for (j = 0; str[i] != '/'; j++, i++) {
				source[j] = str[i];
			}
			source[j] = '\0';
			i++;

			//Destination
			for (j = 0; str[i] != '.'; j++, i++) {
				destination[j] = str[i];
			}
			destination[j] = '\0';
			i++;

			if (x == 0) {

				for (k = 0; k < Dno; k++) {

					if (D[k].getdid() == D_id) {

						break;
					}
				}
			}
		}


		if (x == 1) {
			D[Dno].setage(age);
			D[Dno].setdid(D_id);
			D[Dno].setname(Fn, Ln);
			D[Dno].setdob(D1);
			D[Dno].setsal(sal);
			D[Dno].setnoofl(Noofl);
			D[Dno].setOrank(Orannk);
			D[Dno].setstatus(stats);
			D[Dno].setexp(exp);
			D[Dno].setLislist(List);

			Dno++;


		}
		if (x2 == 2 && x == 0) {
			del.setbokdate(D2);
			del.setboktime(T1);
			del.setcid(id);
			del.setdestination(destination);
			del.setdid(D_id);
			del.setdistance(dist);
			del.setstatus(stats);
			del.setsource(source);
			del.setvid(V_id);
			del.setGtype(R_G_t);
			del.setGw8(G_W);
			del.setfuelrate(fuelrate);
			D[k].setdel(del);

		}
		else if (x2 == 1 && x == 0) {

			Rid.setbokdate(D2);

			Rid.setboktime(T1);

			Rid.setcid(id);

			Rid.setdestination(destination);

			Rid.setdid(D_id);
			Rid.setdistance(dist);
			Rid.setstatus(stats);
			Rid.setsource(source);
			Rid.setvid(V_id);
			Rid.setnop(Nop);
			Rid.setD_rank(D_rank);
			Rid.setV_rank(V_rank);
			Rid.setRtype(R_G_t);
			Rid.setfuelrate(fuelrate);

			D[k].setride(Rid);

		}

		delete[]source;
		delete[]destination;
		delete[]R_G_t;
		delete[]Fn;
		delete[]Ln;


		getline(input, str);

	}

	input.close();

}
void TMS::V_ReadData() {
	ifstream inpt;
	inpt.open("Vehicle.txt");

	string str;
	//x->New or Old, x2->Ride or Delivery
	int x = 0, x2 = 0, id = 0, D_id = 0, V_id = 0, Nop = 0, day1 = 0, mon1 = 0, year1 = 0, age = 0, stats = 0;
	int  hr = 0, min = 0, sec = 0, check = 0;

	float dist = 0, D_rank = 0, V_rank = 0, fuelrate = 0, G_W = 0;
	char* source;
	char* destination;
	source = new char[30];
	destination = new char[30];


	int i = 0, j = 0, k = 0;
	char* R_G_t;//Ride or good type
	R_G_t = new char[20];
	float Orannk;
	i = 0, j = 0, k = 0;

	Feature* F;

	int regno = 0, NOF = 0, FId = 0;
	float avgmil = 0, cost = 0;

	char* discrp, * Listype, * Fueltype;
	F = new Feature[NOF];
	Fueltype = new char[10];
	Listype = new char[10];
	discrp = new char[20];


	getline(inpt, str);
	//
	while (!inpt.eof()) {



		Date D1, D2, D3;
		mTime T1;
		Delivery del;
		Ride Rid;
		regno = 0, NOF = 0, FId = 0;
		avgmil = 0, cost = 0;

		Fueltype = new char[10];
		Listype = new char[10];
		discrp = new char[20];
		x = 0, x2 = 0, id = 0, D_id = 0, V_id = 0, G_W = 0, Nop = 0, day1 = 0, mon1 = 0, year1 = 0, stats = 0;
		dist = 0, hr = 0, min = 0, sec = 0, check = 0, D_rank = 0, V_rank = 0, fuelrate = 0, Orannk = 0;

		source = new char[30];
		destination = new char[30];
		R_G_t = new char[20];
		//-------		
				//New or Old
		for (i = 0; str[i] != '/'; i++) {
			x = x * 10 + (str[i] - 48);
		}
		i++;

		//Id
		for (; str[i] != '/'; i++) {
			V_id = V_id * 10 + (str[i] - 48);
		}
		i++;


		if (x == 1) {
			for (; str[i] != '/'; i++) {
				regno = regno * 10 + (str[i] - 48);
			}
			i++;

			//Manufacturing Date
			for (; str[i] != ','; i++) {
				day1 = day1 * 10 + (str[i] - 48);
			}
			i++;

			for (; str[i] != ','; i++) {
				mon1 = mon1 * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != '/'; i++) {
				year1 = year1 * 10 + (str[i] - 48);
			}
			i++;
			D1.setday(day1);
			D1.setmonth(mon1);
			D1.setyear(year1);

			stringstream str1;

			for (j = 0; str[i] != '/'; i++, j++) {
				str1 << str[i];
			}
			str1 >> avgmil;
			i++;

			//Liscense
			for (j = 0; str[i] != '/'; i++, j++) {
				Listype[j] = str[i];
			}
			i++;
			Listype[j] = '\0';
			//Fuel Type
			for (j = 0; str[i] != '/'; i++, j++) {
				Fueltype[j] = str[i];
			}
			i++;
			Fueltype[j] = '\0';
			stringstream str5;

			for (j = 0; str[i] != '/'; i++, j++) {
				str5 << str[i];
			}
			str5 >> Orannk;
			i++;

			for (; str[i] != '/'; i++) {
				NOF = NOF * 10 + (str[i] - 48);
			}
			i++;


			F = new Feature[NOF];
			for (j = 0; j < NOF; j++) {
				discrp = new char[20];
				for (; str[i] != ','; i++) {
					FId = FId * 10 + (str[i] - 48);
				}
				i++;
				for (k = 0; str[i] != ','; k++, i++) {
					discrp[k] = str[i];
				}
				discrp[k] = '\0';
				i++;
				for (; str[i] != '/'; i++) {
					cost = cost * 10 + (str[i] - 48);
				}
				i++;
				F[j].setcost(cost);
				F[j].setfid(FId);
				F[j].setdescrip(discrp);
			}
			for (; str[i] != '.'; i++) {
				stats = stats * 10 + (str[i] - 48);
			}
			i++;

		}



		if (x == 0) {
			//Ride or Delivery
			for (; str[i] != '/'; i++) {
				x2 = x2 * 10 + (str[i] - 48);
			}
			i++;

			//Ride

			if (x2 == 1) {
				for (j = 0; str[i] != '/'; j++, i++) {
					R_G_t[j] = str[i];
				}
				R_G_t[j] = '\0';
				i++;
				for (; str[i] != '/'; i++) {
					Nop = Nop * 10 + (str[i] - 48);
				}
				i++;

			}//Delivery
			else if (x2 == 2) {
				for (j = 0; str[i] != '/'; j++, i++) {
					R_G_t[j] = str[i];
				}
				i++;
				R_G_t[j] = '\0';

				stringstream str9;

				for (j = 0; str[i] != '/'; i++, j++) {
					str9 << str[i];
				}
				str9 >> G_W;

				i++;

			}

			//Customer and Driver id
			for (; str[i] != '/'; i++) {
				id = id * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != '/'; i++) {
				D_id = D_id * 10 + (str[i] - 48);
			}
			i++;

			//Booking Date
			for (; str[i] != ','; i++) {
				day1 = day1 * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != ','; i++) {
				mon1 = mon1 * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != '/'; i++) {
				year1 = year1 * 10 + (str[i] - 48);
			}
			i++;
			D2.setday(day1);
			D2.setmonth(mon1);
			D2.setyear(year1);
			//Booking Time
			for (; str[i] != ':'; i++) {
				hr = hr * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != ':'; i++) {
				min = min * 10 + (str[i] - 48);
			}
			i++;
			for (; str[i] != '/'; i++) {
				sec = sec * 10 + (str[i] - 48);
			}
			i++;
			T1.sethour(hr);
			T1.setmin(min);
			T1.setsec(sec);
			//Distance

			for (; str[i] != '/'; i++) {
				dist = dist * 10 + (str[i] - 48);
			}
			i++;
			//Status
			for (; str[i] != '/'; i++) {
				stats = stats * 10 + (str[i] - 48);
			}
			i++;

			//Fuel Rate
			stringstream str1;
			for (j = 0; str[i] != '/'; i++, j++) {
				str1 << str[i];
			}
			str1 >> fuelrate;
			i++;
			if (x2 == 1) {
				stringstream str2;

				//Driver Rank
				for (j = 0; str[i] != '/'; i++, j++) {
					str2 << str[i];
				}
				str2 >> D_rank;
				i++;
				//Vehicle Rank
				stringstream str3;
				for (j = 0; str[i] != '/'; i++, j++) {
					str3 << str[i];
				}
				str3 >> V_rank;
				i++;

			}

			//Source
			for (j = 0; str[i] != '/'; j++, i++) {
				source[j] = str[i];
			}
			source[j] = '\0';
			i++;

			//Destination
			for (j = 0; str[i] != '.'; j++, i++) {
				destination[j] = str[i];
			}
			destination[j] = '\0';
			i++;

			if (x == 0) {

				for (k = 0; k < Vno; k++) {

					if (V[k].getvid() == V_id) {

						break;
					}
				}
			}
		}


		if (x == 1) {
			V[Vno].setregno(regno);
			V[Vno].setvid(V_id);
			V[Vno].setavgmil(avgmil);
			V[Vno].setfueltype(Fueltype);//-
			V[Vno].setmfg(D1);
			V[Vno].setlsctyp(Listype);
			V[Vno].setlis(F);
			V[Vno].setOrank(Orannk);
			V[Vno].setstatus(stats);


			Vno++;


		}
		if (x2 == 2 && x == 0) {
			del.setbokdate(D2);
			del.setboktime(T1);
			del.setcid(id);
			del.setdestination(destination);
			del.setdid(D_id);
			del.setdistance(dist);
			del.setstatus(stats);
			del.setsource(source);
			del.setvid(V_id);
			del.setGtype(R_G_t);
			del.setGw8(G_W);
			del.setfuelrate(fuelrate);
			V[k].setdel(del);

		}
		else if (x2 == 1 && x == 0) {

			Rid.setbokdate(D2);

			Rid.setboktime(T1);

			Rid.setcid(id);

			Rid.setdestination(destination);

			Rid.setdid(D_id);
			Rid.setdistance(dist);
			Rid.setstatus(stats);
			Rid.setsource(source);
			Rid.setvid(V_id);
			Rid.setnop(Nop);
			Rid.setD_rank(D_rank);
			Rid.setV_rank(V_rank);
			Rid.setRtype(R_G_t);
			Rid.setfuelrate(fuelrate);

			V[k].setride(Rid);

		}

		delete[]source;
		delete[]destination;
		delete[]R_G_t;


		getline(inpt, str);


	}
	inpt.close();
}

//-------------------------------------TMS END---------------------------------------------------------
void main() {
	cout << "---------------------------------Welcome to FAST Transport Management System------------------------------------------\n";
	TMS a;
	a.Menu();
	a.ReadData();
	a.V_ReadData();
	a.D_ReadData();
	int i;
	while (1) {

		cout << "Perform Function From above\n";
		cin >> i;
		if (i == 1) {
			a.addcustomer();
		}
		else if (i == 2) {
			a.add_driver();
		}
		else if (i == 3) {
			a.remove_driver();
		}
		else if (i == 4) {
			a.add_vehicle();
		}
		else if (i == 5) {
			a.remove_vehicle();
		}
		else if (i == 6) {
			a.printcustom();
		}
		else if (i == 7) {
			a.printdriver();
		}
		else if (i == 8) {
			a.printvehicle();
		}
		else if (i == 9) {
			a.printvehiclehis();
		}
		else if (i == 10) {
			a.printcustomhis();
		}
		else if (i == 11) {
			a.printdriverhis();
		}
		else if (i == 12) {
			a.printrankdriver();
		}
		else if (i == 13) {
			a.printmultiplelis();
		}
		else if (i == 14) {
			a.printupdatesal();
		}
		else if (i == 15) {
			a.addservice();
		}
		else if (i == 16) {
			a.cancelRD();
		}
		else if (i == 17) {
			a.completeRD();
		}
		else if (i == 18) {

		}
		else if (i == 19) {

		}
		else if (i == 20) {

		}
		else if (i == 21) {
			a.Driverpendser();
		}
		else if (i == 22) {
			a.cancelservice();
		}
		else {
			break;
		}
	}




}