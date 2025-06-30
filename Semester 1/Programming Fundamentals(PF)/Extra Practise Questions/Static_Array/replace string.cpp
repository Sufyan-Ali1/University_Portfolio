#include<iostream>
using namespace std;
int replacefunc(char str[], char findstr[], char replacestr[]) {
	int len = 0;
	//to find length of string
	for (len = 0; str[len] != '\0'; len++);

	int j ;
	int len1 = 0;// length of string that you want to replace

	int check = 0;//
	int index = -1;//index of character from where replace string start
	for (int i = 0; str[i] != '\0'; i++) {
		j = 0;
		if (str[i] == findstr[j]) {
			index = i;
			len1 = 0;
			for (j=0; findstr[j] != '\0'; j++) {
				if (str[i] == findstr[j]) {
					i++;
					check = 1;
					len1++;
				}
				else {
					check = 0;
					break;
				}
			}

		}
		if (check == 1 && (str[i]==' '||str[i]=='\0')) {
			break;
		}
		else {
			check = 0;
		}
	}

	if(check==1){
		
		for (int i = 0;len1>0||replacestr[i]!='\0'; ) {

			if (len1>0 && replacestr[i]!='\0') {
				str[index] = replacestr[i];
				len1--;
				index++;
				i++;
			}

		else if (len1 == 0 && replacestr[i] != '\0') {
				for (int j = len;j>=index;j-- ){
					str[j + 1] = str[j];
			    }
				len++;
				str[index] = replacestr[i];
				index++;
				i++;
			}
			else if (replacestr[i] == '\0' && len1>0) {
				int k;
				for (int k=index;;k++ ) {
					str[k] = str[k + 1];
					if (str[k] == '\0')
						break;
				}
			
				len1--;
			}
		}
		cout << "\n" << str << "\n";
    }
	else {
		cout << "string is not found\n";
	}
	
	return 0;
}
void main() {
	char str[150];
	char findstr[50];
	char replacestr[60];

	cout << "Enter a string\n";
	cin.getline(str, 150);
	cout << "Enter a word or string whcih you want to replace\n";
	cin.getline(findstr, 50);
	cout << "Enter the replaced string or word\n";
	cin.getline(replacestr, 60);

	replacefunc(str,findstr,replacestr);
}