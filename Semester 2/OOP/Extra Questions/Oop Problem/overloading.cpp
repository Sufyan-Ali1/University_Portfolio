#include<iostream>
using namespace std;
class complexnum {
	int real;
	int img;
public:
	complexnum(int = 0, int = 0);
	complexnum  operator+(complexnum);
	complexnum  operator*(complexnum&);
	complexnum  operator/(complexnum&);
	complexnum  operator-(complexnum&);
//	~complexnum();
	complexnum  operator++();
	complexnum  operator--();
	bool operator==(const complexnum&)const;
	complexnum  operator++(int);
	complexnum  operator--(int);
	void operator=(complexnum&);
	void print();

};
//complexnum::~complexnum() {
//	cout << "Destructor\n";
//}
complexnum::complexnum(int a, int b) {
	real = a;
	img = b;
}

complexnum complexnum ::operator-(complexnum& x) {
	complexnum c;
	c.real = real - x.real;
	c.img = img - x.img;
	cout << "Subtraction Function\n";
	return c;
}

complexnum complexnum ::operator*(complexnum& x) {
	complexnum c;
	c.real = real * x.real;
	c.img = img * x.img;
	cout << "Multiplication Function\n";
	return c;
}
void complexnum::print() {
	if (img >= 0) {
		cout << real << " + " << img << "i" << endl;
	}
	else {
		cout << real << img << "i" << endl;
	}
}
bool complexnum::operator==(const complexnum& x)const {
	cout << "Equality check Function\n";
	return(real == x.real && img == x.img);
}
complexnum complexnum::operator++() {
	++real;
	++img;
	cout << "Pre increment Function\n";
	return *this;
}
complexnum complexnum::operator--() {
	--real;
	--img;
	cout << "Pre Decrement Function\n";
	return *this;
}
complexnum complexnum::operator++(int) {
	complexnum x;
	x.real = real;
	x.img = img;
	real++;
	img++;
	cout << "Post increment Function\n";
	return x;
}
complexnum complexnum::operator--(int) {
	complexnum x;
	x.real = real;
	x.img = img;
	real--;
	img--;
	cout << "Post Decrement Function\n";
	return x;
}
void complexnum::operator=(complexnum& x) {
	real = x.real;
	img = x.img;
	cout << "Equal Function\n";
}
complexnum complexnum ::operator+(complexnum x) {
	complexnum c;
	c.real = real + x.real;
	c.img = img + x.img;
	cout << "Addition Function\n";
	return c;
}
void main() {
	complexnum a(3, 5);
	complexnum b(3, 5);
	complexnum c ;
	complexnum d = a + b;
	c = a+b;

	c.print();
	//complexnum d = a - b;
	//d.print();
	//complexnum e = a * b;
	////e = a * b;
	//e.print();
	////e.~complexnum();
	//bool x = (a == b);
	//cout << x << endl;
	//complexnum f;
	//c.print();

	//c.print();
	//c.print();
	//
}