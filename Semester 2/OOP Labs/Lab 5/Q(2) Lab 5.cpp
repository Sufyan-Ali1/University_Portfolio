#include<iostream>
using namespace std;
class Rectangle {
	int length;
	int width;
public:
	Rectangle() {
		length = 0;
		width = 0;
	}
	Rectangle(int a) {
		length = a;
		width = a;
	}
	Rectangle(int a,int b) {
		length = a;
		width = b;
	}
	void area() {
		int areaa;
		areaa = length * width;
		cout << "Area is " << areaa << endl;
	}
};
void main() {
	Rectangle a;
	Rectangle b(3,4);
	Rectangle c(3);
	a.area();
	b.area();
	c.area();
}
