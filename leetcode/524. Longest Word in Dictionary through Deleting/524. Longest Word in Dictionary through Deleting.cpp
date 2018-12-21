#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		string result = "";
		for (auto ds : d)
		{
			if (ds.length() < result.length()) continue;
			if (canDeleteSomeLetter(s, ds))
			{
				if (ds.length() > result.length() || (ds.length() == result.length() && ds < result))
				{
					result = ds;
				}
			}
		}
		return result;
	}
private:
	bool canDeleteSomeLetter(const string& s, const string &d)
	{
		int j = 0;
		for (int i = 0; i != s.length() && j != d.length(); ++i)
		{
			if (s[i] == d[j])
			{
				++j;
			}
		}
		return j == d.length();
	}
};

int main()
{
	Solution s;
	vector<string> dic = { "ba","ab","a","b" };
	cout << s.findLongestWord("abpcplea", dic) << endl;
	return 0;
}