#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

template<typename T>
struct S
{
	S() {}

	S(T t)
	: val(t)
	{}

	S& operator=(const T& newValue) { val = newValue; return *this; }
	istream operator>>(T t) { cin >> val; return val;}

	void set(T t) { val = t; }
	const T& get() const { return val; return val;}

	T& getRef() {return val;}

private:
	T val;
};

template<typename T>
const T& get(S<T>& s)
{
	return s.get();
}

template<typename T>
void read_val(T& v)
{
	cin >> v;
}

int main()
{
	S<int> si;
	cout << "Írjon be egy int típusú változót: "; read_val(si.getRef());
	cout << si.get() << endl;

	S<char> sc;
	cout << "Írjon be egy char típusú változót: "; read_val(sc.getRef());
	cout << sc.get() << endl;

	S<double> sd;
	cout << "Írjon be egy double típusú változót: "; read_val(sd.getRef());
	cout << sd.get() << endl;

	S<string> ss;
	cout << "Írjon be egy string típusú változót: "; read_val(ss.getRef());
	cout << ss.get() << endl;

	S<vector<int>> svi(vector<int>(10, 19));
	cout << "Írjon be 10 int típusú változót: ";
	for (int i = 0; i < 10; ++i)
		read_val(svi.getRef()[i]);
	for (int i : svi.get())
		cout << i << ", ";

	cout << endl;

	keep_window_open();
	return 0;
}
