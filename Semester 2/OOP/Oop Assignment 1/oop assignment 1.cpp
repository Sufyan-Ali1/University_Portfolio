
#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include<windows.h>
using namespace std;


struct activity {
	char* ttle;
	char* userid;
	int duration;
	float priority;
};

//---------------1st function to print list of activities of given user
//----------------------in given time period..
void listact(activity***** calendar, int ptr[]) {

	cout << "Enter User ID (Format: user12)\n";
	string ar;
	cin.ignore();
	getline(cin, ar);
	/*	for (int i = 0;; i++) {
			//cin.ignore();
			if (ar[0]=='u'&&ar[1]=='s'&& ar[2] == 'e' && ar[3] == 'r') {
				break;
			}
			else {
				cout << "Please Enter user name in correct format\n";
				cin.ignore();
				cin.getline(ar, 8);
			}
		}*/
	cout << "Enter starting Date of time period\n";
	cout << "Day:";
	int sday;
	cin >> sday;
	int smonth;
	cout << "Month:";
	cin >> smonth;
	cout << "Enter ending Date of time period\n";
	cout << "Day:";
	int eday;
	cin >> eday;
	int emonth;
	cout << "Month:";
	cin >> emonth;
	cout << "\nList of Activities of user in given time period\n\n";
	int hr = 0;
	int check = 0;

	for (int a = 0; a < smonth - 1; a++) {
		if (a == 0 || a == 2 || a == 4 || a == 6 || a == 7 || a == 9 || a == 11) {
			hr = hr + 31 * 24;
		}
		else if (a == 3 || a == 5 || a == 8 || a == 10) {
			hr = hr + 30 * 24;
		}
		else if (a == 1) {
			hr = hr + 28 * 24;
		}
	}
	hr = hr + (sday - 1) * 24;

	for (int i = smonth - 1; i < emonth; i++) {
		int j = 0;
		if (i == smonth - 1) {
			j = sday - 1;
		}
		else {
			j = 0;

		}
		int x = 0;
		if (i == emonth - 1) {
			x = eday;
		}

		else if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
			x = 31;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10) {
			x = 30;
		}
		else if (i == 1) {
			x = 28;
		}
		for (; j < x; j++) {

			for (int k = 0; k < 24; k++) {

				for (int l = 0; l < ptr[hr]; l++) {

					if (calendar[i][j][k][l] != NULL) {
						string a;
						
						a = (*calendar[i][j][k][l]).userid;
						if (ar == a) {
							check = 1;
							cout << (*calendar[i][j][k][l]).ttle << endl;

						}
						

					}

				}


				hr++;

			}
		}
	}
	if (!check) {
		cout << "There is not activity exist of " << ar << endl;
	}
}

