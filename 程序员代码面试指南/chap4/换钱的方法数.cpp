#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

// DP 空间压缩
int number_of_methods_dp_compress(const vector<int> &coins, int aim)
{
	if (coins.empty() || aim <= 0)
		return 0;

	int N = coins.size();
	vector<int> dp(aim + 1, 0);
	dp[0] = 1;

	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = 0; j <= aim; ++j)
		{
			if (j - coins[i] >= 0)
				dp[j] += dp[j - coins[i]];
		}
	}

	return dp[aim];
}

// DP
int number_of_methods_dp(const vector<int> &coins, int aim)
{
	if (coins.empty() || aim <= 0)
		return 0;

	int N = coins.size();
	vector<vector<int>> dp(N + 1, vector<int>(aim + 1, 0));
	dp.back()[0] = 1;

	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = 0; j <= aim; ++j)
		{
			dp[i][j] += dp[i + 1][j];
			if (j - coins[i] >= 0)
				dp[i][j] += dp[i][j - coins[i]];
		}
	}

	return dp[0][aim];
}

// 记忆搜索
int number_of_methods_memory(const vector<int> &coins, int aim, int index, vector<vector<int>> &map)
{
	if (aim == 0)
		return 1;
	else if (aim < 0)
		return 0;

	if (index >= coins.size())
		return 0;

	int numbers = 0;
	for (int i = 0; coins[index] * i <= aim; ++i)
	{
		int &map_value = map[index + 1][aim - coins[index] * i];
		if (map_value == -1)
			map_value = number_of_methods_memory(coins, aim - coins[index] * i, index + 1, map);
		numbers += map_value;
	}

	return numbers;
}

int number_of_methods_memory(const vector<int> &coins, int aim)
{
	if (coins.empty() || aim <= 0)
		return 0;

	vector<vector<int>> map(coins.size() + 1, vector<int>(aim + 1, -1));	// -1是未搜索

	return number_of_methods_memory(coins, aim, 0, map);
}

// 暴力递归
int number_of_methods(const vector<int> &coins, int aim, int index)
{
	if (aim == 0)
		return 1;
	else if (aim < 0)
		return 0;

	if (index >= coins.size())
		return 0;

	int numbers = 0;
	for (int i = 0; coins[index] * i <= aim; ++i)
		numbers += number_of_methods(coins, aim - coins[index] * i, index + 1);

	return numbers;
}

int number_of_methods(const vector<int> &coins, int aim)
{
	if (coins.empty() || aim <= 0)
		return 0;

	return number_of_methods(coins, aim, 0);
}

int main()
{
	vector<int> arr{ 5, 10, 25, 1 };
	assert(number_of_methods_dp(arr, 15) == 6);
	for (int i = 0; i != 100; ++i)
		assert(number_of_methods_dp_compress(arr, i) == number_of_methods_memory(arr, i));
	return 0;
}