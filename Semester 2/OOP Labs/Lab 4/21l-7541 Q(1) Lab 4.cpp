#include<iostream>
#include<fstream>
using namespace std;
char** allocatememory(int& rows, int& cols) {
	char** matrix;
	cout << "Enter the rows of matrix\n";
	cin >> rows;
	cout << "Enter the cloumns of matrix\n";
	cin >> cols;
	matrix = new char* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new char[cols];
	}
	return matrix;
}
void loadmatrix(char** matrix, int row, int col) {
	cout << "Enter 5 rows of character matrix\n";
	for (int i = 0; i < row; i++) {
		cin >> matrix[i];
	}

	ofstream newfile;
	newfile.open("newfilewrite.txt", ios::out);
	for (int i = 0; i < row; i++) {
		//	newfile.seekp(i);
		newfile << matrix[i];
		newfile << "\n";
		cout << endl;
	}
	newfile.close();
	ifstream xyz;
	xyz.open("newfilewrite.txt", ios::in);
	for (int i = 0; i < row; i++) {
		xyz >> matrix[i];
	}


}
void displaymatrix(char** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		cout << matrix[i];
		cout << endl;
	}
}
char** removematrix(char** matrix, int rows, int cols, const char a) {
	int row = rows;
	int col = cols;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] == a) {
				
				
				
				
				for (int k = i; k < row; k++) {
					for (int l = 0; l < col; l++) {
						if (k == row - 1) {
							matrix[k ][l] = '-';
						}
						else {
							matrix[k][l] = matrix[k + 1][l];
							matrix[k + 1][l] = '-';
						}
					}
				}
				row--;
			
				for (int k = j; k < col; k++) {
					for (int l = 0; l < row; l++) {
						if (k == col - 1) {
							matrix[l][k] = '-';
						}
						else {

							matrix[l][k] = matrix[l][k + 1];
							matrix[l][k + 1] = '-';
						}
					}
				}
				col--;
				j--;
				
				

			}
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j];
		}
		cout << endl;
	}
	return matrix;
}
void main() {
	char** matrix;
	int rows;
	int cols;


	matrix = allocatememory(rows, cols);
	loadmatrix(matrix, rows, cols);

	displaymatrix(matrix, rows, cols);
	cout << "Enter which character you want to remove from matrix\n";
	char a;
	cin >> a;
	removematrix(matrix, rows, cols, a);
	system("pause");
}