//-------------------2nd function to print 5 most important activities
void impact(activity***** calendar, int ptr[]) {
	cout << "Enter User ID (Format: user12)\n";
	string ar;
	cin.ignore();
	getline(cin, ar);
	cout << "Enter starting Date of time period\n";
	cout << "Day:";
	int sday;
	cin >> sday;
	int smonth;
	cout << "Month:";
	cin >> smonth;
	cout << "Enter ending Date of time period\n";
	cout << "Day:";
	int eday;
	cin >> eday;
	int emonth;
	cout << "Month:";
	cin >> emonth;
	float arr[365];
	cout << "\nList of Activities of user in given time period\n\n";
	int hr = 0;

	int size = 0;
	for (int a = 0; a < smonth - 1; a++) {
		if (a == 0 || a == 2 || a == 4 || a == 6 || a == 7 || a == 9 || a == 11) {
			hr = hr + 31 * 24;
		}
		else if (a == 3 || a == 5 || a == 8 || a == 10) {
			hr = hr + 30 * 24;
		}
		else if (a == 1) {
			hr = hr + 28 * 24;
		}

	}
	hr = hr + (sday - 1) * 24;

	for (int i = smonth - 1; i < emonth; i++) {
		int j = 0;
		if (i == smonth - 1) {
			j = sday - 1;
		}
		else {
			j = 0;

		}

		int x = 0;
		if (i == emonth - 1) {
			x = eday;
		}

		else if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
			x = 31;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10) {
			x = 30;
		}
		else if (i == 1) {
			x = 28;
		}
		for (; j < x; j++) {

			for (int k = 0; k < 24; k++) {

				for (int l = 0; l < ptr[hr]; l++) {

					if (calendar[i][j][k][l] != NULL) {
						string a;
						a = (*calendar[i][j][k][l]).userid;
						if (ar == a) {

							arr[size] = (*calendar[i][j][k][l]).priority;
							size++;

						}

					}

				}

				hr++;
			}

		}
	}

	//--sorting of priority array
	for (int i = 0; i < size - 1; i++) {
		for (int j = i; j < size; j++) {
			if (arr[i] < arr[j]) {
				float temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	//----searching for activity of highest priority
	hr = 0;
	int m = 0;
	int check = 0;
	int j = 0;
	int count = 0;
	//calcaluating the starting hour of the year of given time
	for (int a = 0; a < smonth - 1; a++) {
		if (a == 0 || a == 2 || a == 4 || a == 6 || a == 7 || a == 9 || a == 11) {
			hr = hr + 31 * 24;
		}
		else if (a == 3 || a == 5 || a == 8 || a == 10) {
			hr = hr + 30 * 24;
		}
		else if (a == 1) {
			hr = hr + 28 * 24;
		}
	}
	hr = hr + (sday - 1) * 24;

	int y = hr;
	while (m < 5) {
		hr = y;
		for (int i = smonth - 1; i < emonth; i++) {
			if (m == 5)
			{
				break;
			}
			check = 0;
			if (i == smonth - 1) {
				j = sday - 1;
			}
			else {
				j = 0;

			}


			int x = 0;
			if (i == emonth - 1) {
				x = eday;
			}

			else if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
				x = 31;
			}
			else if (i == 3 || i == 5 || i == 8 || i == 10) {
				x = 30;
			}
			else if (i == 1) {
				x = 28;
			}
			for (; j < x; j++) {

				for (int k = 0; k < 24; k++) {

					for (int l = 0; l < ptr[hr]; l++) {

						if (calendar[i][j][k][l] != NULL) {
							string a;
							a = (*calendar[i][j][k][l]).userid;
							if (ar == a) {
								float d;

								d = (*calendar[i][j][k][l]).priority;
								if (arr[m] == d) {
									cout << (*calendar[i][j][k][l]).ttle << endl;
									m++;
									check = 1;

								}
							}
						}

					}
					hr++;

				}

			}
		}
	}
}

//----------------7th function to print calendar stats
void calendarstat(activity***** calendar, int ptr[]) {
	int ttlact = 0;
	int hr = 0;
	float* avg;
	avg = new float;
	int* m;
	m = new int[12];
	for (int i = 0; i < 12; i++) {
		m[i] = 0;
	}

	//-------
	int size = 0;
	for (int i = 0; i < 12; i++) {
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
			size = 31;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10) {
			size = 30;
		}
		else if (i == 1) {
			size = 28;
		}

		for (int j = 0; j < size; j++) {

			for (int k = 0; k < 24; k++) {

				for (int l = 0; l < ptr[hr]; l++) {

					if (calendar[i][j][k][l] != NULL) {
						ttlact++;
						m[i]++;
					}
				}
				hr++;
			}
		}
	}
	cout << "Total no of acivities in the year" << ttlact << endl;
	*avg = float(ttlact) / 12;
	cout << "There are " << *avg << " activites average per month\n";
	int max = m[0];
	int ind = 0;
	for (int i = 0; i < 12; i++) {
		if (max < m[i]) {
			max = m[i];
			ind = i;
		}
	}
	char arr[13][13] = { {"January"},{"February"},{"March"},{"April"},{"May"},{"June"} ,{"June"} ,{"July"},{"August"},{"September"},{"October"},{"Novmber"} ,{"December"} };
	cout << arr[ind] << " is the busiest month of the year and there are " << max << " activities in this month\n";
	delete[] m;
	delete avg;
	avg = NULL;
	m = NULL;
	//-----
}
//---------------8th function to remove data of given user 
void rmvusr(activity***** calendar, int ptr[]) {
	//-----
	cout << "Enter User ID to remove the data of that user (Format: user12)\n";
	string ar;
	cin.ignore();
	getline(cin, ar);

	int hr = 0;
	int size = 0;
	int check = 0;
	for (int i = 0; i < 12; i++) {
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
			size = 31;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10) {
			size = 30;
		}
		else if (i == 1) {
			size = 28;
		}


		for (int j = 0; j < size; j++) {

			for (int k = 0; k < 24; k++) {

				for (int l = 0; l < ptr[hr]; l++) {

					if (calendar[i][j][k][l] != NULL) {
						string a;
						a = (*calendar[i][j][k][l]).userid;

						if (ar == a) {
							delete (calendar[i][j][k][l]);
							(calendar[i][j][k][l]) = NULL;
							check = 1;
						}

					}

				}
				hr++;

			}

		}




	}
	if(check)
	cout << "Data of " << ar << " is removed\n";
	else {
		cout << "Data of " << ar << " is already not exist\n";
	}
	//---
}

