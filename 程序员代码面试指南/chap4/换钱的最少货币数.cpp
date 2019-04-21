#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

// 贪心不行，下面的代码是错的
int minCoinGreed(vector<int> &coins, int aim)
{
	if (coins.empty() || aim < 0)
		return -1;
	
	int counter = 0;
	sort(coins.begin(), coins.end(), std::greater<int>());
	for (auto coin : coins)
	{
		counter += aim / coin;
		aim %= coin;
	}
	return aim == 0 ? counter : -1;
}

// DP状态压缩
int minCoinDPCompress(const vector<int> &coins, int aim)
{
	if (coins.empty() || aim < 0)
		return -1;
	int N = coins.size();
	vector<int> dp(aim + 1, -1);

	dp[0] = 0;

	//int temp;
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = 0; j != aim + 1; ++j)
		{
			//temp = dp[j];
			// 这里dp赋值的过程解耦做的很好。先确定是否用temp，再决定dp[j - coins[i]]。
			// 我在dp里写的就没有书上这个好。
			//dp[j] = -1;
			//if (temp != -1)
			//	dp[j] = temp;
			if (j - coins[i] >= 0 && dp[j - coins[i]] != -1)
			{
				if (dp[j] == -1)
					dp[j] = dp[j - coins[i]] + 1;
				else
					dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
	}
	return dp[aim];
}

// DP
int minCoinDP(const vector<int> &coins, int aim)
{
	if (coins.empty() || aim < 0)
		return -1;
	int N = coins.size();
	vector<vector<int>> dp(N + 1, vector<int>(aim + 1, -1));	// 硬币数目使用N+1为了算第N行。

	dp.back()[0] = 0;

	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = 0; j != aim + 1; ++j)
		{
			if (j - coins[i] >= 0)
			{
				if (dp[i][j - coins[i]] == -1)
					dp[i][j] = (dp[i + 1][j] == -1 ? -1 : dp[i + 1][j]);
				else if (dp[i + 1][j] == -1)
					dp[i][j] = dp[i][j - coins[i]] + 1;
				else
					dp[i][j] = min(dp[i][j - coins[i]] + 1, dp[i + 1][j]);
			}
			else
				dp[i][j] = dp[i + 1][j];
		}
	}

	return dp[0][aim];
}

// 书上的限制硬币的暴力递归
int minCoin2(const vector<int> &coins, int aim, int index)
{
	if (aim == 0)
		return 0;
	else if (aim < 0)
		return -1;

	if (index >= coins.size())
		return -1;

	int min = -1;
	int num = 0;
	for (int i = 0; coins[index] * i <= aim; ++i)
	{
		num = minCoin2(coins, aim - coins[index] * i, index + 1);
		if (num != -1 && (min == -1 || (num + i) < min))
			min = num + i;
	}
	return min;
}

int minCoin2(const vector<int> &coins, int aim)
{
	if (coins.empty() || aim < 0)
		return -1;

	return minCoin2(coins, aim, 0);
}

// 暴力递归
int minCoinCore1(const vector<int> &coins, int aim)
{
	if (aim == 0)
		return 0;
	else if (aim < 0)
		return -1;

	int min = -1;
	int num = 0;
	for (int i = 0; i != coins.size(); ++i)
	{
		num = minCoinCore1(coins, aim - coins[i]);
		if (num != -1 && (min == -1 || num < min))
			min = num;
	}
	return (min == -1 ? -1 : (min + 1));
}

int minCoin1(const vector<int> &coins, int aim)
{
	if (coins.empty() || aim < 0)
		return -1;

	return minCoinCore1(coins, aim);
}

int main()
{
	vector<int> arr{ 5, 2, 3 };
	auto ret1 = minCoinDPCompress(arr, 4);
	auto ret2 = minCoinGreed(arr, 4);
	int i = 0;
	try {
		for (; i != 100; ++i)
			if (minCoinDP(arr, i) != minCoinDPCompress(arr, i))
				throw exception();
	}
	catch(exception){
		cerr << "error in " << i << endl;
	}
	return 0;
}