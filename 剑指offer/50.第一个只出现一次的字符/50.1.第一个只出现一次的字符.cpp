#include <cassert>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		vector<int> upper(26, 0);
		vector<int> lower = upper;

		for (auto c : str)
		{
			if (c < 91)
				++upper[c - 'A'];
			else
				++lower[c - 'a'];
		}

		for (int i = 0; i != str.size(); ++i)
		{
			auto c = str[i];
			if (c < 91 && upper[c - 'A'] == 1)
				return i;
			else if (c > 91 && lower[c - 'a'] == 1)
				return i;
		}
		return -1;
	}
};

int main()
{
	Solution s;
	//assert(s.FirstNotRepeatingChar("abaccdeff") == 1);
	//assert(s.FirstNotRepeatingChar("a") == 0);
	//assert(s.FirstNotRepeatingChar("") == -1);
	//assert(s.FirstNotRepeatingChar("abcdefg") == 0);
	//assert(s.FirstNotRepeatingChar("abcdefgabcd") == 4);
	assert(s.FirstNotRepeatingChar("kYVmIJVzYWPQLtIdKMmvkVSoKtqJANOfCCOfLVJEjjhbnPrDOwKCDeqhts") == 7);
	return 0;
}