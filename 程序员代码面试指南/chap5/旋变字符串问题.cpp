#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.empty() && s2.empty())
			return true;
		if (s1.empty() || s2.empty())
			return false;
		if (s1 == s2)
			return true;
		if (!sameTypeSameNumber(s1, s2))
			return false;

		int N = s1.size();
		vector<vector<vector<bool>>> dp(N, vector<vector<bool>>(N, vector<bool>(N + 1, false)));
		for (int L1 = 0; L1 != N; ++L1)
		{
			for (int L2 = 0; L2 != N; ++L2)
			{
				dp[L1][L2][1] = s1[L1] == s2[L2];
			}
		}

		for (int size = 2; size <= N; ++size)
		{
			for (int L1 = 0; L1 <= N - size; ++L1)
			{
				for (int L2 = 0; L2 <= N - size; ++L2)
				{
					for (int leftPart = 1; leftPart < size; ++leftPart)
					{
						if ((dp[L1][L2][leftPart] && dp[L1 + leftPart][L2 + leftPart][size - leftPart]) ||
							(dp[L1][L2 + size - leftPart][leftPart] && dp[L1 + leftPart][L2][size - leftPart]))
						{
							dp[L1][L2][size] = true;
							break;
						}
					}
				}
			}
		}
		return dp[0][0][N];
	}
private:
	bool sameTypeSameNumber(const string & s1, const string & s2)
	{
		vector<int> map(256, 0);
		for (auto c : s1)
			++map[c];
		for (auto c : s2)
		{
			if (--map[c] < 0)
				return false;
		}
		return true;
	}
};

class Solution_recursive {
public:
	bool isScramble(string s1, string s2) {
		if (s1.empty() && s2.empty())
			return true;
		if (s1.empty() || s2.empty())
			return false;
		if (s1 == s2)
			return true;
		if (!sameTypeSameNumber(s1, s2))
			return false;

		return process(s1, s2, 0, 0, s1.size());
	}
private:
	bool sameTypeSameNumber(const string& s1, const string& s2)
	{
		vector<int> map(256, 0);
		for (auto c : s1)
			++map[c];
		for (auto c : s2)
		{
			if (--map[c] < 0)
				return false;
		}
		return true;
	}
	bool process(const string& str1, const string& str2, int L1, int L2, int size)
	{
		if (size == 1)
			return str1[L1] == str2[L2];

		for (int leftPart = 1; leftPart < size; ++leftPart)
		{
			if ((process(str1, str2, L1, L2, leftPart) && process(str1, str2, L1 + leftPart, L2 + leftPart, size - leftPart)) ||
				(process(str1, str2, L1, L2 + size - leftPart, leftPart) && process(str1, str2, L1 + leftPart, L2, size - leftPart)))
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	cout << s.isScramble("great", "rgeat") << endl;
	cout << s.isScramble("abcde", "caebd") << endl;
	cout << s.isScramble("a", "a") << endl;
	cout << s.isScramble("ccabcbabcbabbbbcbb", "bbbbabccccbbbabcba") << endl;
	return 0;
}