//--------------9th function to store calendar in file
void savcal(activity***** calendar, int ptr[]) {
	ofstream output;
	output.open("new.txt", ios::out);

	//---
	int hr = 0;
	int ac = 0;
	int size = 0;
	for (int i = 0; i < 12; i++) {
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
			size = 31;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10) {
			size = 30;
		}
		else if (i == 1) {
			size = 28;
		}
		for (int j = 0; j < size; j++) {

			for (int k = 0; k < 24; k++) {

				for (int l = 0; l < ptr[hr]; l++) {

					if (calendar[i][j][k][l] != NULL) {
						string a;
						a = (*calendar[i][j][k][l]).userid;
						int b = (*calendar[i][j][k][l]).duration;
						string c;
						c = (*calendar[i][j][k][l]).ttle;
						float d;
						d = (*calendar[i][j][k][l]).priority;
						output << j + 1 << "/" << i + 1 << "," << k + 1 << "," << k + b + 1;
						output << "," << a << "," << "act" << ac << "," << c << "," << d;
						output << "\0" << "\n";
						ac++;
					}

				}
				hr++;

			}

		}




		//-----------------------------------------------------------------
	}

	//---
	cout << "  Congratulation Data loaded in New File\n\n";

}
//-----------------6th function to print activity stats for a given month
void monstat(activity***** calendar, int ptr[]) {
	//---
	int hr = 0;
	int i;
	int* m;
	m = new int[31];
	int size = 0;
	float avg;
	float* n;
	n = new float[31];
	for (int i = 0; i < 31; i++) {
		m[i] = 0;
	}
	for (int i = 0; i < 31; i++) {
		n[i] = 0;
	}
	cout << "Enter month no for print activity stats\n";
	cin >> i;
	i--;
	for (int a = 0; a < i; a++) {
		if (a == 0 || a == 2 || a == 4 || a == 6 || a == 7 || a == 9 || a == 11) {
			hr = hr + 31 * 24;
		}
		else if (a == 3 || a == 5 || a == 8 || a == 10) {
			hr = hr + 30 * 24;
		}
		else if (a == 1) {
			hr = hr + 28 * 24;
		}


	}
	int ttlact = 0;

	if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
		size = 31;
	}
	else if (i == 3 || i == 5 || i == 8 || i == 10) {
		size = 30;
	}
	else if (i == 1) {
		size = 28;
	}


	for (int j = 0; j < size; j++) {

		for (int k = 0; k < 24; k++) {

			for (int l = 0; l < ptr[hr]; l++) {

				if (calendar[i][j][k][l] != NULL) {
					ttlact++;
					m[j]++;
					n[j] = n[j] + (*calendar[i][j][k][l]).priority;
				}

			}
			hr++;

		}
		n[j] = (n[j] / float(m[j]));

	}

	int max = m[0];
	int ind = 0;
	for (int i = 0; i < size; i++) {
		if (max < m[i]) {
			max = m[i];
			ind = i;
		}
	}


	float* maxp;//max priority
	maxp = new float;
	*maxp = n[0];
	int indp = 0;
	for (int i = 0; i < size; i++) {
		if (*maxp < n[i]) {
			*maxp = n[i];
			indp = i;
		}
	}
	avg = float(ttlact) / 12;
	cout << "Total no of acivities in the month is " << ttlact << endl;

	cout << "There are " << avg << " activites average per day\n";
	cout << ind + 1 << " day of the month is the busiest day and there are " << max << " activities on that day\n";
	cout << indp + 1 << " day of the month is the important day and there are " << m[indp] << " activities on that day\n";
	cout << endl;
	delete[]m;
	m = NULL;
	delete maxp;
	maxp = NULL;
	delete[]n;
	n = NULL;
}

//-----------------------Last Function to print month of a calendar

