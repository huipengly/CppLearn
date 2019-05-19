#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string lowestString(vector<string>& strs)
{
	sort(strs.begin(), strs.end(), [](const string & lhs, const string & rhs) { return (lhs + rhs) < (rhs + lhs); });
	string res{};
	for (auto& str : strs)
	{
		res += str;
	}
	return res;
}

int main()
{
	vector<string> strs{ "ba", "b" };
	cout << lowestString(strs) << endl;
	return 0;
}