#include <iostream>
using namespace std;
int main()
{
	int x, quotient = 0, remainder, sum, number;
	cout << "Input a number ";
	cin >> x;
	number = x;
	remainder = x;
	sum = 0;
	while (x > 0)
	{
		
		remainder = x % 10;
		quotient = x / 10;
		x = quotient;
		sum = sum + remainder * remainder * remainder;
	}
	
	if (sum == number)
		cout << "I have found an amazing Armstrong number";
	else
		cout << "This is not my amazing Armstrong number";
	return 0;
}
