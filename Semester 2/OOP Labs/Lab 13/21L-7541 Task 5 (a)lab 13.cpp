#include<iostream>
using namespace std;
class Animal {
public:
	virtual string speak(){
		
		return "Speak Called()";
	}
};
class Dog :public Animal {
public:
	string speak() {
		
		return"Woof:";
	}
};
void main() {
	Animal objAnimal;
	Dog objDog;
	Animal* ptrAnimal = &objAnimal;
	Dog* ptrDog = &objDog;
	cout << objAnimal.speak() << endl;
	cout << objDog.speak() << endl;
	cout << ptrAnimal->speak() << endl;
	cout << ptrDog->speak() << endl;
}