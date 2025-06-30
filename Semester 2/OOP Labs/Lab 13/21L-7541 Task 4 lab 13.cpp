#include<iostream>
using namespace std;
class exceptiontornado {
public:
	exceptiontornado() {
		cout << "Tornado: Take cover immediately!" << endl;
	}
	exceptiontornado(int m) {
		cout << "Tornado: "<<m <<" miles away;and approaching!" << endl;
	}
};
void main(){
	exceptiontornado a;
	exceptiontornado b(10);

}