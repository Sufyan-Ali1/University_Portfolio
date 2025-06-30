#include<iostream>
#include<cmath>
using namespace std;
class vectortype {
	double* x, * y, * z, * len;


public:
	vectortype(double, double, double);
	vectortype();
	vectortype(vectortype&);
	void print() {
		cout << "(" << *x << ", " << *y << ", " << *z << ")" << endl;

	}

	~vectortype();
	void operator=(const vectortype&);

	double length();
	vectortype operator+(vectortype&);
	double operator*(vectortype&);
	vectortype  operator-(vectortype&);
	vectortype  operator++();
	vectortype  operator--();
	vectortype  operator++(int);
	vectortype  operator--(int);
	double angle(const vectortype&);

	friend bool operator==(vectortype&, vectortype&);
	friend bool operator<(vectortype, vectortype);
	friend	bool operator>(vectortype, vectortype);
	friend bool operator!=(vectortype&, vectortype&);
	friend ostream& operator<<(ostream&, vectortype&);
	friend istream& operator>>(istream&, vectortype&);

};
//-------------------------------Insertion and Extraction Operator----------
ostream& operator<<(ostream& ob, vectortype& b) {
	ob << "x= " << *(b.x) << " y= " << *(b.y) << " z= " << *(b.z) << endl;
	return ob;
}
istream& operator>>(istream& ob, vectortype& b) {
	cout << "Enter (x,y,z) co ordinates of vector\n";
	cout << "x= ";
	ob >> *(b.x);
	cout << "y= ";
	ob >> *(b.y);
	cout << "z= ";
	ob>> *(b.z);
	return ob;
}



//------------------------------Equalty and Comparison Operators--------------------------

bool operator==(vectortype& a, vectortype& b) {
	return(*(a.x) == *(b.x) && (*(a.y) == *(b.y)) && (*(a.z) == *(b.z)));
}
bool operator!=(vectortype& a, vectortype& b) {
	return(*(a.x) != *(b.x) || (*(a.y) != *(b.y)) || (*(a.z) != *(b.z)));
}
bool operator>(vectortype a, vectortype b) {

	(*(a.len)) = sqrt(((*(a.x)) * (*(a.x))) + ((*(a.y)) * (*(a.y))) + ((*(a.z)) * (*(a.z))));
	(*(b.len)) = sqrt(((*(b.x)) * (*(b.x))) + ((*(b.y)) * (*(b.y))) + ((*(b.z)) * (*(b.z))));

	return(*(a.len) > *(b.len));
}
bool operator<(vectortype a, vectortype b) {
	(*(a.len)) = sqrt(((*(a.x)) * (*(a.x))) + ((*(a.y)) * (*(a.y))) + ((*(a.z)) * (*(a.z))));
	(*(b.len)) = sqrt(((*(b.x)) * (*(b.x))) + ((*(b.y)) * (*(b.y))) + ((*(b.z)) * (*(b.z))));

	return(*(a.len) < *(b.len));
}
//------------------------------------------------Constructor----------------------------------------------
vectortype::vectortype(double a, double b, double c) {
	x = new double;
	y = new double;
	z = new double;

	len = new double;


	*x = a;
	*y = b;
	*z = c;

	*len = 0;


}
vectortype::vectortype() {
	x = new double;
	y = new double;
	z = new double;

	len = new double;


	*x = 0;
	*y = 0;
	*z = 0;

	*len = 0;


}
vectortype::vectortype(vectortype& a) {
	x = new double;
	y = new double;
	z = new double;
	len = new double;


	*x = *(a.x);
	*y = *(a.y);
	*z = *(a.z);
	*len = *(a.len);
	//cout << "copy constructor called\n";

}
//----------------------------Increment and Decrement Functions------------------------------ 
vectortype vectortype::operator++() {
	++* x;
	++* y;
	++* z;

	return *this;
}

vectortype vectortype::operator--() {
	--* x;
	--* y;
	--* z;
	return *this;
}
vectortype vectortype::operator++(int) {
	vectortype a;

	*(a.x) = *x;
	*(a.y) = *y;
	*(a.z) = *z;
	(*x)++;
	(*y)++;
	(*z)++;

	return a;
}
vectortype vectortype::operator--(int) {
	vectortype a;

	*(a.x) = *x;
	*(a.y) = *y;
	*(a.z) = *z;
	(*x)--;
	(*y)--;
	(*z)--;

	return a;
}
//---------------------------------Addition and Subtraction---------------------------------
vectortype vectortype ::operator-(vectortype& a) {
	vectortype c;
	*(c.x) = *x - *(a.x);
	*(c.y) = *y - *(a.y);
	*(c.z) = *z - *(a.z);

	return c;
}

