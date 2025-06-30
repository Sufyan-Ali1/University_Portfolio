#pragma once

class mTime
{
	int hour;
	int min;
	int sec;
public:
	mTime(int = 0, int = 0, int = 0);
	void setmin(int );
	void sethour(int );
	void setsec(int );
	int gethour();
	int getmin();
	int getsec();
	friend ostream& operator<<(ostream& , mTime& );
};
mTime::mTime(int a, int b, int c) {
	hour = a;
	min = b;
	sec = c;
}
void mTime::setmin(int a) {
	min = a;
}
void mTime::sethour(int a) {
	hour = a;
}
void mTime::setsec(int a) {
	sec = a;
}
int mTime::getmin() {
	return min ;
}
int mTime::gethour() {
	return hour;
}
int mTime::getsec() {
	return sec;
}
ostream& operator<<(ostream& ob, mTime& a) {
	ob << "Time= " << a.hour << ":" << a.min << ":" << a.sec << endl;
	return ob;
}