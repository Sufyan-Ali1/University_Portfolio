#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class str {
	string a;
public:
	str(string = "");
	//------------operations-----------
	int size(string);
	void uprcase(string&);
	void lwrcase(string&);
	char ind(string, int);
	char* substr(string, char, char);
	int strind(string, char);
	bool cmpr(string a, string b);
	string concat(string, string);
	string concat(string, char*);
	string concat(string, int);
	string concat(string, float);


	string prepend(char*, string);
	string prepend(int, string);
	string prepend(float, string);

	string is(int);//to convert integer to string
	bool operator==(str);
	bool operator!=(str);
	bool operator<(str);
	bool operator>(str);
	char operator[](int);
	void operator=(str);
	void print() {
		cout << "String " << a << endl;
	}

	friend ostream& operator<<(ostream&, str&);
	friend istream& operator>>(istream&, str&);

	string operator+(int);
	string operator+(float);
	string operator+(char*);
	string operator+(str);
	friend string operator+(int, str);
	friend string operator+(float, str);
	friend string operator+(char*, str);
};
string str::operator+(str z) {
	char* x;
	x = new char[size(a) + size(z.a) + 1];
	int i;
	for (i = 0; i < size(a); i++) {
		x[i] = a[i];
	}
	for (int j = 0; j < size(z.a); j++, i++) {
		x[i] = z.a[j];
	}
	x[i] = '\0';

	return x;
}
string str::operator+(int b) {
	char* x;
	int c = b;
	int i;
	for (i = 0; c > 0; i++) {
		c = c / 10;
	}
	x = new char[size(a) + i + 1];

	for (i = 0; i < size(a); i++) {
		x[i] = a[i];
	}
	string z = is(b);
	for (int j = 0; z[j] != '\0'; j++, i++) {

		x[i] = z[j];
	}
	x[i] = '\0';

	return x;
}
string str::operator+(float b) {
	char* x;
	int c = b;
	int i;
	for (i = 0; c > 0; i++) {
		c = c / 10;
	}
	x = new char[size(a) + i + 1];

	for (i = 0; i < size(a); i++) {
		x[i] = a[i];
	}
	string z;
	stringstream ss;
	ss << b;
	z = ss.str();

	for (int j = 0; z[j] != '\0'; j++, i++) {

		x[i] = z[j];
	}
	x[i] = '\0';


	return x;
}
string str::operator+(char* b) {
	int i;
	for (i = 0; b[i] != '\0'; i++) {}

	char* x;
	x = new char[size(a) + i + 1];

	for (i = 0; i < size(a); i++) {
		x[i] = a[i];
	}
	for (int j = 0; b[j] != '\0'; j++, i++) {
		x[i] = b[j];
	}
	x[i] = '\0';

	return x;
}
string operator+(char* b, str z) {
	int i;
	for (i = 0; b[i] != '\0'; i++) {}

	char* x;
	x = new char[size(z.a) + i + 1];

	for (i = 0; b[i] != '\0'; i++) {
		x[i] = b[i];
	}
	for (int j = 0; j < size(z.a); j++, i++) {
		x[i] = z.a[j];
	}
	x[i] = '\0';

	return x;
}
string operator+(int b, str z) {
	char* x;
	int c = b;
	int i;
	for (i = 0; c > 0; i++) {
		c = c / 10;
	}
	x = new char[size(z.a) + i + 1];
	string y = z.is(b);
	for (i = 0; y[i] != '\0'; i++) {
		x[i] = y[i];
	}

	for (int j = 0; j < size(z.a); j++, i++) {

		x[i] = z.a[j];
	}
	x[i] = '\0';

	return x;
}
string operator+(float b, str z) {
	char* x;
	int c = b;
	int i;
	for (i = 0; c > 0; i++) {
		c = c / 10;
	}
	x = new char[size(z.a) + i + 1];
	string y;
	stringstream ss;
	ss << b;
	y = ss.str();

	for (i = 0; y[i] != '\0'; i++) {
		x[i] = y[i];
	}


	for (int j = 0; j < size(z.a); j++, i++) {

		x[i] = z.a[j];
	}
	x[i] = '\0';


	return x;
}
ostream& operator<<(ostream& obj, str& z) {
	obj << z.a << endl;

	return obj;
}
istream& operator>>(istream& iobj, str& z) {
	iobj >> z.a;

	return iobj;
}
void str::operator=(str b) {
	a = b.a;
}
char str::operator[](int x) {

	return (a[x]);
}
bool str::operator==(str b) {

	if (size(a) != size((b.a))) {
		return 0;
	}
	else {
		for (int i = 0; i < size(a); i++) {
			if (a[i] != b.a[i]) {

				return 0;
			}
		}
	}
	return 1;

}
bool str::operator!=(str b) {

	if (size(a) != size((b.a))) {
		return 1;
	}
	else {
		for (int i = 0; i < size(a); i++) {
			if (a[i] != b.a[i]) {

				return 1;
			}
		}
	}
	return 0;

}
bool str::operator<(str b) {

	return (size(a) < size((b.a)));

}