vectortype vectortype ::operator+(vectortype& a) {
	vectortype c;
	*(c.x) = *x + *(a.x);
	*(c.y) = *y + *(a.y);
	*(c.z) = *z + *(a.z);

	return c;
}
//-------------------------------Dot Product of Two Vectors---------------------------

double vectortype ::operator*(vectortype& a) {
	vectortype c;

	*(c.x) = *x * (*(a.x));
	*(c.y) = *y * (*(a.y));
	*(c.z) = *z * (*(a.z));
	double dot;
	dot = *(c.x) + *(c.y) + *(c.z);
	return dot;
}
//------------------------------------Length of Vector------------------------------------
double vectortype::length() {
	(*len) = sqrt(((*x) * (*x)) + ((*y) * (*y)) + ((*z) * (*z)));
	return *len;
}
//---------------------------Angle between Two Vectors----------------------------------
double vectortype::angle(const vectortype& a) {
	double theta = 0;

	(*len) = sqrt(((*x) * (*x)) + ((*y) * (*y)) + ((*z) * (*z)));
	(*(a.len)) = sqrt(((*(a.x)) * (*(a.x))) + ((*(a.y)) * (*(a.y))) + ((*(a.z)) * (*(a.z))));

	double dot;
	dot = (*x) * (*(a.x)) + (*y) * (*(a.y)) + (*z) * (*(a.z));


	theta = acos(dot / (*len * (*(a.len))));

	return theta;
}
//--------------------------------Assignment Operator----------------------------------
void vectortype::operator=(const vectortype& a) {


	*x = *(a.x);
	*y = *(a.y);
	*z = *(a.z);
	*len = *(a.len);
}
//--------------------

		//-------------------------------------Destructor---------------------------------------
vectortype::~vectortype() {

	delete x;
	x = NULL;
	delete y;
	y = NULL;
	delete z;
	z = NULL;
}
void main() {
	double dot;
	double theta;
	cout << "Enter three coordinates(x,y,z) of first vector\n";
	float a1, b1, c1;
	cout << "x= ";
	cin >> a1;
	cout << "y= ";
	cin >> b1;
	cout << "z= ";
	cin >> c1;
	cout << "Enter three coordinates(x,y,z) of second vector\n";
	float a2, b2, c2;
	cout << "x= ";
	cin >> a2;
	cout << "y= ";
	cin >> b2;
	cout << "z= ";
	cin >> c2;
	vectortype a(a1, b1, c1);
	vectortype b(a2, b2, c2);
	vectortype c;

	c = a;

	cout << "Overloaded Assignment operator called\n\n";
	dot = a * b;
	cout << "Dot product of these two vectors is " << a * b << endl;
	cout << "Length of first vector is: " << a.length() << endl;
	cout << "Length of Second vector is: " << b.length() << endl;
	theta = a.angle(b);
	cout << "Angle between two vectors is :" << theta << endl << endl;
	c = a + b;
	cout << "Addition of two vectors is: (A+B)" << endl;
	c.print();
	c = a - b;
	cout << "Subtraction of two vectors is (A-B): " << endl;
	c.print();
	cout << "First vector Co-ordinates: ";
	a.print();

	c = ++a;
	cout << "After Pre-Increment: ";
	a.print();
	c = a++;
	cout << "After Post-Increment: ";
	c.print();
	c = --a;
	cout << "After Pre-Decrement: ";
	c.print();
	c=a--;
	cout << "After Post-Decrement: ";
	c.print();
	cout << "\nTesting Equal Operator\n";
	if (a == b) {
		cout << "Both vectors are equal\n";
	}
	else {
		cout << "Both vectors are not equal\n";
	}
	cout << "\nTesting Not Equal Operator\n";
	if (a != b) {
		cout << "Both vectors are not equal\n";
	}
	else {
		cout << "Both vectors are equal\n";
	}
	cout << endl;
	cout << "Enter Vector using extraction operator\n";
		cin >> c;
	cout << "Vector output using insertion operator: \n";
	cout << c;
}