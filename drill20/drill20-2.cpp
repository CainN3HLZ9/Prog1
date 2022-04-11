#include "std_lib_facilities.h"
#include <iterator>

template<typename Iter1, typename Iter2>
Iter2 IterCopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while (f1 != e1)
	{
		*f2 = *f1;
		++f1;
		++f2;
	}

	return f2;
}

// -----------------------------------------------------------------------------

int main()
{
	array<int, 10> intArray = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	vector<int> intVector{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	list<int> intList{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	array<int, 10> intArray2 = intArray;

	vector<int> intVector2 = intVector;

	list<int> intList2 = intList;

	for (int& i : intArray)
		i += 2;

	for (int& i : intVector)
		i += 3;

	for (int& i : intList)
		i += 5;

	IterCopy(intArray.begin(), intArray.end(), intVector2.begin());
	if (intArray[0] != intVector2[0])
		cout << "Az intArray[0] és intVector2[0] nem egyezik!" << endl;

	IterCopy(intList.begin(), intList.end(), intArray2.begin());
	if(*(intList.begin()) != intArray2[0])
		cout << "Az intList[0] ls intArray2[0] nem egyezik!" << endl;

	auto vecResult = find(begin(intVector), end(intVector), 3);
	if (vecResult != end(intVector))
		cout << "intVector tartalmaz 3-at:" << distance(intVector.begin(), vecResult) << endl;
	else
		cout << "intVector nem tartalmaz 3-at" << endl;

	auto listResult = find(begin(intList), end(intList), 27);
	if (listResult != end(intList))
		cout << "listResult tartalmat 27-et:" << distance(intList.begin(), listResult) << endl;
	else
		cout << "listResult nem tartalmaz 27-et" << endl;

	intList.push_back(27);
	listResult = find(begin(intList), end(intList), 27);
	if (listResult != end(intList))
		cout << "listResult tartalmaz 27-et:" << distance(intList.begin(), listResult) << endl;
	else
		cout << "listResult nem tartalmaz 27-et" << endl;

	keep_window_open();
	return 0;
}
