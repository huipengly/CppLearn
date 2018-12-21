#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <unordered_set>
using std::unordered_set;

class Solution {
public:
	string longestWord(vector<string>& words) {
		// 不需要排序时，用无序的set
		unordered_set<string> word_set{ words.cbegin(), words.cend() };
		string longest{ "" };

		for (string s : word_set)
		{
			// 对不符合的条件的判定应该最先进行。
			if (s.length() < longest.length() || (s.length() == longest.length() && s > longest))
			{
				continue;
			}
			bool flag = true;
			for (int i = 1; i != s.length(); ++i)
			{
				if (word_set.count(s.substr(0, i)) == 0)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				longest = s;
			}
		}

		return longest;
	}
};

int main()
{
	Solution s;
	vector<string> vs{ "a","banana","app","appl","ap","apply","apple" };
	cout << s.longestWord(vs) << endl;
	return 0;
}