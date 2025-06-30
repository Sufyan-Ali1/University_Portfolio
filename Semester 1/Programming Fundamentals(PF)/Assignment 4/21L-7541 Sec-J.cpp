#include<iostream>
#include<fstream>
using namespace std;
void main() {

	char str1[40], str2[40], str3[40];
	cout << "Enter three strings consist on two words\n";
	cout << "Enter 1st string\n";
	cin.getline(str1, 40);
	cout << "Enter 2nd string\n";
	cin.getline(str2, 40);
	cout << "Enter 3rd string\n";
	cin.getline(str3, 40);

	ofstream output("DATA.txt", ios::out);//to write strings in file
	output << str1 << "\n" << str2 << "\n" << str3 << "\n";

	output.close();
	ifstream input("DATA.txt", ios::in);//get input from file


	while (!input.eof()) {
		char chr[40];
		input.getline(chr, 40);
		if (!input.eof()) {


			char chr1[20];
			char chr2[20];
			int check1 = 0;
			int check2 = 0;


			int count = 0;
			int j = 0;
			int length1 = 0, length2 = 0;
			for (int i = 0; ; i++) {//for store the two character of string in different arrays
				if (chr[i] == '\0') {
					chr2[j] = chr[i];
					break;
				}
				else if (chr[i] == ' ') {
					count = 1;
					j = 0;
					chr1[i] = '\0';
				}
				else if (count == 0) {
					chr1[j] = chr[i];
					length1++;
					j++;
				}
				else if (count == 1) {
					chr2[j] = chr[i];
					length2++;
					j++;
				}
			}

			int k = length1, l = length2;//check 2 words in string are imperfect palindrome or not
			for (int i = 0; i < k--; i++) {
				if (chr1[i] != chr1[k]) {
					check1 += 2;
				}
			}

			for (int i = 0; i < l--; i++) {
				if (chr2[i] != chr2[l]) {
					check2 += 2;
				}
			}
			int z;
			for (int m = 0; chr1[m] != '\0'; m++) {

				for (z = 0; chr2[z] != '\0'; z++) {
					if (chr1[m] == chr2[z]) {
						for (int index = m; chr1[index] != '\0'; index++) {
							chr1[index] = chr1[index + 1];
						}
						length1--;
						for (int index1 = z; chr2[index1] != '\0'; index1++) {
							chr2[index1] = chr2[index1 + 1];
						}
						length2--;
						m--;
						break;
					}
				}
				z = 0;
			}

			if (check1 > 0 && check1 <= 2) {//check 1st word imperfect palindrome
				cout << "Yes ";
			}
			else {
				cout << " No ";
			}
			if (check2 > 0 && check2 <= 2) {//check 2nd word imperfect palindrome
				cout << "Yes ";
			}
			else {
				cout << " No ";
			}
			if ((length1 + length2) <= 2) {//check string super anagram
				cout << " Yes ";

			}
			else {
				cout << " No ";

			}
			cout << endl;
		}
	}

	input.close();
}