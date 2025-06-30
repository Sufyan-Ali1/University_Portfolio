#include<iostream>
using namespace std;
int kthSmallest(int arr[], int l, int r, int k)
{
    int j = l - r + 1;
    int *arra;
    arra = new int[j];
    for (int i = 0; i < j; i++, l++) {
        arra[i] = arr[l];
    }

    for (int i = 0; i < j; i++) {
        for (int m = 0; m < j - i - 1; m++) {
            if (arra[m] > arra[m + 1]) {
                int temp = arra[m];
                arra[m] = arra[m + 1];
                arra[m + 1] = temp;
            }
        }
    }
    return arra[k - 1];


}
void main() {
	int arr[10];
	int l = 1;
	int r = 9;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    int k = kthSmallest(arr, l, r, 5);
    cout << endl << k << endl;
}