bool str::operator>(str b) {

	return (size(a) > size((b.a)));

}
string str::is(int a) {
	int c = a;
	int i;
	int count = 0;
	for (i = 0; c > 0; i++) {
		c = c / 10;
	}
	char* x;
	x = new char[i];
	c = a;
	int sum = 0;
	int b;
	bool a2 = true;
	while (c > 0) {
		b = c % 10;
		if (b != 0) {
			a2 = false;
		}
		if (b == 0 && a2)
			count++;
		c = c / 10;
		sum = sum * 10 + b;
	}

	for (i = 0; sum > 0; i++) {
		b = sum % 10;
		x[i] = b + 48;
		sum = sum / 10;
	}
	for (int j = 0; j < count; i++, j++) {
		x[i] = 0 + 48;
	}
	x[i] = '\0';
	return x;
}
string str::concat(string a, string b) {
	char* x;
	x = new char[size(a) + size(b) + 1];
	int i;
	for (i = 0; i < size(a); i++) {
		x[i] = a[i];
	}
	for (int j = 0; j < size(b); j++, i++) {
		x[i] = b[j];
	}
	x[i] = '\0';

	return x;
}
string str::concat(string a, char* b) {
	int i;
	for (i = 0; b[i] != '\0'; i++) {}

	char* x;
	x = new char[size(a) + i + 1];

	for (i = 0; i < size(a); i++) {
		x[i] = a[i];
	}
	for (int j = 0; b[j] != '\0'; j++, i++) {
		x[i] = b[j];
	}
	x[i] = '\0';

	return x;
}
string str::concat(string a, int b) {
	char* x;
	int c = b;
	int i;
	for (i = 0; c > 0; i++) {
		c = c / 10;
	}
	x = new char[size(a) + i + 1];

	for (i = 0; i < size(a); i++) {
		x[i] = a[i];
	}
	string z = is(b);
	for (int j = 0; z[j] != '\0'; j++, i++) {

		x[i] = z[j];
	}
	x[i] = '\0';

	return x;
}
string str::concat(string a, float b) {
	char* x;
	int c = b;
	int i;
	for (i = 0; c > 0; i++) {
		c = c / 10;
	}
	x = new char[size(a) + i + 1];

	for (i = 0; i < size(a); i++) {
		x[i] = a[i];
	}
	string z;
	stringstream ss;
	ss << b;
	z = ss.str();

	for (int j = 0; j < size(z); j++, i++) {

		x[i] = z[j];
	}
	x[i] = '\0';


	return x;
}

string str::prepend(char* b, string a) {
	int i;
	for (i = 0; b[i] != '\0'; i++) {}

	char* x;
	x = new char[size(a) + i + 1];

	for (i = 0; b[i] != '\0'; i++) {
		x[i] = b[i];
	}
	for (int j = 0; j < size(a); j++, i++) {
		x[i] = a[j];
	}
	x[i] = '\0';

	return x;
}

string str::prepend(int b, string a) {
	char* x;
	int c = b;
	int i;
	for (i = 0; c > 0; i++) {
		c = c / 10;
	}
	x = new char[size(a) + i + 1];
	string z = is(b);
	for (i = 0; z[i] != '\0'; i++) {
		x[i] = z[i];
	}

	for (int j = 0; j < size(a); j++, i++) {

		x[i] = a[j];
	}
	x[i] = '\0';

	return x;
}
string str::prepend(float b, string a) {
	char* x;
	int c = b;
	int i;
	for (i = 0; c > 0; i++) {
		c = c / 10;
	}
	x = new char[size(a) + i + 1];
	string z;
	stringstream ss;
	ss << b;
	z = ss.str();

	for (i = 0; z[i] != '\0'; i++) {
		x[i] = z[i];
	}


	for (int j = 0; j < size(a); j++, i++) {

		x[i] = a[j];
	}
	x[i] = '\0';


	return x;
}


