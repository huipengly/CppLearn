#include <string>
using std::string;
#include <algorithm>
using std::sort;
#include <vector>
using std::vector;

class Solution {
public:
	// 构造统计表，不需要排序。
	bool isAnagram(string s, string t) {
		if (s.length() != t.length())
		{
			return false;
		}
		vector<int> count(26, 0);
		for (int i = 0; i != s.length(); ++i)
		{
			++count[s[i] - 'a'];
			--count[t[i] - 'a'];
		}
		for (auto i : count)
		{
			if (i != 0)
			{
				return false;
			}
		}
		return true;

	}
	bool isAnagram_sort(string s, string t) {
		if (s.length() != t.length())
		{
			return false;
		}
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		if (s == t)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	return 0;
}