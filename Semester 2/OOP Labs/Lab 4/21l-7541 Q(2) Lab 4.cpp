#include<iostream>
#include<string>

using namespace std;
void inpt(string &nme, string &roll, string &id, string &dgre, string &adres){
	cout << "Enter your name: ";
	getline(cin,nme);
	cout << "Enter your Roll No: ";
	getline(cin, roll);
	cout << "Enter your cnic: ";
	getline(cin, id);
	cout << "Enter your degree: ";
	getline(cin, dgre);
	cout << "Enter your address: ";
	getline(cin, adres);

}
class student{
private:
    string name;
	string degree;
	string rollno;
	string cnic;
	string address;

public:
	void set(string nme, string roll, string id, string dgre, string adres){
		name = nme;
		rollno = roll;
		cnic = id;
		degree = dgre;
		address = adres;
	}
	void print(){
		
		cout << name << endl << rollno << endl << cnic << endl << degree << endl << address << endl;
	}
};
void main(){
	string name;
	string degree;
	string rollno;
	string cnic;
	string address;
	
	
	inpt(name,rollno,cnic,degree,address);
	
	student s1;
	s1.set(name, rollno, cnic, degree, address);
	s1.print();
	system("pause");
}