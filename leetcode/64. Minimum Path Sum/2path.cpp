#include <vector>
using namespace std;

// 第一遍走路径和最长的,然后将地图中走过的路径变为0.第二遍再走.两次加和就是最长的
class TwoPathSum{
public:
    int twoPassSum(vector<vector<int>> &grid)
    {
        return maxPathSum(grid) + maxPathSum(grid);
    }

private:
    int maxPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int width = grid[0].size();
        int height = grid.size();
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i != width; ++i)
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        for (int i = 1; i != height; ++i)
            dp[i][0] = grid[i][0] + dp[i - 1][0];

        for (int i = 1; i != height; ++i)
        {
            for (int j = 1; j != width; ++j)
            {
                dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int i = height - 1, j = width - 1;
        while (i > 0 && j > 0)
        {
            grid[i][j] = 0;
            if (dp[i][j - 1] > dp[i - 1][j])
                --j;
            else
                --i;
        }

        return dp[height - 1][width - 1];
    }
};