#include<iostream>
using namespace std;
class test {
	int len;
	int wid;
	int brd;
public:
	test(int = 0, int = 0, int = 0);
	test operator++();
	void operator--();
	void operator-();
	void print();

};
test test::operator++() {
	len++;
	wid++;
	brd++;
	return *this;
}
void test::operator--() {
	len -= 2;
	wid -= 2;
	brd -= 2;
}
void test::operator-() {
	len = -len;
	wid = -wid;
	brd = -brd;
}
void test::print() {
	cout << "Length = " << len;
	cout << "\nWidth = " << wid;
	cout << "\nBreadth = " << brd << endl;
}
test::test(int a,int b,int c) {
	len = a;
	wid = b;
	brd = c;
}
void main() {
	cout << "Enter 3 number: " << endl;
	cout << "1st: ";
	int a, b, c;
	cin >> a;
	cout << "2nd: ";
	cin >> b;
	cout << "3rd: ";
	cin >> c;
	test ob1(a, b, c);
	test ob2;

	ob1.print();
	--ob1;
	ob1.print();
	ob2=++ ++ ++ob1;
	ob1.print();
	-ob1;
	cout << "Object 2\n";
	ob2.print();

}