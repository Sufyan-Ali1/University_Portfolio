#include<iostream>
using namespace std;
class ComplexNumber
{
private:
	int real;
	int imaginary;
public:
	ComplexNumber(int, int); //with default arguments
	~ComplexNumber(); //Does Nothing.
	void Input();
	void Output();
	bool IsEqual(ComplexNumber);
	ComplexNumber Conjugate();
	ComplexNumber Add(ComplexNumber);
	ComplexNumber Subtract(ComplexNumber);
	ComplexNumber Multiplication(ComplexNumber);
	float Magnitude();
};
ComplexNumber::ComplexNumber(int a=0,int b=0) {
	real = a;
	imaginary = b;
}
ComplexNumber::~ComplexNumber() {

}
void ComplexNumber::Input() {
	cout << "Enter Real: ";
	cin >> real;
	cout << "Enter Imaginary: ";
	cin >> imaginary;
}

void ComplexNumber::Output() {
	if(imaginary>0)
	cout << real << "+" << imaginary << "i" << endl << endl;
	else
		cout << real <<  imaginary << "i" << endl << endl;

	
}

bool ComplexNumber::IsEqual(ComplexNumber a) {
	return (real == a.real && imaginary == a.imaginary);
}

float ComplexNumber::Magnitude() {
	float a;
	a = sqrt((real * real) + (imaginary * imaginary));
	return a;
}

ComplexNumber ComplexNumber::Conjugate() {
	int a;
	if (imaginary > 0) {
		a = -imaginary;
		cout << real << a <<"i" << endl << endl;

	}
	else if (imaginary == 0) {
		cout << real << endl << endl;

	}
	else {
	    a = -imaginary;
		cout << real <<"+" << a << "i" << endl << endl;
	}
	return 0;
}

ComplexNumber ComplexNumber::Add(ComplexNumber a) {
	int c;
	c = imaginary + a.imaginary;
	if (c > 0) {
		cout << real + a.real << "+" << c << "i"<<endl<<endl;
	}
	else if(c==0){
		cout << real + a.real <<"+" << c << "i" << endl << endl;
	}
	else {
		cout << real + a.real  << c << "i" << endl << endl;
	}
	return 0;
}

ComplexNumber ComplexNumber::Subtract(ComplexNumber a) {
	int c;
	c = imaginary - a.imaginary;
	if (c > 0) {
		cout << real - a.real << "+" << c << "i" << endl << endl;
	}
	else if (c == 0) {
		cout << real + a.real << "+" << c << "i" << endl << endl;
	}
	else {
		cout << real - a.real << c << "i" << endl << endl;
	}
	return 0;
}
ComplexNumber ComplexNumber::Multiplication(ComplexNumber a) {
	int x;
	x = (real * a.real) - (imaginary * a.imaginary);
	int y;
	y=  (real * a.imaginary) + (a.real * imaginary);
	if (y > 0) {
		cout << x << " + " << y << "i" << endl << endl;
	}
	else if(y==0){
		cout << x << " + "<<y<<"i" << endl << endl;
	}
	else{
		cout << x << y << "i" << endl << endl;
	}
	return 0;
}


void main() {
	ComplexNumber c1;
	ComplexNumber c2;
	float magnit=0;
	bool a;

	cout << "Enter c1\n";
	c1.Input();
	cout << "\n\nEnter c2\n";
	c2.Input();
	cout << "\n";
	cout << "c1 = ";
	c1.Output();
	cout << "c2 = ";
	c2.Output();
	
	a = c1.IsEqual(c2);
	if (a) {
		cout << "c1 is equal to c2\n\n";
	}
	else {
		cout << "c1 is not equal to c2\n\n";
	}

	
	cout << "Conjugate of c1:  ";
	c1.Conjugate();
	cout << "Conjugate of c2:  ";
	c2.Conjugate();
	cout << "c1 + c2 :   ";
	c1.Add(c2);
	cout << "c1 - c2 :   ";
	c1.Subtract(c2);
	cout << "c1 x c2 :   ";
	c1.Multiplication(c2);
	magnit = c1.Magnitude();
	cout << "Magnitude of c1: " << magnit << endl << endl;
	magnit = c2.Magnitude();
	cout << "Magnitude of c2: " << magnit << endl << endl;
}