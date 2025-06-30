#include<iostream>
using namespace std;
class DB;
class DM {
	int met;
	int cent;
public:
	void set(int c, int d) {
		met = c;
		cent = d;
	}
	void print() {
		cout << "Distance is " << met << " meter and " << cent << " centimeters\n";
	}

	friend void add(DM &,DB &,int);
};
class DB {

	int feet;
	int inch;
public:

	void set(int c, int d) {
		feet = c;
		inch = d;

	}
	void print() {
		cout << "Distance is " << feet << " feet and " << inch << " inches\n";
	}
	friend void add(DM &, DB &, int);
};
void add(DM &a, DB &b,int x) {

	if (x == 1) {
		a.met += b.feet;
		a.cent += b.inch;
	}
	else if (x == 2) {
		b.feet += a.met;
		b.inch += a.cent;
	}
}
void main()
{
	cout << "Enter distance in meter and centimeter\n";
	int met;
	int cen;
	cout << "Meter: ";
	cin >> met;
	cout << "Centimeter : ";
	cin >> cen;
	DM I;
	DB J;
	I.set(met, cen);

	cout << "Enter distance in Feet and Inches\n";
	int fet;
	int inch;
	cout << "Feet: ";
	cin >> fet;
	cout << "Inch : ";
	cin >> inch;
	J.set(fet,inch);
	cout << "Press(1) For addition in Meter and Centimeter\n ";
	cout << "Press(2) For addition in Feet and Inches\n ";
	int x;
	cin >> x;
	add(I, J, x);
	if (x == 1) {
		I.print();
	}
	else if (x == 2) {
		J.print();
	}
}