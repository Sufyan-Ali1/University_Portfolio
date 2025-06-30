#include<iostream>
using namespace std;
void main()
{double W, H, P,f;
cout << "enter hourly wage =";
cin >> W;
cout << "enter number of hours worked =";
cin >> H;
cout << "Enter tax percentage deduction";
cin >> P;
f = (W * H) - (W * H) * (P / 100);
cout << "\nFinal Amount::" << f << "\n";
}