#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		if (numbers.empty())
			return {};
		vector<string> strs;
		strs.reserve(numbers.size());
		for (auto i : numbers)
			strs.push_back(to_string(i));

		sort(strs.begin(), strs.end(), [](const string &lhs, const string &rhs) { return string{ lhs + rhs } < string{ rhs + lhs }; });
		string ret{};
		for (auto &str : strs)
		{
			ret += str;
		}

		return ret;
	}
};

int main()
{
	Solution s;
	cout << s.PrintMinNumber({3, 32, 321}) << endl;
	return 0;
}