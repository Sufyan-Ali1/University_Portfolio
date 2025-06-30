#include<iostream>
using namespace std;
int IsMatrix(int **arr,int size){
	int check = 1;
	for (int i = 1; i <size; i++){
		
		for (int j = 0; j < i ; j++){
			if (arr[i][j] != 0){
				
				check = 0;
			}
		}
	}
	return check;
}
void main(){
	int **arr;
	int size;
	cout << "Enter the size of 2-D Square Matrix\n";
	cin >> size;
	arr = new int*[size];
	for (int i = 0; i < size; i++){
		arr[i] = new int[size];
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cin >> arr[i][j];
		}
	}
	int check=IsMatrix(arr, size);
	if (check==1){
		cout << "true\n";
	}
	else{
		cout << "false\n";
	}
	system("pause");
}