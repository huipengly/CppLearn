#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(const string& A, const string& B) {
        auto dp = findLengthDP(A, B);
        return dp[A.size() - 1][B.size() - 1];
    }
    vector<vector<int>> findLengthDP(const string &A, const string &B)
    {
        if (A.empty() || B.empty())
            return {};
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        dp[0][0] = (A[0] == B[0] ? 1 : 0);
        for (int i = 1; i != A.size(); ++i)
            dp[i][0] = std::max(dp[i - 1][0], A[i] == B[0] ? 1 : 0);
        for (int i = 1; i != B.size(); ++i)
            dp[0][i] = std::max(dp[0][i - 1], A[0] == B[i] ? 1 : 0);
        for (int i = 1; i != A.size(); ++i)
        {
            for (int j = 1; j != B.size(); ++j)
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                if (A[i] == B[j])
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
        return dp;
    }

    string lcse(const string &A, const string &B)
    {
        if (A.empty() || B.empty())
            return "";
        auto dp = findLengthDP(A, B);
        int m = A.size() - 1, n = B.size() - 1;
        int index = dp[m][n];
        string ret(index, 0);
        for (int i = index - 1; i >= 0; --i)
        {
            if (m > 0 && dp[m - 1][n] == dp[m][n])
            {
                --m;
            }
            else if (n > 0 && dp[m][n - 1] == dp[m][n])
            {
                --n;
            }
            else
            {
                ret[index--] = A[m];
                --m;
                --n;
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    string m, n;
    while (cin >> m >> n)
    {
        cout << s.findLength(m, n) << endl;
    }
    return 0;
}