#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> map;
		int pre = -1, len = 0, maxLen = 0;
		for (int i = 0; i != s.size(); ++i)
		{
			if (map.find(s[i]) != map.end())
			{
				pre = std::max(pre, map[s[i]]);
			}
			len = i - pre;
			maxLen = std::max(len, maxLen);
			map[s[i]] = i;
		}
		return maxLen;
	}
};

int main()
{
	Solution s;
	cout << s.lengthOfLongestSubstring("pwwkew") << endl;
	return 0;
}