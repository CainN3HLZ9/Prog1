#include "std_lib_facilities.h"

template<typename T>
struct S
{
	S() {}

	S(T t)
	: val(t)
	{}

	istream operator>>(T t) { cin >> val; return val;}

	T val;
};

int main()
{
	S<int> si;
	cout << "Írjon be egy int típusú elemet: "; cin >> si.val;
	cout << si.val << endl;

	S<char> sc;
	cout << "Írjon be egy char típusú elemet: "; cin >> sc.val;
	cout << sc.val << endl;

	S<double> sd;
	cout << "Írjon be egy double típusú elemet: "; cin >> sd.val;
	cout << sd.val << endl;

	S<string> ss;
	cout << "Írjon be egy string típusú elemet: "; cin >> ss.val;
	cout << ss.val << endl;

	S<vector<int>> svi(vector<int>(10,19));
	cout << "Írjon be 10 int típusú változót: ";
	for(int i = 0; i < 10; ++i)
		cin >> svi.val[i];
	for(int i : svi.val)
		cout << i << ", ";

	cout << endl;

	keep_window_open();
	return 0;
}
