#include<iostream>
#include<string>
using namespace std;
class lecream{
	int wafer;
	
	string flavor;
	int Nscop;//no of scoop
	int price;
	int scoop;
	
public:
	void priece(int,int,int);

	lecream();
		void print();
		~lecream();

	
};
lecream::lecream(){
	wafer = 0;
	scoop = 50;
	Nscop = 0;
	price = 0;
	flavor = "\0";
}
lecream::~lecream(){
	cout << "Thank You\n";
	system("pause");
}
void lecream::priece(int x,int n,int a){
	if (x == 1){
		flavor = "Chocolate";
	}
	if (x == 2){
		flavor = "Vanilla";
	}
	if (x == 3){
		flavor = "Strawberry";
	}
	if (x == 4){
		flavor = "Mango";
	}
	if (x == 5){
		flavor = "Tutti Fruiti";
	}
	if (x == 6){
		flavor = "Almond Crunch";
	}
	if (x == 7){
		flavor = "Coffee";
	}
	Nscop = n;
	wafer = a;
	if (x == 1){
		price = Nscop*(scoop + 10);
	}
	else{
		price = Nscop*scoop;
	}
	if (wafer){
		price = price + 10;
	}
}
void lecream:: print(){
	cout << "Your Total Price is " << price << endl;
	cout << "Your flavor is " << flavor << endl;
	cout << "Total number of scoops " << Nscop<<endl;
	cout << " Number of wafers " << wafer << endl;
}
int main(){
	cout << "\t\t\tMENU of Ice Cream Shop\n";
	cout << "Press (1) For Chocolate icecream\nPress (2) For Vanilla icecream\nPress (3) For Strawberry icecream\nPress (4) For Mango icecream\nPress (5) For Tutti Fruiti icecream\n";
	cout<< "Press (6) For Almond Crunch icecream\nPress (7) For Coffee icecream\n\n";
	cout << "1 Scoop of chocloate icecream :Rs 60\n1 Scoop of others icecream :Rs 50\n\n";
	cout << "Select from the above: ";
	int n;
	cin >> n;
	cout << "Enter No of scoops(1-3)\n";
	
	int x;
	cin >> x;
	if (x < 0 && x > 3){
		cout << "Invalid Input\n";
		return 0;
	}
	
	cout << "If you want to take wafer with icecream (Enter 1 else 0 )Wafer Rs 10\n";
	int a;
	cin >> a;
	lecream c;


	c.priece(n,x,a);
	c.print();
	//system("pause");
	return 0;
}