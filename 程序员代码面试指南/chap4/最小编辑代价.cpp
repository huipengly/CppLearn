#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// O(1)的swap
template<typename T>
void swap(T &lhs, T &rhs)
{
	T temp = std::move(lhs);
	lhs = std::move(rhs);
	rhs = std::move(temp);
}

class MinCost {
public:
	int findMinCost(string A, int n, string B, int m, int ic, int dc, int rc) {
		// 始终是长字符串编辑成短字符串。但是交换之后，插入和删除的代价需要呼唤
		if (n < m)
		{
			::swap(A, B);
			::swap(n, m);
			::swap(ic, dc);
		}

		vector<int> dp(m + 1, 0);
		for (int i = 1; i != m + 1; ++i)
			dp[i] = ic * i;
		for (int i = 1; i != n + 1; ++i)
		{
			int pre = dp[0];
			dp[0] = dc * i;
			for (int j = 1; j != m + 1; ++j)
			{
				int cost = 0;
				if (A[i - 1] == B[j - 1])
					cost = pre;
				else
					cost = pre + rc;
				cost = std::min(std::min(cost, dp[j - 1] + ic), dp[j] + dc);
				pre = dp[j];
				dp[j] = cost;
			}
		}
		return dp.back();
	}
};

// 动态规划
class MinCost_dp {
public:
	int findMinCost(string A, int n, string B, int m, int ic, int dc, int rc) {
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i != n + 1; ++i)
			dp[i][0] = dc * i;
		for (int i = 1; i != m + 1; ++i)
			dp[0][i] = ic * i;

		for (int i = 1; i != n + 1; ++i)
		{
			for (int j = 1; j != m + 1; ++j)
			{
				if (A[i - 1] == B[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i - 1][j - 1] + rc;

				dp[i][j] = std::min(std::min(dp[i][j], dp[i - 1][j] + dc), 
									dp[i][j - 1] + ic);
			}
		}
		return dp.back().back();
	}
};

int main()
{
	MinCost m;
	cout << m.findMinCost("ab12cd3", 7, "abcdf", 5, 5, 3, 2) << endl;
	return 0;
}