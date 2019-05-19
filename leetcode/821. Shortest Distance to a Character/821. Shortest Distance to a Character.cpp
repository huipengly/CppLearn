#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 本来我是用标志位判断last，比如等于-1.其实可以直接给last一个很大的值就行了，具体见leetcode题解
class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		vector<int> shortestDistance(S.size(), INT_MAX);
		int last = -1;
		for (int i = S.find(C); i != S.size(); ++i)
		{
			if (S[i] == C)
			{
				shortestDistance[i] = 0;
				last = i;
			}
			else if (last != -1)
			{
				shortestDistance[i] = i - last;
			}
		}
		last = -1;
		for (int i = S.size() - 1; i >= 0; --i)
		{
			if (S[i] == C)
			{
				last = i;
			}
			else if (last != -1)
			{
				shortestDistance[i] = std::min(shortestDistance[i], last - i);
			}
		}
		return shortestDistance;
	}
};

// 我这个想法是每看到一个C，就分别向左向右走，生成距离，如果距离比原来的还短，就替换，否则结束。
// 其实可以直接从左向右走一遍生成距离，再从右向左走一遍，短的话就替换原来的距离
class Solution1 {
public:
	vector<int> shortestToChar(string S, char C) {
		int last = 0;
		vector<int> shortestDistance(S.size(), INT_MAX);
		for (int i = S.find(C); i != S.size(); ++i)		// 从第一个C开始
		{
			if (S[i] == C)
			{
				shortestDistance[i] = 0;
				for (int j = i - 1; j >= last; --j)
				{
					if (shortestDistance[j] > i - j)
						shortestDistance[j] = i - j;
					else
						break;
				}
				last = i;
			}
			else
			{
				shortestDistance[i] = i - last;
			}
		}
		return shortestDistance;
	}
};

int main()
{
	Solution s;
	auto ret = s.shortestToChar("loveleetcode", 'e');
	for (auto i : ret)
		cout << i << " ";
	return 0;
}