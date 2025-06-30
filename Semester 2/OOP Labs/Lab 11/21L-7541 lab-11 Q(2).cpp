#include<iostream>
using namespace std;
class BankAccount{
	int accid;
	float bal;
	
public:
	BankAccount(int = 0,int=0);

public:
	void Balanceinq();
	int getid();
	float getbal();
	void setbal(int a){
		bal = a;
	}

};
BankAccount::BankAccount(int a,int b){
	accid = a;
	bal = b;
}
float BankAccount::getbal(){
	return bal;
}
int BankAccount::getid(){
	return accid;
}

class currentacc :public BankAccount
{
public:
	currentacc(int=0,int=0);
	int amountwithdraw();
	void amountdep();
};
class savingsacc :public BankAccount
{
public:
	savingsacc(int = 0, int = 0);
	int amountwithdraw();
	void amountdep();
};

int currentacc:: amountwithdraw(){
	cout << "Enter amount to withdraw\n";
	int x;
	cin >> x;
	int ttl = getbal()-x;
	while (ttl < 5000){
		cout << "Your Amount is low please enter again\n";
		cin >> x;
		break;
	}
	ttl = getbal() - x;
	if (ttl < 5000){
		cout << "Invalid Amount\n";
	}
	else{
		setbal(ttl);
		cout << "collect your cash\n";
		
	}
	return 0;
}

int savingsacc::amountwithdraw(){
	cout << "Enter amount to withdraw\n";
	int x;
	cin >> x;
	int ttl = getbal() - x;
	while (ttl < 10000){
		cout << "Your Amount is low please enter again\n";
		cin >> x;
		break;
	}
	ttl = getbal() - x;
	if (ttl < 10000){
		cout << "Invalid Amount\n";
	}
	else{
		setbal(ttl);
		cout << "collect your cash\n";

	}
	return 0;
}
void savingsacc::amountdep(){
	cout << "Enter amount to deposit\n";
	int x;
	cin >> x;
	int a = getbal();
	a = a + x;
	setbal(a);
	cout << "Amount depoisted\n";
}

void currentacc::amountdep(){
	cout << "Enter amount to deposit\n";
	int x;
	cin >> x;
	int a = getbal();
	a = a + x;
	setbal(a);
	cout << "Amount depoisted\n";
}
currentacc::currentacc(int a,int b) :BankAccount{a,b}
{

}
savingsacc::savingsacc(int a,int b) : BankAccount{ a,b }
{

}
void main(){
	cout << "------------------------------------Welcome to Bank---------------------------------------------\n";
	cout << "Press(1) for saving account\nPress(2) for current account\npress anything else for close\n ";
	int x;
	cin >> x;
	if (x == 1){
		cout << "------------------------------Saving Account-------------------\n";
		cout << "Enter id of account\n";
		int a;
		cin >> a;
		cout << "Enter balance of account\n";
		int b;
		cin >> b;
		savingsacc ob(a, b);
		cout << "Press(1) for deposit amount\nPress(2) for withdraw amount \npress anything else for close\n ";
		int y;
		cin >> y;
		if (y == 1){
			ob.amountdep();
		}
		else if(y==2){
			ob.amountwithdraw();
		}
		
	}
	else if (x == 2){
		cout << "------------------------------Current Account-------------------\n";
		cout << "Enter id of account\n";
		int a;
		cin >> a;
		cout << "Enter balance of account\n";
		int b;
		cin >> b;
		currentacc ob1(a, b);
		cout << "Press(1) for deposit amount\nPress(2) for withdraw amount \npress anything else for close\n ";
		int y;
		cin >> y;
		if (y == 1){
			ob1.amountdep();
		}
		else if (y == 2){
			ob1.amountwithdraw();
		}
	}
	system("pause");
}