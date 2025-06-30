#include<iostream>
using namespace std;
void main() {
	int i = 1,factorial,n;
	factorial = 1;
	cout << "enter a number\n";
	cin >> n;
	while(i<=n){
		factorial = factorial * i;
		i++;
		
}
	cout << factorial;

}



