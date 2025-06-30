
#include<iostream>
using namespace std;
int main() {
	int d, m, y,r,a,b,M.D,n;
	cout << "Enter date,month,year\n";
	cout << "Date ";
	cin >> d;
	cout << "Month ";
	cin >> m;
	cout << "Year ";
	cin >> y;
	r = y % 1899;
	
	n = 1;
	M.D = 0;
	while (n < m) {
	
		if (n == 1) {
			M.D = M.D + 31;
		}
        else if (n == 2) {
			M.D = M.D + 29;
		}
		else if (n == 3) {
			M.D = M.D + 31;
		}
		else if (n == 4) {
			M.D = M.D + 30;
		}
		else if (n == 5) {
			M.D = M.D + 31;
		}

		else if (n == 6) {
			M.D = M.D + 30;
		}
		else if (n == 7) {
			M.D = M.D + 31;
		}
		else if (n == 8) {
			M.D = M.D + 31;
		}

		else if (n == 9) {
			M.D = M.D + 30;
		}
		else if (n == 10) {
			M.D = M.D + 31;
		}
		else if (n == 11) {
			M.D = M.D + 30;
		}
		n++;
	}
	a = 365 * r + d + M.D;
		if (r > 0 && r<601) {
			b = a % 7;
			if (b == 0) {
				cout << "SUNDAY";
			}
			else if (b == 1) {
				cout << "MONDAY";
			}
			else if (b == 2) {
				cout << "TUESDAY";
			}
			else if (b == 3) {
				cout << "WEDNESDAY";
			}
			else if (b == 4) {
				cout << "THURSDAY";
			}
			else if (b == 5) {
				cout << "FRIDAY";
			}
			else if (b == 6) {
				cout << "SATURDAY";
			}
			
		}
		else {
			cout << "Incorrect Date";
		}

}