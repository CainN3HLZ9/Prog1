#include "std_lib_facilities.h"

template<typename T>
struct S
{
 T val;
};
int main()
{
 S<double> sd;
 sd.val = 10.4f;
 cout << sd.val << endl;

 S<string> ss;
 ss.val = "A String.";
 cout << ss.val << endl;

 keep_window_open();
 return 0;
}
