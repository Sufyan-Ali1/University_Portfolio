#include<iostream>
using namespace std;
class vision{
	float length, width;
	float area;
	float priece;
public:
	void setwidth();
	void setlength();
	void areaa();
	void price();
	vision();
	vision(int a, int b){
		length = a;
		width = b;
	}
	vision(float a, float b){
		length = a;
		width = b;
	}
	void display();
	
};
vision::vision(){
	setlength();
	setwidth();
}
void vision::setlength(){
	length = 40;
}
void vision::setwidth(){
	width = 55;
}
void vision::areaa(){
	area=length*width;
}
void vision::price(){
	priece = area * 65;
}
void vision::display(){
	cout << "Price of your Television is " << priece << endl;
	cout << "Dimesions of your television is " << length << " length " << width << " width \n";
	cout << "Area of your Television is " << area << endl<<"\n\n";
}
void main(){
	int w, l;
	float w1, l1;
	cout << "Enter the length and widht in integers respectively\n";
	cin >> l;
	cin >> w;
	cout << "Enter the length and widht in float respectively\n";
	cin >> l1;
	cin >> w1;
	vision c;
	vision c1(l, w);
	vision c2(l1, w1);
	c.areaa();
	c1.areaa();
	c2.areaa();
	c.price();
	c1.price();
	c2.price();
	c.display();
	c1.display();
	c2.display();
	system("pause");
}