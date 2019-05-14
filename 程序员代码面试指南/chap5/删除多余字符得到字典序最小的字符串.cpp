#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 书上的实现方法
class Solution {
public:
	string removeDuplicateLetters(string str) {
		vector<int> map(26, 0);
		string ret{};
		ret.reserve(26); //	因为只有小写字母，所以返回的字符串最多只有26位，提前申请空间
		for (int i = 0; i != str.size(); ++i)
		{
			++map[str[i] - 'a'];
		}
		int l = 0, r = 0;
		while (r != str.size())
		{
			if (map[str[r] - 'a'] == -1 ||
				--map[str[r] - 'a'] > 0)
			{
				++r;
			}
			else
			{
				int pick = -1;
				for (int i = l; i <= r; ++i)
				{
					if (map[str[i] - 'a'] != -1 &&
						(pick == -1 || str[i] < str[pick]))
					{
						pick = i;
					}
				}
				ret += str[pick];
				map[str[pick] - 'a'] = -1;
				for (int i = pick + 1; i <= r; ++i)		// 这里要从pick+1开始，因为前面的不在需要了
				{
					if (map[str[i] - 'a'] != -1)
						++map[str[i] - 'a'];
				}
				l = pick + 1;
				r = l;
			}
		}
		return ret;
	}
};

// 我自己的实现，其实并不需要删除字符串，只需要标注哪些不需要了，而且统计也只需要统计一回
class Solution_erase {
public:
	string removeDuplicateLetters(string s) {
		vector<int> map(26, 0);
		string ret{};
		int min_c = 26, min_index = -1;
		while (!s.empty())
		{
			// 统计字频
			for (int i = 0; i != s.size(); ++i)
			{
				++map[s[i] - 'a'];
			}
			// 找到某个字符频率为0的时候，并且找到这个区间内最小的字符
			for (int i = 0; i != s.size(); ++i)
			{
				int c = s[i] - 'a';
				if (c < min_c)
				{
					min_c = c;
					min_index = i;
				}
				if (--map[c] == 0)
				{
					ret += 'a' + min_c;
					// 移除选定之前的
					s.erase(0, min_index);
					// 移除最小的字符
					s.erase(remove(s.begin(), s.end(), min_c + 'a'), s.end());
					min_c = 26;
					map = vector<int>(26, 0);
					break;
				}
			}
		}
		return ret;
	}
};

int main()
{
	Solution s;
	cout << s.removeDuplicateLetters("cbacdcbc") << endl;
	return 0;
}