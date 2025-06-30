using namespace std;

class point {
	int x;
	int y;
public:
	point(int = 0, int = 0);
	void print();
	~point();
};
point::point(int a,int b) {
	x = a;
	y = b;
	cout << "Point() Called\n";
}
void point::print() {
	cout << "(" << x << "," << y << ")" << endl;
}
point::~point() {
	cout << "~Point() called\n";
}