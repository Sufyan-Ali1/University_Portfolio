#include<iostream>
using namespace std;
void main() {
	cout << "Select a option which you want to calculate" << endl;
	cout << "1.Area of Circle " << endl << "2.Area of Reactangle " << endl << "3.Area of Triangle " << endl << "4.Quit" << endl;
	int a;
	cout << "Enter a number from above 4" << endl ;
	cin >> a;
	if (a == 1) {
		cout << "1.Area of Circle" << endl;
		double R,Area;
		cout << "Enter the Radius of Circle =";
		cin >> R;
		Area = 3.14*(R)*(R);
		cout << "Area =" << Area << endl;
	}
	else if(a==2){
		cout << "2.Area of Rectangle " << endl;
		double l, w,A;
		cout << "Enter the length of Rectangle " << endl;
		cin >> l;
		cout << "Enter the width of Rectangle " << endl;
		cin >> w;
		A = l * w;
		cout << "Area =" << A << endl;

	}
	else if (a == 3) {
		cout << "3.Area of Triangle" << endl;
		double b, h,a;
		cout << "Enter the base of Triangle "<<endl;
		cin >> b;
		cout << "Enter the height of Triangle "<<endl;
		cin >> h;
		a = 0.5 * b * h;
		cout << "area =" << a << endl;

	}
	else if (a==4){
	

	}

}
