#include<iostream>
using namespace std;
void votecasting(char** candidate, int** region, int*& total, int x) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < x; j++) {
			cout << "Enter vote of " << candidate[j] << " in region " << i + 1 << ": ";
			cin >> region[i][j];
			total[j] += region[i][j];
		}
	}


}
void showrec(char** candidate, int** region, int*& total, int x) {

	cout << "\n\t\t\t----------------------Election Results-----------------------\n\n";
	cout << "Candidate\t\t\t\t\tVotes\n\n";
	cout << "Name\t\tRegion1\t\tRegion2\t\tRegion3\t\tRegion4\t\tTotal\n";
	cout << "-----\t\t--------\t--------\t--------\t--------\t--------\t\n";

	for (int i = 0; i < x; i++) {
		cout << candidate[i] << "\t";
		for (int j = 0; j < 4; j++) {
			cout << "\t" << region[j][i] << "\t";
		}
		cout << "\t" << total[i] << endl;

	}

}
void main() {
	int** region;
	region = new int* [4];
	char** candidate;
	cout << "Enter no of Candidates: ";
	int x;
	cin >> x;

	candidate = new char* [x];
	for (int i = 0; i < 4; i++) {
		region[i] = new int[x];
	}
	cin.ignore();
	for (int i = 0; i < x; i++) {
		cout << "Enter Candidate " << i + 1 << " Name: ";

		candidate[i] = new char[15];
		cin >> candidate[i];
	}
	int* total;
	total = new int[x];
	for (int i = 0; i < x; i++) {
		total[i] = 0;
	}
	votecasting(candidate, region, total, x);
	showrec(candidate, region, total, x);
	int win = 0;
	int max = 0;
	int ttl = 0;
	int* reg;
	reg = new int[x];
	for (int i = 0; i < x; i++) {
		ttl += total[i];
		if (max < total[i]) {
			max = total[i];
			win = i;
		}
	}
	for (int i = 0; i < 4; i++) {
		reg[i] = 0;
		for (int j = 0; j < x; j++) {
			reg[i] += region[i][j];
		}
	}
	cout << endl << candidate[win] << " Win\n";
	cout << "Total Votes received " << ttl << endl;
	for (int i = 0; i < 4; i++) {
		cout << "Total votes in region " << i + 1 << " " << reg[i] << endl;
	}
}