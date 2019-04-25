#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 动态压缩 time: O(N + M) space: O(min{N, M})
class Mixture {
public:
	bool chkMixture(string A, int n, string B, int m, string C, int v) {
		if (m + n != v)
			return false;
		if (m > n)	// 始终保持B/m是短的
		{
			std::swap(A, B);
			std::swap(n, m);
		}
		vector<bool> dp(m + 1, false);
		dp[0] = true;
		for (int i = 1; i != m + 1; ++i)
			dp[i] = dp[i - 1] && (B[i - 1] == C[i - 1]);
		for (int i = 1; i != n + 1; ++i)
		{
			dp[0] = dp[0] && (A[i - 1] == C[i - 1]);
			for (int j = 1; j != m + 1; ++j)
			{
				dp[j] = (dp[j] && (A[i - 1] == C[i + j - 1])) ||
					(dp[j - 1] && (B[j - 1] == C[i + j - 1]));
			}
		}
		return dp.back();
	}
private:
	template <typename T>
	void swap(T& lhs, T& rhs)
	{
		T temp = std::move(lhs);
		lhs = std::move(rhs);
		rhs = std::move(temp);
	}
};

// dp time: O(N + M) space: O(N + M)
class Mixture_dp {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) {
		if (m + n != v)
			return false;
		vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
		dp[0][0] = true;
		for (int i = 1; i != n + 1; ++i)
			dp[i][0] = dp[i - 1][0] && (A[i - 1] == C[i - 1]);
		for (int i = 1; i != m + 1; ++i)
			dp[0][i] = dp[0][i - 1] && (B[i - 1] == C[i - 1]);
		for (int i = 1; i != n + 1; ++i)
		{
			for (int j = 1; j != m + 1; ++j)
			{
				dp[i][j] = dp[i - 1][j] && (A[i - 1] == C[i + j - 1]) ||
					dp[i][j - 1] && (B[j - 1] == C[i + j - 1]);
			}
		}
		return dp.back().back();
    }
};

int main()
{
	Mixture s;
	cout << s.chkMixture("ABC", 3, "12C", 3, "A12BCC", 6) << endl;;

    return 0;
}