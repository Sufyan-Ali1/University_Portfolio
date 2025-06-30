#include<iostream>
using namespace std;
int findequillibrium(int arr[], int size) {
    
    int check = -1;
    int leftsum = 0;
    for (int i = 0; i < size; i++) {
     int  rightsum = 0;
        
        for (int j = i+1; j < size; j++) {
            rightsum += arr[j];
        }
        if (leftsum == rightsum) {
            cout << "Equillibrium index is " << i << endl;
            check = 1;
        }
        leftsum += arr[i];
    }
    return 0;
}

int main()
{
    int arr[10];
    int n = 10;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    findequillibrium(arr, n);
}


