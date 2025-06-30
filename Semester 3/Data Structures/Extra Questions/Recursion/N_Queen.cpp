/*#include<iostream>
#include<vector>
using namespace std;
int isSafe(int mat[][7], int r, int c)
{
	int n = 7;
	 return 0 if two queens share the same row
	for (int i = 0; i <= c; i++)
	{
		if (mat[r][i] == 1) {
			return 0;
		}
	}

	 return 0 if two queens share the same `` diagonal
	for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
	{
		if (mat[i][j] == 1) {
			return 0;
		}
	}

	 return 0 if two queens share the same `/` diagonal
	for (int i = r, j = c; i <n  && j >= 0; i++, j--)
	{
		if (mat[i][j] == 1) {
			return 0;
		}
	}

	return 1;
}
void f(int arr[][7], int &sum, int ind,int n,int col) {
	if (col == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j];
			}
			cout << endl;
		}
		sum++;

		cout << endl << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isSafe(arr, i, col)) {
			
			
			arr[i][col] = 1;
			f(arr, sum, i, n, col + 1);
			arr[i][col] = 0;
			
		}
	}
}
void main() {
	int arr[7][7];
	int n = 7;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
	int map[] = { 0,0,0,0 };
	int sum = 0;
	f(arr, sum, 0, n, 0);
	cout << sum << endl;
}*/
// ---------------------------------------------------------------------------
//#include <stdio.h>
//#include <string.h>
//#include<iostream>
//using namespace std;
//// `N × N` chessboard
//#define N 8
//
//// Function to check if two queens threaten each other or not
//int isSafe(char mat[][N], int r, int c)
//{
//    // return 0 if two queens share the same column
//    for (int i = 0; i < r; i++)
//    {
//        if (mat[i][c] == 'Q') {
//            return 0;
//        }
//    }
//
//    // return 0 if two queens share the same `` diagonal
//    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
//    {
//        if (mat[i][j] == 'Q') {
//            return 0;
//        }
//    }
//
//    // return 0 if two queens share the same `/` diagonal
//    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
//    {
//        if (mat[i][j] == 'Q') {
//            return 0;
//        }
//    }
//
//    return 1;
//}
//
//void printSolution(char mat[][N])
//{
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = 0; j < N; j++) {
//            printf("%c ", mat[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//}
//
//void nQueen(char mat[][N], int r, int &sum)
//{
//    // if `N` queens are placed successfully, print the solution
//    if (r == N)
//    {
//        printSolution(mat);
//        sum++;
//        cout << sum << endl;;
//        return;
//    }
//
//    // place queen at every square in the current row `r`
//    // and recur for each valid movement
//    for (int i = 0; i < N; i++)
//    {
//        // if no two queens threaten each other
//        if (isSafe(mat, r, i))
//        {
//            // place queen on the current square
//            mat[r][i] = 'Q';
//
//            // recur for the next row
//            nQueen(mat, r + 1,sum);
//
//            // backtrack and remove the queen from the current square
//            mat[r][i] = '-';
//        }
//    }
//}
//
//int main()
//{
//    // `mat[][]` keeps track of the position of queens in the current configuration
//    char mat[N][N];
//
//    // initialize `mat[][]` by `-`
//    memset(mat, '-', sizeof mat);
//    int sum=0;
//    nQueen(mat, 0,sum);
//
//    return 0;
//}
//----------------------------------------------------------
#include<iostream>
#include<vector>
using namespace std;
void f(int arr[][7], int& sum, int ind, int n, int col,int leftrow[], int upd[], int lod[]) {
	if (col == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j];
			}
			cout << endl;
		}
		sum++;

		cout << endl << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (leftrow[i] ==0 &&upd[n-1+col-i]==0&&lod[i + col]==0) {
			leftrow[i] =1;
			upd[n - 1 + col - i] = 1;
			lod[i + col] = 1;
			arr[i][col] = 1;
			f(arr, sum, i, n, col + 1, leftrow, upd, lod);
			arr[i][col] = 0;
			leftrow[i] = 0;
			upd[n - 1 + col - i] = 0;
			lod[i + col] = 0;

		}
	}
}
void main() {
	int arr[7][7];
	int n = 7;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
	int leftrow[7];
	int upd[13];
	int lod[13];
	for (int i = 0; i < 13; i++) {
		upd[i] = 0;
		lod[i] = 0;
	}
	for (int i = 0; i < 7; i++) {
		leftrow[i]=0;
	}
	int sum = 0;
	f(arr, sum, 0, n, 0,leftrow,upd,lod);
	cout << sum << endl;
}