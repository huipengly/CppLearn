#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		return isValid(s, p) && isMatch(s, p, 0, 0);
	}
private:
	bool isValid(const string& s, const string& p)
	{
		for (char c : s)	// s里没有.*
		{
			if (c == '.' || c == '*')
				return false;
		}

		for (int i = 0; i != p.size(); ++i)		// p第一个不为*且不会出现连续的*
		{
			if (p[i] == '*' && (i == 0 || p[i - 1] == '*'))
				return false;
		}
		return true;
	}
	bool isMatch(const string& s, const string& p, int si, int pi)
	{
		if (pi == p.size())
			return si == s.size();

		if (pi + 1 == p.size() || p[pi + 1] != '*')
		{
			return si != s.size() && (s[si] == p[pi] || p[pi] == '.') && isMatch(s, p, si + 1, pi + 1);
		}

		if (s[si] == p[pi] || (p[pi] == '.' && si != s.size()))
			return isMatch(s, p, si + 1, pi + 2) || isMatch(s, p, si + 1, pi) || isMatch(s, p, si, pi + 2);
		else
			return isMatch(s, p, si, pi + 2);
	}
};

// 左神的递归实现方法，leetcode提交能快很多
class Solution2 {
public:
	bool isMatch(string s, string p) {
		return isValid(s, p) && isMatch(s, p, 0, 0);
	}
private:
	bool isValid(const string& s, const string& p)
	{
		for (char c : s)	// s里没有.*
		{
			if (c == '.' || c == '*')
				return false;
		}

		for (int i = 0; i != p.size(); ++i)		// p第一个不为*且不会出现连续的*
		{
			if (p[i] == '*' && (i == 0 || p[i - 1] == '*'))
				return false;
		}
		return true;
	}
	bool isMatch(const string& s, const string& p, int si, int pi)
	{
		if (pi == p.size())
			return si == s.size();

		if (pi + 1 == p.size() || p[pi + 1] != '*')
		{
			return si != s.size() && (s[si] == p[pi] || p[pi] == '.') && isMatch(s, p, si + 1, pi + 1);
		}

		while (si != s.size() && (s[si] == p[pi] || p[pi] == '.'))
		{
			if (isMatch(s, p, si, pi + 2))
				return true;
			++si;
		}
		return isMatch(s, p, si, pi + 2);
	}
};

class Solution3 {
public:
	bool isMatch(string s, string p) {
		if (!isValid(s, p))
			return false;
		auto dp = move(initDPMap(s, p));
		for (int i = s.size() - 1; i >= 0; --i)
		{
			for (int j = p.size() - 2; j >= 0; --j)
			{
				if (p[j + 1] != '*')
				{
					dp[i][j] = (s[i] == p[j] || p[j] == '.') && dp[i + 1][j + 1];
				}
				else
				{
					int si = i;
					while (si != s.size() && (s[si] == p[j] || p[j] == '.'))
					{
						if (dp[si][j + 2])
						{
							dp[i][j] = true;
							break;
						}
						++si;
					}
					if (!dp[i][j])
					{
						dp[i][j] = dp[si][j + 2];
					}
				}
			}
		}
		return dp[0][0];
	}
private:
	bool isValid(const string& s, const string& p)
	{
		for (char c : s)	// s里没有.*
		{
			if (c == '.' || c == '*')
				return false;
		}

		for (int i = 0; i != p.size(); ++i)		// p第一个不为*且不会出现连续的*
		{
			if (p[i] == '*' && (i == 0 || p[i - 1] == '*'))
				return false;
		}
		return true;
	}
	vector<vector<bool>> initDPMap(const string& s, const string& p)
	{
		int slen = s.size();
		int plen = p.size();
		vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
		dp[slen][plen] = true;
		for (int j = plen - 2; j >= 0; j -= 2)
		{
			if (p[j] != '*' && p[j + 1] == '*')
				dp[slen][j] = true;
			else
				break;
		}
		if (slen > 0 && plen > 0)
		{
			if (s[slen - 1] == p[plen - 1] || p[plen - 1] == '.')
				dp[slen - 1][plen - 1] = true;
		}
		return dp;
	}
};

int main()
{
	Solution3 s;
	cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("aa", "a*") << endl;
	cout << s.isMatch("ab", ".*") << endl;
	cout << s.isMatch("aab", "c*a*b") << endl;
	cout << s.isMatch("mississippi", "mis*is*p*.") << endl;
	cout << s.isMatch("ab", ".*c") << endl;
	return 0;
}