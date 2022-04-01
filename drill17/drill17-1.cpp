#include "std_lib_facilities.h"

void print_array10(ostream& os, int* a)
{
	for (int i = 0; i < 10; ++i)
		os << "n " << i << ": " << a[i] << "	memory addr: " << &a[i] << endl;
}

void print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
		os << "n " << i << ": " << a[i] << "	memory addr: " << &a[i] << endl;
}

int* allocate_array(int n)
{
	int* a = new int[n];
	int counter = 100;
	for (int i = 0; i < n; ++i)
		a[i] = counter++;

	return a;
}

vector<int*> allocate_vector(int n)
{
	vector<int*> temp;
	int counter = 100;
	for (int i = 0; i < n; ++i)
		temp.push_back(new int{counter++});

	return temp;
}

void print_vector(vector<int*> v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << "n " << i << ": " << *v[i] << "	memory addr: " << v[i] << endl;
}

void delete_vector(vector<int*> v)
{
	for (int i = 0; i < v.size(); ++i)
		delete v[i];
}

int main()
{
	int* tenInts = new int[10];

	for (int i = 0; i < 10; ++i){
		cout << "n " << i << ": " << tenInts[i] << "	memory addr: " << &tenInts[i] << endl;
  }

	print_array10(cout, tenInts);
	delete[] tenInts;

	int* tenInts2 = new int[10]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };
	print_array10(cout, tenInts2);
	delete[] tenInts2;

	int* intArray = new int[11]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };
	print_array(cout, intArray, 11);
	delete[] intArray;

	int* twentyInts = allocate_array(20);
	print_array(cout, twentyInts, 20);
	delete[] twentyInts;

	vector<int*> v_tenInts = allocate_vector(10);
	print_vector(v_tenInts);
	delete_vector(v_tenInts);

	vector<int*> v_11Ints = allocate_vector(11);
	print_vector(v_11Ints);
	delete_vector(v_11Ints);

	vector<int*> v_20Ints = allocate_vector(20);
	print_vector(v_20Ints);
	delete_vector(v_20Ints);

	keep_window_open();
	return 0;
}
