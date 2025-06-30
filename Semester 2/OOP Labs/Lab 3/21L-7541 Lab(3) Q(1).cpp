#include<iostream>
using namespace std;
void input(int*a, int*b, int*c, int size){
	cout << "Enter 1st array of " << size << " elements\n";
	for (int i = 0; i < size; i++){
		cin >> a[i];

	}
	cout << "Enter 2nd array of " << size << " elements\n";
	for (int i = 0; i < size; i++){
		cin >> b[i];

	}

	cout << "Enter 3rd array of " << size << " elements\n";
	for (int i = 0; i < size; i++){
		cin >> c[i];

	}

}
int intersectin(int *a, int*b, int*c, int**rsltarr, int size, int count[]){
	
	cout << 'a';
	cout << endl;
	int k = 0;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){

			if (a[i] == b[j]){
			
				count[0]++;
				rsltarr[0][count[0]-1] = a[i];
				
			}
			if (b[i] == c[j]){
			count[1]++;
			
			rsltarr[1][count[1] - 1]=b[i];
			}
			if (a[i] == c[j]){
			count[2]++;
			
			rsltarr[2][count[2] - 1]=a[i];
			}
		}
	}
	for (int i = 0; i <3; i++){
		for (int j = 0; j < count[i]; j++){
			cout << rsltarr[i][j];
		}
		cout << endl;
	}
	
		
		cout << endl;
		
	//system("pause");
		return 0;
}

int main(){
	int**rsltarr;
	rsltarr = new int*[3];

	int *a, *b, *c;
	cout << "Enter the size of arrays\n";
	int size;
	cin >> size;
	for (int i = 0; i < 3; i++)
	{
		rsltarr[i] = new int[size];
	}
	a = new int[size];
	b = new int[size];
	c = new int[size];
	int count[3] = {0,0,0};
	input(a, b, c, size);
	 intersectin(a, b, c, rsltarr, size,count);
	
	cout << endl;
	system("pause");
	return 0;
}