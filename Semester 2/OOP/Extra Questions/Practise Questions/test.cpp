#include<iostream>
using namespace std;
class stud {
	int a;
	int b;
public:
	stud(int = 0, int =0);
	int  add(int a,int b);
	int &sub(int,int);
	int &mul(int,int);
	void print();
};
stud::stud(int a , int b) {
	this->a = a;
	this->b = b;
		cout << "A is " << this->a << endl;
	cout << "B is " << this->b << endl;
}
int stud::add(int a,int b) {
	this->a = this->a + a;
	this->b = this->b + b;
	cout << "A is " << this->a << endl;
	cout << "B is " << this->b << endl;

	return this->a;
}
int &stud::sub(int a, int b) {
	this->a = this->a - a;
	this->b = this->b - b;
	cout << "A is " << this->a << endl;
	cout << "B is " << this->b << endl;
	return this->a;
}
int &stud::mul(int a, int b) {
	this->a = this->a * a;
	this->b = this->b * b;
	//this->add(2, 3);
	cout << "A is " <<this->a << endl;
	cout << "B is " << this->b << endl;
	return this->a;
}
void stud::print() {
	cout << "A is " << a << endl;
		cout << "B is " << b << endl;

}
void main() {
	stud obj;

    int a=obj.add(5, 6);//.sub(1, 2).mul(3, 8);
	++a;
	obj.print();
}