#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// ø’º‰—πÀı
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.empty() || dungeon[0].empty())
			return -1;
		int rows = dungeon.size(), cols = dungeon[0].size();
		int more = max(rows, cols);
		int less = min(rows, cols);
		bool rowmore = more == rows;
		vector<int> dp(less);
		dp[less - 1] = dungeon.back().back() > 0 ? 1 : (-dungeon.back().back() + 1);
		for (int j = less - 2; j >= 0; --j)
		{
			int row = (rowmore ? more - 1 : j);
			int col = (rowmore ? j : more - 1);
			dp[j] = max(dp[j + 1] - dungeon[row][col], 1);
		}
		for (int i = more - 2; i >= 0; --i)
		{
			int row = (rowmore ? i : less - 1);
			int col = (rowmore ? less - 1 : i);
			dp[less - 1] = max(dp[less - 1] - dungeon[row][col], 1);
			for (int j = less - 2; j >= 0; --j)
			{
				int row = (rowmore ? i : j);
				int col = (rowmore ? j : i);
				int down = max(dp[j] - dungeon[row][col], 1);
				int right = max(dp[j + 1] - dungeon[row][col], 1);
				dp[j] = min(down, right);
			}
		}
		return dp[0];
	}
};

// dp
class Solution_dp {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.empty() || dungeon[0].empty())
			return -1;
		int rows = dungeon.size(), cols = dungeon[0].size();
		vector<vector<int>> dp(rows--, vector<int>(cols--));
		dp[rows][cols] = dungeon[rows][cols] > 0 ? 1 : (-dungeon[rows][cols] + 1);
		for (int i = rows - 1; i >= 0; --i)
			dp[i][cols] = max(dp[i + 1][cols] - dungeon[i][cols], 1);
		for (int j = cols - 1; j >= 0; --j)
			dp[rows][j] = max(dp[rows][j + 1] - dungeon[rows][j], 1);
		for (int i = rows - 1; i >= 0; --i)
		{
			for (int j = cols - 1; j >= 0; --j)
			{
				int down = max(dp[i + 1][j] - dungeon[i][j], 1);
				int right = max(dp[i][j + 1] - dungeon[i][j], 1);
				dp[i][j] = min(down, right);
			}
		}
		return dp[0][0];
	}
};

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.empty() || dungeon[0].empty())
			return -1;
		int rows = dungeon.size() - 1, cols = dungeon[0].size() - 1;
		vector<vector<int>> dp(rows, vector<int>(cols));
		dp[rows][cols] = dungeon[rows][cols] > 0 ? 1 : (-dungeon[rows][cols] + 1);
		for (int i = rows; i >= 0; --i)
			dp[i][0] = max(dp[i + 1][0] - dungeon[i][0], 1);
		for (int i = cols; i >= 0; ++i)
			dp[0][i] = max(dp[0][i + 1] - dungeon[0][i], 1);
		for (int i = rows - 1; i >= 0; --i)
		{
			for (int j = cols - 1; j >= 0; --j)
			{
				int down = max(dp[i + 1][j] - dungeon[i][j], 1);
				int right = max(dp[i][j + 1] - dungeon[i][j], 1);
				dp[i][j] = min(down, right);
			}
		}
		return dp[0][0];
	}
};

int main()
{
	vector<vector<int>> mat {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
	Solution s;
	cout << s.calculateMinimumHP(mat) << endl;
	return 0;
}