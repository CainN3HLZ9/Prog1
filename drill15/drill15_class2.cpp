#include "std_lib_facilities.h"

struct Person
{
public:
	Person() {}
	Person(string vezetek, string kereszt, int n) { init(vezetek, kereszt, n); }

	void init(string vezetek, string kereszt, int n)
	{
		checkName(vezetek, kereszt);
		checkAge(n);

		varVezetek = vezetek;
		varKereszt = kereszt;
		varKor = n;
	}

	string methodVezetek() const { return varVezetek; }
	string methodKereszt() const { return varKereszt; }
	int getAge() const { return varKor; }

private:
	void checkAge(int n);
	void checkName(string vezetek, string kereszt);

	string varVezetek, varKereszt;
	int varKor;
};

void Person::checkAge(int n)
{
	unsigned int difference = 150 - n;
	if (difference > 150)
		error("A kornak 0 és 150 között kell lennie");
}

void Person::checkName(string vezetek, string kereszt)
{
	if (vezetek == "")
		error("A vezetéknév nem lehet üresen hagyva");
	size_t result = vezetek.find_first_of(";:\"\'[]*&^%$#@!");
	if (result == string::npos)
	{
		if (kereszt == "")
			error("A keresztnév nem lehet üresen hagyva");

		result = kereszt.find_first_of(";:\"\'[]*&^%$#@!");
		if (result == string::npos)
			return;
	}

	error("A név nem tartalmazhatja az alábbi karaktereket: ;:\"\'[]*&^%$#@!");
}

ostream& operator<<(ostream& o, const Person& p)
{
	o << p.methodVezetek() << " " << p.methodKereszt() << ": " << p.getAge() << endl;
	return o;
}

istream& operator>>(istream& i, Person& p)
{
	string vezetek, kereszt;
	int a;
	cout << "Vezetéknév: "; cin >> vezetek;
	cout << "Keresztnév "; cin >> kereszt;
	cout << "Életkor: "; i >> a;

	p.init(vezetek, kereszt, a);

	return i;
}

int main()
{
	Person p1;
	cin >> p1;
	cout << p1;

	return 0;
}
