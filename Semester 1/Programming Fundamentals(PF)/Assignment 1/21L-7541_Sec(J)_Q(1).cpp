/*Assignment
  Name :sufyan Ali
  Roll No:21L-7541*/

#include<iostream>
#include <cmath>

using namespace std;
int main()
{
	double i, p, u,y ;
	u = 1.234;
		p = 3.334;
		cout << "Equation = (sqrt(u*(sqrt(i*i*i)*((i*i)-1))))/(sqrt((p*i)-2)+(sqrt((p*i)-1) "<<endl;
		cout <<"u= " <<u << endl <<"p = "<< p << endl;
		cout << "enter the value of i" << endl;
		cin >> i;
		y = sqrt(u * (sqrt(i * i * i) * ((i * i) - 1))) / (sqrt((p * i) - 2) + (sqrt((p * i) - 1)));
		cout << "The value of above equation is =" << y << endl;
}