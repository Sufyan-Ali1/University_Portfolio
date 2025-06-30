#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>
using namespace std;
class Animal{
public:
	virtual string speak(){
		return " speak() called.";
	}
	~Animal() 	{ cout << "~Animal() called." << endl; }
};
class Dog :public Animal
{
public:
	string speak(){
		return " Woof";
	}
	~Dog() 	{ cout << "~Dog() called." << endl; }

};
class Cat :public Animal
{
public:
	string speak(){
		return " Mew!";
	}
	
	~Cat() 	{ cout << "~Cat() called." << endl; }

};
int  main(){
	const int size = 5;
	Animal * myPets[size];
	Cat whiskers;
	Dog mutley;

	//myPets[0] = &whiskers;
//	myPets[1] = &mutley;

	//for (int i = 0; i<size; i++)
	//	cout << myPets[i]->speak() << endl;



	int i = 0;
	while (i<size)
	{
		cout << "Press 1 for a Dog and 2 for a Cat." << endl;
		switch (_getch())
		{
		case '1':
			myPets[i] = new Dog;
			cout << "Dog added at position " << i << endl << endl;
			myPets[i]->~Animal();
			i++;
			break;
		case '2':
			myPets[i] = new Cat;
			cout << "Cat added at position " << i << endl << endl;
			myPets[i]->~Animal();
			i++;
			break;
		default:
			cout << "Invalid input. Enter again." << endl << endl;
			break;
		}
	}
	//whiskers.~Cat();
	//mutley.~Dog();

	system("pause");
	return 0;
}