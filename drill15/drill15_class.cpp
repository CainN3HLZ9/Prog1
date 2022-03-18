#include "std_lib_facilities.h"

struct Person
{
public:
	Person() {}
	Person(string s, int n) { init(s, n); }

	void init(string s, int n)
	{
		nevEllen(s);
		korEllen(n);

		varNev = s;
		varKor = n;
	}

	string Nev() const { return varNev; }
	int eletkor() const { return varKor; }

private:
	void korEllen(int n);
	void nevEllen(string s);

	string varNev;
	int varKor;
};

void Person::korEllen(int n)
{

	unsigned int difference = 150 - n;
	if (difference > 150)
		error("A kor legyen 0 és 150 között");
}

void Person::nevEllen(string s)
{
	size_t result = s.find_first_of(";:[]*&^%$#@!");
	if (result == string::npos)
		return;

	error("A név nem tartalmazhatja a következő karaktereket: ;:\"\'[]*&^%$#@!");
}

ostream& operator<<(ostream& o, const Person& p)
{
	o << p.Nev() << ": " << p.eletkor() << endl;
	return o;
}

istream& operator>>(istream& i, Person& p)
{
	string s;
	int a;
	cout << "Név: "; getline(i, s);
	cout << "Kor: "; i >> a;

	p.init(s, a);

	return i;
}

int main()
{

	Person p1{ "Goofy", 63 };
	cout << p1 << endl;

	Person p2;
	cin >> p2;
	cout << p2 << endl;

	return 0;
}
