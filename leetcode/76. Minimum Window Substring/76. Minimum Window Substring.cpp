#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	string minWindow(string s, string t) {
		if (s.empty() || t.empty() || s.size() < t.size())
			return "";
		unordered_map<char, int> map;
		for (char c : t)
			++map[c];
		int left = 0, right = 0, min_len = INT_MAX, match = t.size();
		string min_str{};
		while (right != s.size())
		{
			--map[s[right]];
			if (map[s[right]] >= 0)
				--match;

			if (match == 0)
			{
				while (map[s[left]] < 0)
					++map[s[left++]];
				int len = right - left + 1;
				if (len < min_len)
				{
					min_len = len;
					min_str = s.substr(left, len);
				}
				++match;
				++map[s[left++]];
			}
			++right;
		}
		return min_str;
	}
};

int main()
{
	Solution s;
	cout << s.minWindow("adabbca", "acb") << endl;
	return 0;
}