void str::uprcase(string& b) {
	for (int i = 0; b[i] != '\0'; i++) {
		if (b[i] >= 97 && b[i] <= 122) {
			b[i] = b[i] - 32;
		}

	}

}
void str::lwrcase(string& b) {
	for (int i = 0; b[i] != '\0'; i++) {
		if (b[i] >= 65 && b[i] <= 90) {
			b[i] = b[i] + 32;
		}

	}

}
str::str(string b) {

	a = b;
}
char* str::substr(string b, char c, char d) {
	char* x;
	x = new char[size(b)];
	int count = 0;
	int k = 0;
	for (int i = 0; i < size(b); i++)
	{
		if (b[i] == c) {
			count = 1;
		}
		if (count) {
			x[k] = b[i];
			k++;
		}
		if (count && b[i] == d) {
			count++;
			break;
		}
	}
	x[k] = '\0';
	if (count != 2) {
		x[0] = '\0';

	}
	return x;
}
int str::strind(string b, char c) {
	for (int i = 0; i < size(b); i++) {
		if (b[i] == c) {
			return i;
		}
	}
	return 0;
}
int str::size(string b) {

	int i;
	for (i = 0; b[i] != '\0'; i++) {

	}
	return i;
}
bool str::cmpr(string a, string b) {
	if (size(a) != size(b)) {
		return 0;

	}
	else {
		for (int i = 0; i < size(a); i++) {
			if (a[i] != b[i]) {
				return 0;
			}
		}
	}
	return 1;
}
char str::ind(string b, int c) {

	return b[c];


}
void main() {
	string a;                                                          // c--> first object
	                                                                   //ob-->second object
	                                                                   //ob1-->third object
	cout << "Enter String\n";
	getline(cin, a);


	str c(a);
	cout << "Length of string is " << c.size(a) << endl;
	cout << "Upper Case: ";
	c.uprcase(a);
	cout << a << endl;
	cout << "Lower Case: ";
	c.lwrcase(a);
	cout << a << endl;
	cout << "Enter a index to find a character in first string\n";
	int m;
	cin >> m;
	cout << "Testing Given Index Character\n";
	if (m < size(a))
		cout << c.ind(a, m) << endl;
	else {
		cout << "You entered incorrect index\n";
	}
	cout << "\nTesting Extract String\n";
	cout << "To extract substring enter start and end of string\n";
	char i, j;
	cout << "Start: ";
	cin >> i;
	cout << "End: ";
	cin >> j;
	string z = c.substr(a, i, j);
	if (z[0] == '\0') {
		cout << "Substring not found\n";
	}
	else {

		cout << "Substring " << z << endl;
	}
	cout << "\nTesting starting index of Substring\n";
	int x = c.strind(a, i);
	if (z[0] != 0) {
		cout << "Starting index of substring " << x << endl;
	}
	else {
		cout << "Substring is not found\n";
	}

	cout << "\nTesting Compare two strings\n";
	cin.ignore();
	string b;
	cout << "Enter 2nd String\n";

	getline(cin, b);
	
	if (c.cmpr(a, b)) {
		cout << "Strings are Equal\n";
	}
	else {
		cout << "Strings are not Equal\n";
	}
	str ob(b);
	int x1;
	cout << "\nTesting Conatenation with integer\n";
	cout << "Enter integer to conacatenate with string: ";
	cin >> x1;
	cout << "String after concatenate: " << c.concat(a, x1) << endl << endl;
	float y1;
	cout << "\nTesting Conatenation with Float Number\n";
	cout << "Enter float number to conacatenate with string: ";
	cin >> y1;
	
	cout << "String after concatenate: " << c.concat(a, y1) << endl << endl;


	char* z1;
	z1 = new char[30];
	cout << "\nTesting Conatenation with character array\n";
	cout << "Enter character array to conacatenate with string: ";
	cin >> z1;
	cout << "String after concatenate: " << c.concat(a, z1) << endl << endl;

	cout << "Now Same integer, floar number and character prepend with string\n";
	cout << "\nTesting Prepend with integer\n";
	cout << "String after integer prepend: " << c.prepend(x1, a) << endl;
	cout << "\nTesting Prepend with Float Number\n";
	cout << "String after float number prepend: " << c.prepend(y1, a) << endl;
	cout << "\nTesting Prepend with Character Array\n";
	cout << "String after character array prepend: " << c.prepend(z1, a) << endl;


	cout << endl;
	cout << "String is assigned to another object using assignment operator(=)\n\n";
	cout << "Tesing Assigned Operator\n";
	str ob1;
	ob1 = c;
	cout << ob1;
	cout << endl;
	cout << "Compare two strings\n ";

	cout << "\nTesting Equal Operator\n";
	if (c == b) {
		cout << "First string is equal to Second string\n";
	}
	else {
		cout << "First string is not equal to Second string\n";
	}
	cout << "\nTesting Greater Operator\n";
	if (c > b) {
		cout << "First String is greater than Second string\n";
	}
	else {
		cout << "Second String is greater than First string\n";
	}
	cout << "\nTesting Lesser Operator\n";
	if (c < b) {
		cout << "First String is smaller than Second string\n";
	}
	else {
		cout << "Second String is smaller than First string\n";
	}
	cout << endl;
	cout << "Testing [] Operator\n";
	cout << "Enter a index to find a character of string\n";
	int abc;
	cin >> abc;
	cout << "Character at index " << abc << " is " << c[abc] << endl << endl;

	cout << "Enter a string using extraction operator\n";
	cin >> ob1;
	cout << "Output of string using insertion operator\n";
	cout << ob1 << endl;

	cout << "conacatenate and prepend using + operator\n";
	
	cout << "\nConcatenation\n";
	cout << c + b << endl;
	cout << c + x1 << endl;//x1 integer
	cout << c + y1 << endl;//y1 float
	cout << c + z1 << endl;//z1 char array
	cout << "\nPrepend\n";
	cout << x1 + c << endl;
	cout << y1 + c << endl;
	cout << z1 + c << endl;
}




