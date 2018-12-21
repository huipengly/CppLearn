#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include <iostream>
using std::cout; using std::endl;
#include <utility>
using std::pair;
#include <stack>
using std::stack;
#include <queue>
using std::priority_queue;

class Solution {
public:
	// 找到数学解的方法
	string reorganizeString(string S) {
		vector<int> counter(26, 0);
		for (auto c : S)
		{
			++counter[c - 'a'];
		}
		for (auto i : counter)
		{
			if (i > (S.length() + 1) / 2)
			{
				return "";
			}
		}
		sort(S.begin(), S.end(), 
			[counter](const char &c1, const char &c2) 
			{ return counter[c1 - 'a'] < counter[c2 - 'a'] || (counter[c1 - 'a'] == counter[c2 - 'a'] && c1 < c2); });
		int i = S.length() && 1 ? 1 : 0;
		int j = !i;
		string ret(S.length(), '0');
		int it = 0;
		for (; i < S.length(); i += 2)
		{
			ret[i] = S[it++];
		}
		for (; j < S.length(); j += 2)
		{
			ret[j] = S[it++];
		}
		return ret;
	}
};

int main()
{
	Solution s;
	cout << s.reorganizeString("aab") << endl;
	return 0;
}