#include<iostream>
using namespace std;
void findstr(char arr[][11], char str[], int rowsize) {
	int i = 0;
	int check = 0;
	while (i < rowsize) {
		int k = 0;
		int index = 0;
		for (int j = 0; arr[i][j] != '\0'; j++) {
			check = 0;
			index = j;
			if (arr[i][j] == str[k]) {
				for (k = 0; str[k] != '\0'; k++) {
					if (arr[i][j] == str[k]) {
						j++;
						check = 1;
					}
					else {
						check = 0;
						break;
					}

				}
			}
			if (check) {
				cout << "the word found horizontally at " << i << " row and " << index << " column";
				break;
			}

		}
		if (check) {
			break;
		}
		i++;
	}
	if (!check) {
		while (i < 20) {
			int k = 0;
			int index = 0;
			for (int j = 0; j<rowsize; j++) {
				check = 0;
				index = j;
				if (arr[j][i] == str[k]) {
					for (k = 0; str[k] != '\0'; k++) {
						if (arr[j][i] == str[k]) {
							j++;
							check = 1;
						}
						else {
							check = 0;
							break;
						}

					}
				}
				if (check) {
					cout << "the word found vertically at " <<index  << " row and " << i << " column";
					break;
				}

			}
			if (check) {
				break;
			}
			i++;
		}
	}

}
void main() {
	char arr[6][11];
	int size = 6;
	cout << "Enter 10 strings\n";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	char str[10];
	cout << "Enter which string you want to find\n";
	cin >> str;
		findstr(arr, str, size);
}