#include <algorithm>
#include <vector>
using namespace std;

// DP，空间压缩
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;
		int col = grid[0].size();
		int row = grid.size();
		int more = max(col, row);
		int less = min(col, row);
		bool row_more = more == row;
		vector<int> arr(less, 0);
		arr[0] = grid[0][0];
		for (int i = 1; i != less; ++i)
			arr[i] = arr[i - 1] + (row_more ? grid[0][i] : grid[i][0]);

		for (int i = 1; i != more; ++i)
		{
			arr[0] += row_more ? grid[i][0] : grid[0][i];
			for (int j = 1; j != less; ++j)
			{
				arr[j] = min(arr[j - 1], arr[j]) + (row_more ? grid[i][j] : grid[j][i]);
			}
		}

		return arr[less - 1];
	}
};

//// DP，正向想
//class Solution {
//public:
//	int minPathSum(vector<vector<int>>& grid) {
//		if (grid.empty() || grid[0].empty())
//			return 0;
//		int width = grid[0].size();
//		int height = grid.size();
//		vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
//		dp[0][0] = grid[0][0];
//		for (int i = 1; i != width; ++i)
//			dp[0][i] = grid[0][i] + dp[0][i - 1];
//		for (int i = 1; i != height; ++i)
//			dp[i][0] = grid[i][0] + dp[i - 1][0];
//
//		for (int i = 1; i != height; ++i)
//		{
//			for (int j = 1; j != width; ++j)
//				dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
//		}
//
//		return dp[height - 1][width - 1];
//	}
//};

// DP，反向想的。要处理许多矩阵有问题，这个没处理好
//class Solution {
//public:
//	int minPathSum(vector<vector<int>>& grid) {
//		if (grid.empty() || grid[0].empty())
//			return 0;
//		int width = grid[0].size();
//		int height = grid.size();
//		vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
//		dp[height - 1][width - 1] = grid[height - 1][width - 1];
//
//		int i = height - 1;
//		int j = width - 2;
//		for (; j >= 0; --j)
//			dp[i][j] = grid[i][j] + dp[i][j + 1];
//		for (i = height - 2, j = width - 1; i >= 0; --i)
//			dp[i][j] = grid[i][j] + dp[i + 1][j];
//
//		for (int m = 2; width - m > 0 && height - m > 0; ++m)
//		{
//			dp[width - m][height - m] = grid[width - m][height - m] + min(dp[width - m][height - m + 1], dp[width - m + 1][height - m]);
//			for (i = height - m, j = width - m - 1; j >= 0; --j)
//				dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
//			for (i = height - m - 1, j = width - m; i >= 0; --i)
//				dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
//		}
//		dp[0][0] = grid[0][0] + min(dp[0][1], dp[1][0]);
//
//		return dp[0][0];
//	}
//};

int main()
{
	Solution s;
	vector<vector<int>> mat = { {1, 2, 5}, { 3, 2, 1 } };
	auto ret = s.minPathSum(mat);
	return 0;
}