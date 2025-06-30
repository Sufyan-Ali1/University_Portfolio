#include<iostream>
using namespace std;
void main() {
	cout << "Enter number of items that you want to buy \n";
	int item, i = 1, billingamount = 0, itemprice, totalamount;
	cin >> item;
	while (item >= i) {
		cout << "Enter the price of item " << i << endl;
		cin >> itemprice;
		billingamount = itemprice + billingamount;
		i++;
	}
	if (billingamount >= 200) {
		totalamount = item * 10 + billingamount;
	}
	else {
		totalamount = billingamount;
	}
	cout << "Total bill is " << totalamount << endl;
}