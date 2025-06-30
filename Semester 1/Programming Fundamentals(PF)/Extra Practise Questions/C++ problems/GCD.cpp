#include<iostream>
using namespace std;
int main() {
	int a, b,e;
	cout << "Enter two numbers\n";
	cin >> a >> b;
	double c , d ;
	

	if (a > b) {
		e = b;
		c = a % b;
		d = b % b;
		cout << c;
		while (c > 0 || d > 0) {
			--e;
			c = a % e;
			d = b % e;

			
	//	}
	}
	/*else {
	 e = b;
		c = a % b;
		d = b % b;

		while (c > 0 || d > 0) {
			c = a % a;
			d = b % a;
			a--;
		}
	}*/
	cout << "gcd " << e;

	return 0;
}