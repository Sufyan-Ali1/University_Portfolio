#include<iostream>
using namespace std;
class Polynomial
{
private:
	int totalTerms;//Total terms in a Polynomial
	int* coeff;//to save array of coefficients
	int* exp; //to save array of exponents
public:
	Polynomial(int = 0, int cof[] = 0, int ex[] = 0);
	bool operator!();
	bool operator!=(Polynomial);
	friend ostream& operator<<(ostream&,const Polynomial&);
	Polynomial operator+(Polynomial);
	friend Polynomial operator+(int, Polynomial);
	Polynomial operator++();
	Polynomial operator++(int);

};
//constructor
Polynomial::Polynomial(int a, int b[], int c[]) {

	totalTerms = a;
	coeff = new int[totalTerms];
	exp = new int[totalTerms];
	for (int i = 0; i < totalTerms; i++) {
		coeff[i] = b[i];
	}
	for (int i = 0; i < totalTerms; i++) {
		exp[i] = c[i];
	}
}
bool Polynomial::operator!() {
	return((totalTerms == 1) && (*coeff == 0) && (*exp == 0));
}
bool Polynomial:: operator!=(Polynomial a) {
	int count = 0;
	if (totalTerms == a.totalTerms) {
		count = 1;
		for (int i = 0; i < totalTerms && count; i++) {
			if (coeff[i] != a.coeff[i] || exp[i] != a.exp[i]) {
				count = 0;
			}
		}
	}

	return(!count);
}
Polynomial Polynomial::operator+(Polynomial a) {
	Polynomial c;
	c.totalTerms = totalTerms;
	c.coeff = new int[totalTerms];
	c.exp = new int[totalTerms];
	int j;
	for (int i = 0; i < totalTerms; i++) {
		c.exp[i] = exp[i];
		c.coeff[i] = coeff[i];
	}
	int count;
	for (int i = 0; i < a.totalTerms; i++) {
		count = 0;
		for (j = 0; j < totalTerms; j++) {
			if (a.exp[i] == c.exp[j]) {
				c.coeff[j] += a.coeff[i];

				count = 1;
			}
		}
		if (!count) {
			int* q;
			q = new int[c.totalTerms];

			int* t;
			t = new int[c.totalTerms];
			for (int k = 0; k < c.totalTerms; k++)
			{
				q[k] = coeff[k];
				t[k] = exp[k];
			}
			delete[]coeff;
			delete[]exp;
			coeff = new int[c.totalTerms + 1];
			exp = new int[c.totalTerms + 1];
			for (int k = 0; k < c.totalTerms; k++) {
				coeff[k] = q[k];
				exp[k] = t[k];
			}

			c.coeff[totalTerms] = a.coeff[i];
			c.exp[totalTerms] = a.exp[i];
			c.totalTerms++;
		}
	}

	for (int i = 0; i < c.totalTerms - 1; i++) {
		for (int j = i + 1; j < c.totalTerms; j++) {
			if (c.exp[i] < c.exp[j]) {
				swap(c.exp[i], c.exp[j]);
				swap(c.coeff[i], c.coeff[j]);
			}
		}
	}

	return c;
}
Polynomial operator+(int a, Polynomial b) {
	Polynomial c;
	c.totalTerms = b.totalTerms;
	c.coeff = new int[c.totalTerms];
	c.exp = new int[c.totalTerms];
	int j;
	for (int i = 0; i < c.totalTerms; i++) {
		c.exp[i] = b.exp[i];
		c.coeff[i] = b.coeff[i];
	}
	for (int i = 0; i < c.totalTerms; i++) {
		if (c.exp[i] == 0) {
			c.coeff[i] += a;
		}
	}
	return c;
}
ostream& operator<<(ostream& obj,const Polynomial& a) {
	obj << a.coeff[0] << "x^";
	if (a.exp[0] != 0) {
		obj << a.exp[0];
	}
	for (int i = 1; i < a.totalTerms; i++) {
		if (a.coeff[i] >= 0) {
			obj << "+" << a.coeff[i];
			if (a.exp[i] != 0) {
				obj << "x^" << a.exp[i];
			}
		}
		else {
			obj << a.coeff[i];
			if (a.exp[i] != 0) {
				obj << "x^" << a.exp[i];
			}
		}
	}
	return obj;
}
Polynomial Polynomial::operator++() {
	for (int i = 0; i < totalTerms; i++)
	{
		++coeff[i];
	}
	return *this;
}
Polynomial Polynomial::operator++(int) {
	Polynomial temp;
	temp.totalTerms = totalTerms;
	for (int i = 0; i < totalTerms; i++) {
		temp.coeff[i] = coeff[i];
		temp.exp[i] = exp[i];
		coeff[i]++;
	}
	return temp;
}
void main()
{
	int coeff_P1[] = { 1,2,5 }; //Coefficients for Polynomial P1
	int exp_P1[] = { 4,2,0 }; //Exponents for Polynomial P1
	int coeff_P2[] = { 4,3 }; //Coefficients for Polynomial P2
	int exp_P2[] = { 6,2 }; //Exponents for Polynomial P2

	Polynomial P1(3, coeff_P1, exp_P1);//Creates P1 with 3 terms (P1 = 1x^4 + 2x^2 + 5x^0 )
	Polynomial P2(2, coeff_P2, exp_P2);//Creates P2 with 2 terms (P2 = 4x^6 + 3x^2)
	cout << "P1 = " << P1 << endl; //Prints P1 = x^4+2x^2+5
	cout << "P2 = " << P2 << endl; //Prints P2 = 4x^6+3x^2
	if (!P1)
		cout << "P1 is zero" << endl;/*if polynomial has only 1 term and its coeff and exp are zero. i.e. if p1 = 0.*/
	if (P1 != P2)
		cout << "P1 is Not Equal to P2" << endl;
	cout << ++P1 << endl;//adds 1 in all the coefficient.
	cout << P1 << endl;
	cout << P1++ << endl; //adds 1 in all the coefficient.
	cout << P1 << endl;
	Polynomial P3 = P1 + P2;
	cout << "P3 = " << P3 << endl;
	P3 = 2 + P1; //Assume P1 already has a constant term, add 2 in it.
	cout << "P3 = " << P3 << endl;
}

