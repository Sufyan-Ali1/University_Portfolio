#include<iostream>
using namespace std;
int main() {
	cout << "Enter number of lockers\n";
	int num, i=1, j = 1, rem,count = 0,openlocker=0,closelocker=0;//rem for check number is completely divide or not
	cin >> num;
	for (i = 1;i <= num;i++) {
		count = 0;
		for (j = 1 ;j <= i;j++) {
			rem = i%j;
			if (rem == 0) {
				count++;
			}
		}
		cout << i << " has " << count << " divisor ";
		if (count % 2 == 0) {
			closelocker++;
		}
		else if (count % 2 == 1) {
			openlocker++;
		}
	}
	cout << endl;
	cout << closelocker << " are close\n";
	cout << openlocker << " are open\n";

	
	system("pause");
}