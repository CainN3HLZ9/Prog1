#include "std_lib_facilities.h"

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

int main()
{
	S<int> si(101);
	si = 10;
	cout << si.getRef() << endl;

	S<char> sc('z');
	sc = 'a';
	cout << get(sc) << endl;

	S<double> sd(10.4f);
	sd = 83.3f;
	cout << get(sd) << endl;

	S<string> ss("A String.");
	ss = "hosszabb string";
	cout << get(ss) << endl;

	S<vector<int>> svi(vector<int>(10, 100));
	svi = vector<int>(10, 15);
	for (int i : get(svi))
		cout << i << ", ";

	cout << endl;

	keep_window_open();
	return 0;
}
