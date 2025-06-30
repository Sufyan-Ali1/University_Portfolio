#include<iostream>
#include<fstream>
using namespace std;
char dictionary(char arr[][20],int rsize) {
	
	ofstream text("Dictionary.txt");
	cout << "Enter 15 words to store in our dictionary\n";

	for (int i = 0; i < rsize; i++) {
		cout << "Enter " << i + 1 << " word \t";
		cin >> arr[i];
		text << arr[i]<<"\n";
	}
	text.close();
	
	ifstream input("Dictionary.txt");
	cout << "Which word you want to find\n";
	char chr[20];
	cin >> chr;
	int i = 0;
	int j = 0;
	int k = 0;
	int check = 0;
	char arra[16][20];
	
	while (!input.eof()) {
		input.getline(arra[i], 20);
		j = 0;
		if (!input.eof()) {
			check = 0;
				if (arra[i][k] == chr[j]) {
					for(k=0;chr[j]!='\0' && arra[i][k]!='\0'; k++) {
						if (arra[i][k] == chr[j]) {
							check = 1;
							j++;
						}
						else {
							check = 0;
							break;
						}
				    }
					if (check==1 && arra[i][k] != chr[j]) {
						check = 0;
					}
			    }
				if (check == 1) {
					cout << "You spelled correctly\n";
					break;
				}
				
		}
		
		i++;
	}
	if (check == 0) {
	cout << "you spelled wrong\n";
				}
	input.close();
	return 0;
}
void main() {
   char	arr[15][20];
   int rsize = 15;
   dictionary(arr, rsize);
}