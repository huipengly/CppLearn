#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLength(const string &lhs, const string &rhs)
    {
        if (lhs.empty() || rhs.empty())
            return 0;
        auto dp = findLengthDP(lhs, rhs);
        int max = 0;
        for (int i = 0; i != dp.size(); ++i)
            max = std::max(max, *max_element(dp[i].begin(), dp[i].end()));
        return max;
    }

    // time: O(M * N) space: O(M * N)
    string lcst1(const string &lhs, const string &rhs)
    {
        if (lhs.empty() || rhs.empty())
            return "";
        auto dp = findLengthDP(lhs, rhs);
        int max = 0, end = 0;
        for (int i = 0; i != dp.size(); ++i)
        {
            for (int j = 0; j != dp[0].size(); ++j)
            {
                if (dp[i][j] > max)
                {
                    max = dp[i][j];
                    end = i;
                }
            }
        }
        return lhs.substr(end - max + 1, max);
    }

    // time: O(M * N) space: O(1)
    string lcst2(const string &lhs, const string &rhs)
    {
        if (lhs.empty() || rhs.empty())
            return "";
        int m = lhs.size() - 1, n = rhs.size() - 1;
        int max = 0, end = 0;
        int row = 0, col = n;
        while (row <= m)
        {
            int i = row, j = col;
            int len = 0;
            while (i <= m && j <= n)
            {
                if (lhs[i] == rhs[j])
                    ++len;
                else
                    len = 0;
                if (len > max)
                {
                    max = len;
                    end = i;
                }
                ++i, ++j;
            }
            if (col > 0)
                --col;
            else
                ++row;
        }
        return lhs.substr(end - max + 1, max);
    }
private:
    vector<vector<int>> findLengthDP(const string &lhs, const string &rhs) {
        if (lhs.empty() || rhs.empty())
            return {};
        vector<vector<int>> dp(lhs.size(), vector<int>(rhs.size(), 0));
        dp[0][0] = lhs[0] == rhs[0] ? 1 : 0;
        for (int i = 1; i != lhs.size(); ++i)
            dp[i][0] = lhs[i] == rhs[0] ? 1 : 0;
        for (int i = 1; i != rhs.size(); ++i)
            dp[0][i] = lhs[0] == rhs[i] ? 1 : 0;
        for (int i = 1; i != lhs.size(); ++i)
        {
            for (int j = 1; j != rhs.size(); ++j)
            {
                if (lhs[i] == rhs[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
        return dp;
    }
};

int main()
{
    Solution s;
    string A{"A1234B"}, B{"CD1234"};
    cout << s.lcst2(A, B) << endl;
    return 0;
}