void clrotput(activity***** calendar, int ptr[]) {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);

	int hr = 0;
	int i;

	cout << "Enter month number\n";
	cin >> i;
	i--;
	for (int a = 0; a < i; a++) {
		if (a == 0 || a == 2 || a == 4 || a == 6 || a == 7 || a == 9 || a == 11) {
			hr = hr + 31 * 24;
		}
		else if (a == 3 || a == 5 || a == 8 || a == 10) {
			hr = hr + 30 * 24;
		}
		else if (a == 1) {
			hr = hr + 28 * 24;
		}
	}
	int size = 0;

	if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
		size = 31;
	}
	else if (i == 3 || i == 5 || i == 8 || i == 10) {
		size = 30;
	}
	else if (i == 1) {
		size = 28;
	}
	for (int j = 0; j < size; j++) {
		int check = 0;
		int k = j + 1;
		for (int k = 0; k < 24; k++) {

			for (int l = 0; l < ptr[hr]; l++) {
				check = 1;
				if (calendar[i][j][k][l] != NULL) {

				}

			}
			hr++;

		}
		if (check) {
			SetConsoleTextAttribute(console_color, 7);

			cout << k << "	";

		}
		else if (!check) {
			SetConsoleTextAttribute(console_color, 6);

			cout << k << "	";
		}
		if (k % 7 == 0) {
			cout << endl;
		}

	}
	cout << endl;
}
//----------------4th function to prinnt clash activities of two user
void clashsact(activity***** calendar, int ptr[]) {

	int hr = 0;
	int i;
	int size = 0;
	string user1;
	string user2;
	int sday;
	int eday;
	int smonth;
	int emonth;
	int check = 0;
	int j = 0;


	cout << "Enter User1 ID (Format: user12)\n";
	cin.ignore();
	getline(cin, user1);
	cout << "Enter User2 ID (Format: user12)\n";

	getline(cin, user2);
	cout << "Enter starting Date of time period\n";
	cout << "Day:";
	cin >> sday;
	cout << "Month:";
	cin >> smonth;
	cout << "Enter ending Date of time period\n";
	cout << "Day:";
	cin >> eday;
	cout << "Month:";
	cin >> emonth;
	cout << user1 << "   " << user2 << endl;


	for (int a = 0; a < smonth - 1; a++) {
		if (a == 0 || a == 2 || a == 4 || a == 6 || a == 7 || a == 9 || a == 11) {
			hr = hr + 31 * 24;
		}
		else if (a == 3 || a == 5 || a == 8 || a == 10) {
			hr = hr + 30 * 24;
		}
		else if (a == 1) {
			hr = hr + 28 * 24;
		}
	}
	hr = hr + (sday - 1) * 24;
	i = smonth - 1;
	cout << "\nClasing activities of " << user1 << " and " << user2 << endl << endl;

	for (; i < emonth; i++) {
		//to find ending day of months
		if (i == emonth - 1) {
			size = eday;
		}
		else if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
			size = 31;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10) {
			size = 30;
		}
		else if (i == 1) {
			size = 28;
		}
		//to check starting day of month
		if (i == smonth - 1) {
			j = sday - 1;
		}
		else {
			j = 0;
		}

		for (; j < size; j++) {

			for (int k = 0; k < 24; k++) {
				int f = hr;
				for (int l = 0; l < ptr[hr]; l++) {

					if (calendar[i][j][k][l] != NULL) {

						string a;
						a = (*calendar[i][j][k][l]).userid;
						int b = (*calendar[i][j][k][l]).duration;
						if (a == user1) {

							for (int m = k; m < k + b; m++) {

								for (int n = 0; n < ptr[f]; n++) {

									string b;
									b = (*calendar[i][j][m][n]).userid;

									if (b == user2) {

										check = 1;
										cout << (*calendar[i][j][m][n]).ttle << endl;
										cout << (*calendar[i][j][k][l]).ttle << endl;
									}
								}
								f++;

							}

						}
						if (!check) {
							if (a == user2) {

								for (int m = k; m < k + b; m++) {

									for (int n = 0; n < ptr[f]; n++) {

										string b;
										b = (*calendar[i][j][m][n]).userid;

										if (b == user1) {

											check = 1;
											cout << (*calendar[i][j][m][n]).ttle << endl;
											cout << (*calendar[i][j][k][l]).ttle << endl;
										}
									}
									f++;

								}
							}
						}
					}

				}
				hr++;
			}
		}
	}
	cout << endl;
	if (!check) {
		cout << "There is not any clashing activity exist\n";
	}
}

