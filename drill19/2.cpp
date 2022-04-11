#include "std_lib_facilities.h"

template<typename T>
struct S
{
	S(T t)
	: val(t)
	{}

	T val;
};

int main()
{
	S<double> sd(10.4f);
	cout << sd.val << endl;

	S<string> ss("A String.");
	cout << ss.val << endl;

	keep_window_open();
	return 0;
}
