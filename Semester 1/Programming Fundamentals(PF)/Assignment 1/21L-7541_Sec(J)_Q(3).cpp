/*Assignment
Name :Sufyan Ali
Roll No 21L-7541*/
#include<iostream>
using namespace std;
void main() {
	int Y, M, D1 ,D2, R ;
	/* Here Y is Years M is Month D1 is the days that user will input and 
	D2 is days that will remaining in calculation of year and month and we use R for ease  */
	cout << "Please enter number of days ";
	cin >> D1;
	Y = D1 / 365;
	R = D1 % 365;
	M = R / 30;
	D2 = R % 30;
	cout << Y << " YEARS  " << M<<" MONTHS " << D2<<" DAYS " <<endl ;

}