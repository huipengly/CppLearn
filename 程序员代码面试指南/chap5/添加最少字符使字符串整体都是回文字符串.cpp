#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 这里我是从右下角开始构造dp的
vector<vector<int>> getDP(const string& str)
{
	vector<vector<int>> dp(str.size(), vector<int>(str.size(), 0));
	for (int i = str.size() - 2; i >= 0; --i)
	{
		dp[i][i + 1] = str[i] == str[i + 1] ? 0 : 1;
		for (int j = i + 2; j != str.size(); ++j)
		{
			if (str[i] == str[j])
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = std::min(dp[i + 1][j], dp[i][j - 1]) + 1;
		}
	}
	return dp;
}

string getPalindrome(const string& str)
{
	if (str.size() < 2)
		return str;
	auto dp = getDP(str);
	int size = str.size();
	int r_size = size + dp[0][size - 1];
	string res(r_size, 0);
	int index = 0, i = 0, j = str.size() - 1;	// 我用了一个index表示在res应该填充的内容，书上直接用了lindex和rindex，我的方法每次都要减，而且写着麻烦
	while (i <= j)
	{
		if (str[i] == str[j])
		{
			res[index] = str[i++];
			res[r_size - index - 1] = str[j--];
		}
		else if (dp[i][j - 1] > dp[i + 1][j])
		{
			res[index] = str[i];
			res[r_size - index - 1] = str[i++];
		}
		else
		{
			res[index] = str[j];
			res[r_size - index - 1] = str[j--];
		}
		++index;
	}
	return res;
}

string getPalindrome(const string& str, const string& strlps)
{
	if (str.empty() || strlps.empty())
		return str;
	int r_size = 2 * str.size() - strlps.size();
	string res(r_size, 0);
	int l = 0, r = str.size() - 1, lps_index = 0, r_index = 0;
	while (l < r)
	{
		string addStr{};
		while (str[l] != strlps[lps_index])
		{
			addStr += str[l++];
		}
		while (str[r] != strlps[lps_index])
		{
			addStr += str[r--];
		}
		for (char c : addStr)
		{
			res[r_index] = c;
			res[r_size - r_index - 1] = c;
			++r_index;
		}
		++lps_index;
	}
	return res;
}

int main()
{
	cout << getPalindrome("") << endl;
	cout << getPalindrome("A1B21C") << endl;
	cout << getPalindrome("A1B21C", "121") << endl;
	return 0;
}