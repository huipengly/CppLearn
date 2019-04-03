#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// 书上还有一个用辅助数组记录上次出现位置的代码。


string longest_substring_without_duplication(const string& str)
{
	if (str.empty())
		return str;
	vector<int> dp(str.size(), 0);
	dp[0] = 1;
	for (int i = 1; i != dp.size(); ++i)
	{
		int d = 1;
		for (; i - d >= 0 && d <= dp[i - 1]; ++d)
		{
			if (str[i] == str[i - d])
			{
				dp[i] = d;
				break;
			}
		}
		if (d > dp[i - 1])
		{
			dp[i] = dp[i - 1] + 1;
		}
		
	}
	return str.substr(str.size() - dp.back());
}

int main()
{
	assert(longest_substring_without_duplication(string{ "" }) == "");
	assert(longest_substring_without_duplication(string{ "aaaaaa" }) == "a");
	assert(longest_substring_without_duplication(string{ "abc" }) == "abc");
	assert(longest_substring_without_duplication(string{ "aba" }) == "ba");
	assert(longest_substring_without_duplication(string{ "ababcacfr" }) == "acfr");
	return 0;
}