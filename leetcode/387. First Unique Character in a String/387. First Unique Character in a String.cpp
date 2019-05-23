#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> map(256, 0);
		for (char c : s)
			++map[c];
		for (int i = 0; i != s.size(); ++i)
			if (map[s[i]] == 1)
				return i;
		return -1;
	}
};

int main()
{
	Solution s;
	cout << s.firstUniqChar("leetcode") << endl;
	return 0;
}