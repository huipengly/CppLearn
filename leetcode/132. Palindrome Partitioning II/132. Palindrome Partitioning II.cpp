#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	int minCut(string s) {
		if (s.empty())
			return 0;
		int size = s.size();
		vector<int> dp(size + 1, 2147483647);
		vector<vector<bool>> p(size, vector<bool>(size, false));
		dp[size] = -1;
		for (int i = size - 1; i >= 0; --i)
		{
			for (int j = i; j != size; ++j)
			{
				if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
				{
					p[i][j] = true;
					dp[i] = std::min(dp[i], 1 + dp[j + 1]);
				}
			}
		}
		return dp[0];
	}
};

int main()
{
	Solution s;
	cout << s.minCut("aab") << endl;
	return 0;
}