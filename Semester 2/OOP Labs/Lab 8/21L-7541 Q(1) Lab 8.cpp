#include<iostream>
using namespace std;
class Box {
	int len;
	int brdt;
	int wid;
	static int obcount;
public:
	//constructor
	Box(int = 0, int = 0, int = 0);
	//static function
	static int getcount();
	//setters
	void setlen(int);
	void setbrdt(int);
	void setwid(int);
	//getters
	int getlen();
	int getwid();
	int getbrdt();
	
	double volume(int, int, int);
	double area(int, int);
	
};

int Box::obcount;
Box::Box(int len, int brdt, int wid) {
	this->len = len;
	this->brdt = brdt;
	this->wid = wid;
	obcount++;
}

int Box::getcount() {
	return obcount;
}
int Box::getbrdt() {
	return this->brdt;
}
int Box::getlen() {
	return this->len;
}
int Box::getwid() {
	return this->wid;
}
void Box::setlen(int len) {
	this->len = len;
}
void Box::setwid(int wid) {
	this->wid = wid;
}
void Box::setbrdt(int brdt) {
	this->brdt = brdt;
}
double Box::volume(int a, int b, int c) {
	double vol;
	vol = a * b * c;
	return vol;
}
double Box::area(int a, int b) {
	double ar;
	ar = a * b ;
	return ar;
}

int main() {
	int len;
	int wid;
	int brdt;
	cout << "Enter length for object 1: ";
	cin >> len;
	cout << "Enter width for object 1: ";
	cin >> wid;
	cout << "Enter breadth for object 1: ";
	cin >> brdt;
	Box ob1(len, brdt, wid);
	cout << "\n\t\t\tDATA OF OBJECT 1\n\n";
	len = ob1.getlen();
	wid = ob1.getwid();
	brdt = ob1.getbrdt();
	cout << "Length of object 1 is " << len << endl;
	cout << "Widgth of object 1 is " << wid << endl;
    cout << "Breadth of object 1 is " << brdt << endl;
	cout << "Area of object 1 is " <<ob1.area(len,wid)  << endl;
	cout << "Volume of object 1 is " << ob1.volume(len, wid,brdt) << endl;
	Box ob2;
	cout << "\nEnter length for object 2: ";
	cin >> len;
	cout << "Enter width for object 2: ";
	cin >> wid;
	cout << "Enter breadth for object 2: ";
	cin >> brdt;
	ob2.setlen(len);
	ob2.setbrdt(brdt);
	ob2.setwid(wid);

	cout << "\n\t\t\tDATA OF OBJECT 2\n\n";
	len = ob2.getlen();
	wid = ob2.getwid();
	brdt = ob2.getbrdt();
	cout << "Length of object 2 is " << len << endl;
	cout << "Widgth of object 2 is " << wid << endl;
	cout << "Breadth of object 2 is " << brdt << endl;
	cout << "Area of object 2 is " << ob1.area(len, wid) << endl;
	cout << "Volume of object 2 is " << ob1.volume(len, wid, brdt) << endl;

	int a=Box::getcount();
	cout << endl;

	cout << "There are " << a << " object is created\n";
}
