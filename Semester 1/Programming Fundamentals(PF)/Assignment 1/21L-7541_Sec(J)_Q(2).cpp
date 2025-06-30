/*Assignment
Name : Sufyan Ali
Roll No =:21L-7541*/
#include<iostream>
using namespace std;
void main() {
	double W, H, T, N;
	cout << "Please enter hourly wage = ";
	cin >> W;
	cout << "Please enter number of hours worked = ";
	cin >> H;
	cout << "Please enter tax(percentage deduction) = ";
	cin >> T;
	N = (W * H) - (W * H) * (T / 100);
	cout << "Net pay = " << N<< endl;
}