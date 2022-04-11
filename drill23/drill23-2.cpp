#include "std_lib_facilities.h"

#include <regex>

// -----------------------------------------------------------------------------

void Eljaras()
{
	ifstream in{ "Iranyitoszamok.txt" };
	if (!in)
	{
		cerr << "no file\n";
	}

	regex pat{ R"(\w{2}\s*\d{5}(-\d{4})?)" };

	int lineNum = 0;
	for (string line; getline(in, line);)
	{
		++lineNum;
		smatch matches;
		if (regex_search(line, matches, pat))
		{
			cout << lineNum << ": " << matches[0] << endl;
			if (1 < matches.size() && matches[1].matched)
			{
				cout << "\t: " << matches[1] << endl;
			}
		}
	}
}

int main()
{
	Eljaras();

	keep_window_open();
	return 0;
}
