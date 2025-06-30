//Name:- Sufyan Ali 
// ID:- l217541@lhr.nu.edu.pk
//Roll No:- 21L-7541

#include<iostream>
#include<time.h>
#include<string>
using namespace std;
float currentbalance = 25000;
int d = 0;//d for check user do any transaction or not

//Function for display menu
int menu() {
	int opt; //opt for select which option user want to perform
	cout << "\n1.Account Info\n";
	cout << "2.Balance\n";
	cout << "3.Deposit\n";
	cout << "4.Withdraw\n";
	cout << "5.Exit\n\n";
	cout << "Select option from above\n";
	cin >> opt;
	return opt;
}
//Function for display account info
int accountinfo(string nam, string acc, int no) {
	cout << nam << endl;
	cout << "Your ID " << no << endl;
	cout << "Your Balance " << currentbalance << endl;
	cout << "Your Account type: " << acc << endl;
	return 0;
}
//function for check balance
int balance() {
	cout << "Your Balance " << currentbalance << endl;
	if (currentbalance < 1000) {
		cout << "Low Balance\n";
	}
	cout << "For go back to menu press Enter\n";
	cin.get();
	return 0;
}
//function for deposit money
int deposit() {
	int amount, count = 1;
	cout << "Enter amount \n";
	cin >> amount;
	while (amount < 0 && count <= 1) {
		cout << "Invalid Amount! \n Try Again\n";
		cin >> amount;
		count++;
	}
	if (amount >= 0) {
		d = 1;
		currentbalance = currentbalance + amount;
		cout << "Your amount deposited\n";
	}
	return 0;
}
//Function for withdraw money
int withdraw() {
	int amount, count = 1;
	float tax;

	cout << "Enter Amount multiple of 500\n";
	cin >> amount;
	while ((amount % 500 != 0 || amount > currentbalance) && count <= 1) {
		if (amount % 500 != 0) {
			cout << "Invalid Amount\n";
		}

		if (amount > currentbalance) {
			cout << "You have insufficent amount\n";
		}
		cout << "Try Again\n";
		cin >> amount;
		count++;
	}
	if (amount % 500 == 0 || amount < currentbalance) {
		d = 1;
		if (amount >= 4000 && amount < 6000) {
			tax = (currentbalance * 5.3) / 100;
			currentbalance = currentbalance - amount - tax;
		}
		else if (amount >= 6000 && amount < 10000) {
			tax = (currentbalance * 6.8) / 100;
			currentbalance = currentbalance - amount - tax;
		}
		else if (amount >= 10000) {
			tax = (currentbalance * 8.4) / 100;
			currentbalance = currentbalance - amount - tax;
		}
		else {
			currentbalance = currentbalance - amount;
		}
	}
	cout << "Collect Your Cash\n";
	return 0;
}

void main() {
	bool istrue = false, A = false;
	string a;
	string account = "Saving";
	int id, work;
	while (!istrue) {//If once program is compile and execute This loop will not be terminate because will not be quit 
		cout << "Enter your name ";//user come and login his accout and can logout his account but cannot qiut ATM..
		cin >> a;
		srand(time(0));
		id = rand();//for generate randon number for id
		while (!A) {//This loop will terminate when user exit his/her account...
			work = menu();

			if (work == 1) {
				accountinfo(a, account, id);
			}
			else if (work == 2) {
				balance();
			}
			else if (work == 3) {
				deposit();
			}
			else if (work == 4) {
				withdraw();
			}
			else if (work == 5) {
				break;
			}
		}
		cout << "Thank You for using FAST Banking\n";
		if (d == 1) {
			cout << "Tumhara Grade Paka Hai\n";

		}
		else if (d == 0) {
			cout << "Kanjoos Insan\n";
		}
	}
}