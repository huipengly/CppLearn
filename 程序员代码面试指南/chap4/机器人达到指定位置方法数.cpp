#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// 空间压缩
int walkDP_compress(int N, int M, int K, int P)
{
	if (N < 2 || K < 1 || M < 1 || M > N || P < 1 || P > N)
		return 0;

	vector<int> dp(N, 0);

	dp[P - 1] = 1;

	int left = 0;	// 当前点上一行左侧
	int temp = 0;
	for (int i = 1; i != K + 1; ++i)	// 还是两层循环
	{
		for (int j = 0; j != N; ++j)
		{
			temp = dp[j];
			if (j == 0)
				dp[j] = dp[j + 1];
			else if (j == N - 1)
				dp[j] = left;
			else
				dp[j] = left + dp[j + 1];
			left = temp;
		}
	}

	return dp[M - 1];
}

// 暴力递归改dp
int walkDP(int N, int M, int K, int P)
{
	if (N < 2 || K < 1 || M < 1 || M > N || P < 1 || P > N)
		return 0;

	vector<vector<int>> dp(K + 1, vector<int>(N, 0));	// 从M点走K步，有效道路

	dp[0][P - 1] = 1;

	for (int i = 1; i != K + 1; ++i)
	{
		for (int j = 0; j != N; ++j)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == N - 1)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
		}
	}

	return dp[K][M - 1];
}

// 暴力递归法
int walkCore(int N, int pos, int rest, int P)
{
	int counter = 0;
	if (rest == 0)
		return (pos == P ? 1 : 0);

	if (pos - 1 > 0)
		counter += walkCore(N, pos - 1, rest - 1, P);
	if (pos + 1 <= N)
		counter += walkCore(N, pos + 1, rest - 1, P);
	return counter;
}

int walk(int N, int M, int K, int P)
{
	if (N < 2 || K < 1 || M < 1 || M > N || P < 1 || P > N)
		return 0;

	return walkCore(N, M, K, P);
}

int main()
{
	assert(walkDP_compress(5, 2, 3, 3) == 3);
	assert(walkDP_compress(3, 1, 3, 3) == 0);
	return 0;
}