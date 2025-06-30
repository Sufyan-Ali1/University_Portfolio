#include<iostream>
using namespace std;
template<typename T>
T increment(T a) {
	a = a + 1;
	return a;
}
template<>
char* increment<char*>(char * a) {
	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] < 122 || a[i]>97) {
			a[i] = a[i] - 32;
		}
		
    }
	return a;
}
void main() {
	char* a;
	a = new char[20];
	cout << "Enter a alphabetic word\n";
	cin >> a;
	a=increment(a);
	cout << a;
}