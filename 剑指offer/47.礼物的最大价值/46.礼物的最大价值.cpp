#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max_gift_value2(const vector<vector<int>> &gifts)
{
	if (gifts.empty() || gifts[0].empty())
		return 0;
	int m = gifts.size();
	int n = gifts[0].size();
	vector<int> dp(n, 0);					// 由于用不到更多的行，所以优化存储

	dp[n - 1] = gifts[m - 1][n - 1];

	for (int i = m - 1; i >= 0; --i)
	{
		dp[n - 1] = gifts[i][n - 1];
		for (int j = n - 2; j >= 0; --j)
		{
			dp[j] = gifts[i][j] + std::max(dp[j], dp[j + 1]);
		}
	}

	return dp[0];
}

int max_gift_value(const vector<vector<int>> &gifts)
{
	if (gifts.empty() || gifts[0].empty())
		return 0;
	int m = gifts.size();
	int n = gifts[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));		// 记录从i, j出发最大的礼物

	dp[m - 1][n - 1] = gifts[m - 1][n - 1];
	for (int i = m - 2; i >= 0; --i)
	{
		dp[i][n - 1] = gifts[i][n - 1] + dp[i + 1][n - 1];
	}
	for (int j = n - 2; j >= 0; --j)
	{
		dp[m - 1][j] = gifts[m - 1][j] + dp[m - 1][j + 1];
	}
	
	for (int i = m - 2; i >= 0; --i)
	{
		for (int j = n - 2; j >= 0; --j)
		{
			dp[i][j] = gifts[i][j] + std::max(dp[i + 1][j], dp[i][j + 1]);
		}
	}

	return dp[0][0];
}

int main()
{
	cout << max_gift_value2({ {1, 10, 3, 8}, {12, 2, 9, 6}, {5, 7, 4, 11}, {3, 7, 16, 5} }) << endl;
	//cout << max_gift_value({ {} }) << endl;
	return 0;
}