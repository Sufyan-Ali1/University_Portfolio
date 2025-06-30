/*Assignment
Name :Sufyan Ali
Roll No :21L-7541*/
#include<iostream>
using namespace std;
void main() {
	int I1, I2, Y, F;
	/*Here I1 is for inches that is given by user and I2 is also for inches that
	remaining in calculation of yard and feet Y for yards and F for feet*/
	cout << "Please enter number of inches ";
	cin >> I1;
	Y = I1 / 36;
	F = (I1 % 36) / 12;
	I2 = (I1 % 36) % 12;
	cout << Y << " Yards " << F << " FEET "<<I2<< " INCHES";
}