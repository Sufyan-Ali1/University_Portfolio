#include<iostream>
using namespace std;
void main() {
	cout << "Enter the borrow amount\n";
	float loan, interestrate, monthlypayment, monthlyinterest, count = 0, firstmonthinterest;
	cin >> loan;
	cout << "Enter the interest rate\n";
	cin >> interestrate;
	cout << "Enter the monthly payment\n";
	cin >> monthlypayment;
	monthlyinterest = interestrate / 12;
	firstmonthinterest = (monthlyinterest/100) * loan;
	while (loan > 0) {

		if (firstmonthinterest > monthlypayment) {
			cout << "Monthly payment is too low,with this monthly payment ,the loan could not be repaid\n";
			break;
		}
		else {
			loan = loan + loan * (monthlyinterest/100) - monthlypayment;

		}
		count++;
	}
	cout << "In " << count << " months the loan will repay" << endl;
}