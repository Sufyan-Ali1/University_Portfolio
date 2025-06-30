#include<iostream>
using namespace std;
class romantype {
	string roman;

	int M;
	int D;
	int C;
	int L;
	int X;
	int V;
	int I;
	int dec;
public:
	romantype(string = "");
	int convert();
	string cnvrt(int);
	string operator+(romantype&);
	string operator-(romantype&);
	string operator*(romantype&);
	string operator/(romantype&);
	bool operator==(romantype);
	bool operator!=(romantype);
	bool operator<(romantype);
	bool operator>(romantype);
	string operator++();
	string operator--();
	string operator++(int);
	string operator--(int);

};
//-----------Constructor
romantype::romantype(string a) {
	M = 1000;
	D = 500;
	C = 100;
	L = 50;
	X = 10;
	V = 5;
	I = 1;
	roman = a;
	dec = convert();

	while (!dec) {
		cout << "Roman Numeral is Incorrect Please Enter again\n";
		cin >> roman;
		dec = convert();
	}
}

string romantype::operator+(romantype& z) {

	int sum = dec + z.dec;
	if (sum > 3999) {
		cout << "sum is out of range of roman numeral(1-3999)\n";
		return "\0";
	}
	else {
		return cnvrt(sum);
	}
}

string romantype::operator-(romantype& z) {
	int dif = dec - z.dec;

	if (dif > 3999) {
		cout << "subtraction is out of range of roman numeral(1-3999)\n";
		return "\0";
	}
	else if (dif <= 0) {
		cout << "Roman Numeral can't be negative or zero\n";
		return "\0";
	}
	else {
		return cnvrt(dif);
	}
}

string romantype::operator*(romantype& z) {
	int prod = dec * z.dec;

	if (prod > 3999) {
		cout << "Product is out of range of roman numeral(1-3999)\n";
		return "\0";
	}
	else if (prod == 0) {
		cout << "Roman Numeral can't be zero\n";
	}
	else {
		return cnvrt(prod);
	}
}

string romantype::operator/(romantype& z) {

	int a = dec % z.dec;

	int div = dec / z.dec;
	if (a != 0 || div == 0) {
		cout << "Roman numeral can't be in decimal part or zero\n";
		return "\0";
	}
	else {

		return cnvrt(div);
	}
}

bool romantype::operator==(romantype z) {
	return(dec == z.dec);
}
bool romantype::operator!=(romantype z) {
	return(dec != z.dec);
}
bool romantype::operator<(romantype z) {
	return(dec < z.dec);
}
bool romantype::operator>(romantype z) {
	return(dec > z.dec);
}

