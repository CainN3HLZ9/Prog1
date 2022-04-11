#include "std_lib_facilities.h"

template<typename T>
struct S
{
	S() {}

	S(T t)
	: val(t)
	{}

	istream operator>>(T t) { cin >> val; return val;}

	const T& get() const { return val; }

	T val;
};

int main()
{
	S<int> si(101);
	cout << si.get() << endl;

	S<char> sc('z');
	cout << sc.get() << endl;

	S<double> sd(10.4f);
	cout << sd.get() << endl;

	S<string> ss("A String.");
	cout << ss.get() << endl;

	S<vector<int>> svi(vector<int>(10, 100));
	for (int i : svi.get())
		cout << i << ", ";

	cout << endl;

	keep_window_open();
	return 0;
}
