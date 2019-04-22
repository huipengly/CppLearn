#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty())
            return 0;
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        int max = 0;
        if (A[0] == B[0])
        {
            dp[0][0] = 1;
            max = 1;
        }
        for (int i = 1; i != A.size(); ++i)
            dp[i][0] = A[i] == B[0] ? 1 : 0;
        for (int i = 1; i != B.size(); ++i)
            dp[0][i] = A[0] == B[i] ? 1 : 0;
        for (int i = 1; i != A.size(); ++i)
        {
            for (int j = 1; j != B.size(); ++j)
            {
                if (A[i] == B[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    max = std::max(dp[i][j], max);
                }
            }
        }
        return max;
    }
};

int main()
{
//    vector<int> A{1, 2, 3, 2, 1}, B{3, 2, 1, 4, 7};
    vector<int> A{0, 0, 0, 0}, B{0, 0, 0};
    Solution s;
    cout << s.findLength(A, B) << endl;
    return 0;
}