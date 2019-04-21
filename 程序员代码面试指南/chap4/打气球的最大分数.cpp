#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

// DP
int max_point_dp(const vector<int> &arr)
{
	if (arr.empty())
		return 0;
	int N = arr.size();
	if (N == 1)
		return arr[0];
	vector<int> help(N + 2, 1);
	for (int i = 0; i != N; ++i)
		help[i + 1] = arr[i];

	vector<vector<int>> dp(help.size(), vector<int>(help.size(), -1));
	for (int i = 1; i <= N; ++i)
		dp[i][i] = help[i - 1] * help[i] * help[i + 1];

	for (int l = N - 1; l >= 1; --l)
	{
		for (int r = l + 1; r <= N; ++r)
		{
			dp[l][r] = max(
				help[l - 1] * help[l] * help[r + 1] + dp[l + 1][r],
				help[l - 1] * help[r] * help[r + 1] + dp[l][r - 1]);
			for (int i = l + 1; i < r; ++i)
			{
				dp[l][r] = max(
					dp[l][r],
					dp[l][i - 1] + dp[i + 1][r] + help[l - 1] * help[i] * help[r + 1]);
			}
		}
	}
	return dp[1][N];
}

// 书上的暴力递归法
int max_point2(const vector<int> &arr, int l, int r)
{
	if (l == r)
		return arr[l - 1] * arr[l] * arr[r + 1];
	if (l > r)		// 我的代码这里出现了超范围索引，这个不利于改动态规划。
		return 0;

	int max = 0;
	for (int i = l; i <= r; ++i)
	{
		max = std::max(max,
			max_point2(arr, l, i - 1) + max_point2(arr, i + 1, r) + arr[l - 1] * arr[i] * arr[r + 1]);
	}
	return max;
}

int max_point2(const vector<int> &arr)
{
	if (arr.empty())
		return 0;
	vector<int> help(arr.size() + 2, 0);
	help[0] = 1;
	help.back() = 1;
	for (int i = 0; i != arr.size(); ++i)
		help[i + 1] = arr[i];
	return max_point2(help, 1, arr.size());
}

// 暴力递归
int shoot_point(const vector<int> &arr, const vector<bool> &mark, int index)
{
	int point = arr[index];
	for (int i = index - 1; i >= 0; --i)
	{
		if (!mark[i])
		{
			point *= arr[i];
			break;
		}
	}

	for (int i = index + 1; i < arr.size(); ++i)
	{
		if (!mark[i])
		{
			point *= arr[i];
			break;
		}
	}
	return point;
}

int max_point(const vector<int> &arr, vector<bool> &mark, int shooted)
{
	if (arr.size() == shooted)
		return 0;

	int point = 0;
	int max = 0;
	for (int i = 0; i != arr.size(); ++i)
	{
		if (!mark[i])
		{
			mark[i] = true;
			point = shoot_point(arr, mark, i) + max_point(arr, mark, shooted + 1);
			if (point > max)
				max = point;
			mark[i] = false;
		}
	}
	return max;
}

int max_point(const vector<int> &arr)
{
	if (arr.empty())
		return 0;
	vector<bool> mark(arr.size(), false);
	return max_point(arr, mark, 0);
}

int main()
{
	vector<int> arr{ 3, 2, 5 };
	auto ret = max_point2(arr);
	assert(max_point_dp(arr) == 50);
	return 0;
}