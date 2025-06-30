#include<iostream>
using namespace std;
int gettotal(int arr[][3], int rsize, int csize) {
	int sum = 0;
	for (int i = 0; i < rsize; i++) {
		for (int j = 0; j < csize; j++) {
			sum = sum + arr[i][j];
		}
	}
	return sum;
}
int getavg(int arr[][3],int rsize,int csize,int sum) {
	
	double avg = double(sum )/ double((rsize * csize));
	return avg;
}
double RightDiagonalSum(int arr[][3], int rsize, int csize) {
	double R_D_Sum = 0;
	for (int i = 0; i < rsize; i++) {
		R_D_Sum = R_D_Sum + arr[i][csize-1-i];
	}
	return R_D_Sum;
}
int LeftDiagonalSum(int arr[][3], int rsize, int csize) {
	int L_D_Sum = 0;
	for (int i = 0; i < rsize; i++) {
		L_D_Sum = L_D_Sum + arr[i][i];
	}
	return L_D_Sum;
}
int gethighestinrow(int arr[][3], int rsize, int csize, int row) {
	
	int max = INT_MIN;
	for (int i = 0; i < csize; i++) {
		if (max < arr[row - 1][i]) {
			max = arr[row - 1][i];
		}
	}
	return max;
}

int getlowestinrow(int arr[][3], int rsize, int csize, int row) {

	int min = INT_MAX;
	for (int i = 0; i < csize; i++) {
		if (min > arr[row - 1][i]) {
			min = arr[row - 1][i];
		}
	}
	return min;
}

void main() {
	int arr[3][3];
	int rsize = 3;
	int csize = 3;

	cout << "Enter array of 3x3 size\n";
	for (int i = 0; i < rsize; i++) {
		for (int j = 0; j < csize; j++) {
			cin >> arr[i][j];
		}
	}

	int sum=gettotal(arr, rsize, csize);
	cout << "Sum of all elements of array is \t" << sum << endl;

	double avg = getavg(arr, rsize, csize, sum);
	cout << "Average of all elements of array is\t" << avg << endl;
	
	int L_D_Sum = LeftDiagonalSum(arr, rsize, csize);
	cout << "Left Diagonal Sum of elements of array is\t" << L_D_Sum << endl;

	int R_D_Sum = RightDiagonalSum(arr, rsize, csize);
	cout << "Right Diagonal Sum of elements of array is\t" << R_D_Sum << endl;

	cout << "Enter number of row in which you find the highest element\n";
	int row;
	cin >> row;
	int high = gethighestinrow(arr, rsize, csize,row);
	cout << "The highest element in "<<row<<" row is \t" << high << endl;

	cout << "Enter number of row in which you find the smallest element\n";
	
	cin >> row;
	int small = getlowestinrow(arr, rsize, csize, row);
	cout << "The highest element in " << row << " row is \t" << small << endl;
}