string romantype::operator++() {
	++dec;
	if (dec > 3999) {
		cout << "Roman Numeral is out of range cannot be increment\n";
		--dec;
		return "\0";
	}
	else {
		roman = cnvrt(dec);
		return roman;
	}

}
string romantype::operator--() {
	--dec;
	if (dec < 0) {
		cout << "Roman Numeral cannot be negative or zero cannot be decrement\n";
		--dec;
		return "\0";
	}
	else {
		roman = cnvrt(dec);
		return roman;
	}

}
string romantype::operator++(int) {
	romantype a(roman);

	++dec;

	if (dec > 3999) {
		cout << "Roman Numeral is out of range cannot be increment\n";
		--dec;

	}
	else {
		roman = cnvrt(dec);
	}

	return cnvrt(a.dec);


}
string romantype::operator--(int) {

	romantype a(roman);

	--dec;

	if (dec < 0) {
		cout << "Roman Numeral cannot be negative or zero cannot be decrement\n";
		--dec;
	}
	else {
		roman = cnvrt(dec);
	}

	return cnvrt(a.dec);
}
string romantype::cnvrt(int c) {
	char a[30];
	int b;
	int d = c;
	int i = 0;

	b = d / 1000;

	if (b) {
		for (i = 0; i < b; i++) {
			a[i] = 'M';

		}
		d = d - b * M;

	}

	if (d >= 900) {
		a[i] = 'C';
		i++;
		a[i] = 'M';
		i++;
		d = d - 900;
	}

	b = d / 500;

	if (b) {
		for (int k = i; i < b + k; i++) {
			a[i] = 'D';

		}
		d = d - b * D;
	}

	if (d >= 400) {
		a[i] = 'C';
		i++;
		a[i] = 'D';
		i++;
		d = d - 400;
	}


	b = d / 100;

	if (b) {
		for (int k = i; i < b + k; i++) {
			a[i] = 'C';
		}
		d = d - C * b;
	}

	if (d >= 90) {
		a[i] = 'X';
		i++;
		a[i] = 'C';
		i++;
		d = d - 90;
	}
	b = d / 50;

	if (b) {
		for (int k = i; i < b + k; i++) {
			a[i] = 'L';
		}
		d = d - L * b;
	}

	if (d >= 40) {
		a[i] = 'X';
		i++;
		a[i] = 'L';
		i++;
		d = d - 40;
	}
	b = d / 10;
	if (b) {
		for (int k = i; i < b + k; i++) {
			a[i] = 'X';
		}
		d = d - X * b;
	}

	if (d >= 9) {
		a[i] = 'I';
		i++;
		a[i] = 'X';
		i++;
		d = d - 9;
	}

	b = d / 5;
	if (b) {
		for (int k = i; i < b + k; i++) {
			a[i] = 'V';
		}
		d = d - V * b;
	}

	if (d >= 4) {
		a[i] = 'I';
		i++;
		a[i] = 'V';
		i++;
		d = d - 4;
	}
	for (; d > 0; d--, i++) {
		a[i] = 'I';
	}
	a[i] = '\0';
	return a;

}
int romantype::convert() {
	int siz = size(roman);
	char b;
	int rslt = 0;
	int next = 0;
	int pr = 0;
	int count = 1;
	for (int i = siz - 1; i >= 0; i--) {
		b = roman[i];


		if (b == 'M' || b == 'm') {
			next = M;
		}
		else if (b == 'D' || b == 'd') {
			next = D;
		}
		else if (b == 'C' || b == 'c') {
			next = C;
		}
		else if (b == 'L' || b == 'l') {
			next = L;
		}
		else if (b == 'I' || b == 'i') {
			next = I;
		}
		else if (b == 'V' || b == 'v') {
			next = V;
		}
		else if (b == 'X' || b == 'x') {
			next = X;
		}
		if (pr == next) {
			count++;
		}
		else if (pr != next) {
			count = 1;
		}
		//---------conditions
		if ((next == 50 || next == 500 || next == 5) && next == pr) {
			return 0;
		}
		if (pr <= next) {
			if (next == 1 && rslt > 4) {
				return 0;
			}
			rslt += next;

		}
		else {
			if ((next == 1 && rslt != 10 && rslt != 5) || (next == 5 || next == 50 || next == 500)) {
				return 0;
			}
			rslt = rslt - next;

		}
		if (count >= 4) {
			return 0;
		}
		pr = next;
	}
	if (rslt > 3999) {
		return 0;
	}
	dec = rslt;

	return dec;
}

void main() {

	cout << "Enter 1st roman numeral\n";
	string a;
	cin >> a;
	romantype ob1(a);

	string b;
	cout << "Enter 2nd roman numeral\n";
	cin >> b;
	romantype ob2(b);

	cout << "\nAddition of roman numerals is: ";
	string w = ob1 + ob2;
	if (w[0] != '\0') {
		cout << w << endl;

	}

	cout << "\nSubtraction of roman numerals is: ";
	string z = ob1 - ob2;
	if (z[0] != '\0') {
		cout << z << endl;
	}
	cout << "\nMultiplication of roman numerals is: ";
	string x = ob1 * ob2;
	if (x[0] != '\0') {
		cout << x << endl;
	}

	cout << "\nDivision of roman numerals is: ";
	x = ob1 / ob2;
	if (x[0] != '\0') {
		cout << x << endl;
	}
	cout << endl;
	cout << "Testing Equal Function\n";
	if (ob1 == ob2) {
		cout << "Roman numeral are equal\n";
	}
	else {
		cout << "Roman numeral are not equal\n";
	}
	cout << "\nTesting Not Equal Function\n";
	if (ob1 != ob2) {
		cout << "Roman numeral are not equal\n";
	}
	else {
		cout << "Roman numeral are equal\n";
	}
	cout << "\nTesting Less than Function\n";
	if (ob1 < ob2) {
		cout << "First Roman Numeral is smaller than Second Roman Numeral\n";
	}
	else {
		cout << "First Roman Numeral is not smaller than Second Roman Numeral\n";
	}
	cout << "\nTesting Greater than Function\n";
	if (ob1 > ob2) {
		cout << "First Roman Numeral is greater than Second Roman Numeral\n\n";
	}
	else {
		cout << "First Roman Numeral is not greater than Second Roman Numeral\n\n";
	}
	cout << "Pre-Increment: ";
	x = ++ob1;
	if (x[0] != '\0') {
		cout << x << endl;
	}
	cout << "Pre-Decrement: ";
	x = --ob1;
	if (x[0] != '\0') {
		cout << x << endl;
	}
	cout << "Post-Increment: ";
	x = ob1++;
	if (x[0] != '\0') {
		cout << x << endl;
	}
	cout << "Post-Decrement: ";
	x = ob1--;
	if (x[0] != '\0') {
		cout << x << endl;
	}
}
