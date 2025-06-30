#include<iostream>
using namespace std;
class B;
class A {
	int x;
public:
	A(int = 0);
	void setx(int);
	void disp();
};
class B :public A
{
	int y;
public:

	B(int = 0, int = 0);
	void sety(int);
	void disp();
};
A::A(int a) {
	x = a;
	cout << "Constructor of A\n";
}
B::B(int a, int b) :A{ a } {

	y = b;
	cout << "Constructor of B\n";
}
void A::setx(int a) {
	x = a;
}
void A::disp() {
	cout << "x= " << x << endl;
}
void B::sety(int a) {
	y = a;
}
void B::disp() {
	cout << "y= " << y << endl; 
}
int main() {
	
	//A* d;
	B e(3,4);
	A * a;
	a = &e;
	//d = &e;
	//b = &c; invalid
	
	((B*)a)->disp();
	a->disp();
}