#include<iostream>
using namespace std;
class diablo {
private:
	string clr;
	int capacity;
	int seats;
	int ymr;//year of manufacture
	int EN;//engine number
	int frameN;
	string ON;//owner name
public:
	diablo(int,int,int,string);
	void setter(int,int,int,string);
	void getter(int&, int&, int&, int&, int&, string&, string&);
	diablo(const diablo&);
};
diablo::diablo(int yemr=0,int EoN=0,int frameNo=0,string names='\0') {
	clr = "Hot Red";
	seats = 4;
	capacity = 1000;
	ymr = yemr;
	EN = EoN;
	frameN = frameNo;
	
	ON = names;
}
diablo::diablo(const diablo& a) {
	clr = a.clr;
	seats = a.seats;
	capacity = a.capacity;
	
}
void diablo::setter(int yemr , int ENo , int frameNo , string naame ) {
	ymr = yemr;
	
	EN = ENo;
	frameN = frameNo;

	ON = naame;
	cout << ymr << " " << EN << " " << frameN << " " << ON << endl;
}
void diablo::getter(int &a, int &b, int &c, int &d, int &e, string &f, string &g) {
	a = ymr;
	b = EN;
	c = frameN;
	d = capacity;
	e = seats;
	f = ON;
	g = clr;

}
void main() {
	int seats, capacity;
	string clr;

	cout << "Enter the owner name: ";
	string str;
	cin >> str;
	cout << "Enter the engine number: ";
	int en;
	cin >> en;
	cout << "Enter the frame number: ";
	int fn;
	cin >> fn;
	cout << "Enter the year of manufacture: ";
	int ymr;
	cin >> ymr;
	diablo obj1(ymr,en,fn,str);
	//obj1.setter(ymr, en, fn, str);
	obj1.getter(ymr,en,fn,capacity,seats,str,clr);
	cout << "\nInformation of object 1\n\n";
	cout << "Owner Name: " << str << endl;
	cout << "Colour: " << clr << endl;
	cout << "Cubic Capacity: " << capacity << endl;
	cout << "Number of seats: " << seats << endl;
	cout << "Manufacture Year : " << ymr << endl;
	cout << "Engine Number: " << en << endl;
	cout << "Frame Number: " << fn << endl;
	
	diablo obj2(obj1);
	cout << "\nEnter the owner name: ";
	
	cin >> str;
	cout << "Enter the engine number: ";
	
	cin >> en;
	cout << "Enter the frame number: ";

	cin >> fn;
	cout << "Enter the year of manufacture: ";
	
	cin >> ymr;
	
	obj2.setter(ymr, en, fn, str);
	obj2.getter(ymr, en, fn, capacity, seats, str, clr);
	cout << "\n\nInformation of object 2\n\n";
	cout << "Owner Name: " << str << endl;
	cout << "Colour: " << clr << endl;
	cout << "Cubic Capacity: " << capacity << endl;
	cout << "Number of seats: " << seats << endl;
	cout << "Manufacture Year : " << ymr << endl;
	cout << "Engine Number: " << en << endl;
	cout << "Frame Number: " << fn << endl;

}