void freetime(activity***** calendar, int ptr[]) {
	int size = 0;
	int hr = 0;

	for (int i = 0; i < 12; i++) {
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
			size = 31;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10) {
			size = 30;
		}
		else if (i == 1) {
			size = 28;
		}

		for (int j = 0; j < size; j++) {

			for (int k = 0; k < 24; k++) {

				if ((calendar[i][j][k][0]) == NULL) {
					if (k < 12) {
						cout << "At " << k << " am";
					}
					else if (k == 12) {
						cout << "At " << k << " pm";
					}
					else {
						cout << "At " << k % 12 << " am";
					}
					cout << " Day " << j + 1 << " Month" << i + 1 << " all users are free\n";
				}
				hr++;
			}
		}
	}
}

int main() {

	int ptr[365 * 24];

	//to give every hour year value equal to zero to show that there is zero acivity store on that hour 
	for (int i = 0; i < (365 * 24); i++) {
		ptr[i] = 0;
	}
	activity***** calendar;
	int x = 0;
	int month = 12;
	calendar = new activity * ***[month];
	for (int i = 0; i < month; i++) {
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
			calendar[i] = new activity * **[31];
			for (int j = 0; j < 31; j++) {
				calendar[i][j] = new activity * *[24];
				for (int k = 0; k < 24; k++) {
					calendar[i][j][k] = new activity * [50];
					for (int l = 0; l < 50; l++) {
						calendar[i][j][k][l] = NULL;
					}

				}
			}
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10) {
			calendar[i] = new activity * **[30];
			for (int j = 0; j < 30; j++) {
				calendar[i][j] = new activity * *[24];
				for (int k = 0; k < 24; k++) {
					calendar[i][j][k] = new activity * [50];
					for (int l = 0; l < 50; l++) {
						calendar[i][j][k][l] = NULL;
					}

				}
			}
		}
		else if (i == 1) {
			calendar[i] = new activity * **[28];
			for (int j = 0; j < 28; j++) {
				calendar[i][j] = new activity * *[24];
				for (int k = 0; k < 24; k++) {
					calendar[i][j][k] = new activity * [50];
					for (int l = 0; l < 50; l++) {
						calendar[i][j][k][l] = NULL;
					}
				}
			}
		}
	}
	int  date = 0;
	int m = 0, st = 0, en = 0;
	string str;
	ifstream input;

	input.open("new.txt", ios::in);
	
	if (input) {

		while (!input.eof()) {
			

			getline(input, str);

			if (!input.eof()) {
				//------to store day

				date = 0;
				m = 0, st = 0, en = 0;
				float pr = 0.0;//priority
				char usr[10];
				char title[50];
				int i;
				
				for (i = 0; str[i] != '/'; i++) {
					date = date * 10 + (str[i] - 48);
				}
				
				i++;
				
				//---------to store month
				for (; str[i] != ','; i++) {
					m = m * 10 + (str[i] - 48);
				}
				
				i++;
				
				//---------to store starting time
				for (; str[i] != ','; i++) {
					st = st * 10 + (str[i] - 48);
				}
				
				i++;
				//---------to store ending time
				for (; str[i] != ','; i++) {
					en = en * 10 + (str[i] - 48);
				}
				i++;
				
				//---------to store user id
				int j;
				for (j = 0; str[i] != ','; i++, j++)
				{
					usr[j] = str[i];
				}
				usr[j] = '\0';
				i = i + 4;
				
				while (str[i] == ',' || (str[i] >= '0' && str[i] <= '9'))
					i++;

				//---------to store title
				for (j = 0; str[i] != ','; j++, i++) {
					title[j] = str[i];

				}

				title[j] = '\0';
				
				i++;                        //end of use of i

				//---------to store priority

				stringstream str1;
				for (j = 0; str[i] != '\0'; i++, j++) {
					str1 << str[i];
				}
				str1 >> pr;
				
				//------------------now store data into calendar---------------------//

				//for (int i = st; i < st + 1; i++) {
				i = st;
				int hr = 0;
				hr = 0;
				//-----calcaluating the hour of year
				for (int a = 0; a < m - 1; a++) {
					
					if (a == 0 || a == 2 || a == 4 || a == 6 || a == 7 || a == 9 || a == 11) {
						hr = hr + 31 * 24;
					}
					else if (a == 3 || a == 5 || a == 8 || a == 10) {
						hr = hr + 30 * 24;
					}
					else if (a == 1) {
						hr = hr + 28 * 24;
					}
				}
				hr = hr + (date - 1) * 24;
				
				hr = hr + i;
				
				//---------------------------	
				
				calendar[m - 1][date - 1][i][ptr[hr]] = new activity;
				//--to store priority in calendar
				
				(*calendar[m - 1][date - 1][i][ptr[hr]]).priority = pr;


				//--to store duration in calendar
				if (en > st) {
					(*calendar[m - 1][date - 1][i][ptr[hr]]).duration = en - st;
				}
				//if starting time is larger than ending time
				else if (en < st) {
					int time = 0;
					time = (24 - st) + en;
					(*calendar[m - 1][date - 1][i][ptr[hr]]).duration = time;
				}

				//--to store title in calendar
				(*calendar[m - 1][date - 1][i][ptr[hr]]).ttle = new char[40];

				for (j = 0; title[j] != '\0'; j++) {
					(*calendar[m - 1][date - 1][i][ptr[hr]]).ttle[j] = title[j];
				}
				(*calendar[m - 1][date - 1][i][ptr[hr]]).ttle[j] = '\0';

				//--to store userid in calendar
				(*calendar[m - 1][date - 1][i][ptr[hr]]).userid = new char[40];
				for (j = 0; usr[j] != '\0'; j++) {
					(*calendar[m - 1][date - 1][i][ptr[hr]]).userid[j] = usr[j];

				}
				(*calendar[m - 1][date - 1][i][ptr[hr]]).userid[j] = '\0';

				ptr[hr] ++;
				//cout << hr << endl;
				//cout << ptr[hr] << endl;
				



			}

		}


	}

	//cout << date - 1 << "  " << m - 1 << "  " << st << "  " << '0' << endl;
	else if (!input) {
		cout << "file not found\n";
	}
	input.close();

	while (1) {

		cout << "\n  Press(1): For list of all activities of a given user during a time period\n\n";
		cout << "  Press(2): For List of 5 most important activites of a given user during a time period\n\n";
		cout << "  Press(3): For a given user, print the longest free period; that is, the";
		cout << "  longest consecutive number \n  of days in which the user has no activity\n\n";
		cout << "  Press(4): List all the clashing activities of a pair of users, during a time	period\n\n";
		cout << "  Press(5): For a list of users, and a time period, list all hourly slots that are\n";
		cout << "  Free for all these user in this time period\n\n";
		cout << "  Press(6): Print activity stats for a given month\n\n";
		cout << "  Press(7): Print Calendar Stats\n\n";
		cout << "  Press(8): Remove a user from the calendar\n\n";
		cout << "  Press(9): Save the calendar\n\n";
		cout << "  press(10): to print any month of a calendar\n\n";
		int a;
		cout << "  Select: ";
		cout << endl;


		cin >> a;
		//----function call
		if (a == 1) {
			listact(calendar, ptr);
		}
		else if (a == 2) {
			impact(calendar, ptr);
		}
		else if (a == 3) {

		}
		else if (a == 4) {
			clashsact(calendar, ptr);
		}
		else if (a == 5) {
			freetime(calendar, ptr);
		}
		else if (a == 6) {
			monstat(calendar, ptr);
		}
		else if (a == 7) {
			calendarstat(calendar, ptr);
		}
		else if (a == 8) {
			rmvusr(calendar, ptr);//remove user
		}
		else if (a == 9) {
			savcal(calendar, ptr); //savecalendar;
		}
		else if (a == 10) {
			clrotput(calendar, ptr);
		}
		cout << "For Process more functions press (1) else (0)\n";
		int* z;
		z = new int;
		cin >> *z;
		if (*z == 0) {
			delete z;
			z = NULL;
			break;
		}
	}

	//-----------------Deletion-----------   
	int hr = 0;
	for (int i = 0; i < 12; i++) {
		int size = 0;
		cout << "a" << endl;
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
			size = 31;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10) {
			size = 30;
		}
		else if (i == 1) {
			size = 28;
		}
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < 24; k++) {

				for (int l = 0; l < ptr[hr]; l++) {

					delete[]calendar[i][j][k][l];

				}
				hr++;
				delete[]calendar[i][j][k];
			}
			delete[]calendar[i][j];
		}
		delete[]calendar[i];
	}

	delete[]calendar;
	return 0;

}
