#include<iostream>
using namespace std;
void main() {
	cout << "Enter the population of town A and growth rate of town" << endl;
	float popA, popB, GR_A, GR_B;
	int i = 0;
	cin >> popA >> GR_A;
	cout << "Enter the population of town B and growth rate of town" << endl;
	cin >> popB >> GR_B;
	bool istrue = false;
	
   while (popA<popB) {
		popA = (popA + (popA * (GR_A / 100)));
		popB = popB + popB * (GR_B / 100);
		
		i++;
	}
	cout << popB << endl;
	cout << "After " << i << " years the population of town A is greater than or equal to town B\n";
	cout << "And that time population of B is "<<popB<< " and population of A is " << popA<< endl;
}