#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

// leetcode ÄÜ·ñÌø³ö
class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int cur = 0, next = 0;
		for (int i = 0; i != nums.size(); ++i)
		{
			if (cur < i)
			{
				cur = next;
			}
			if (nums[i] == 0 && i + nums[i] == next)
				return false;
			next = std::max(i + nums[i], next);
		}
		return true;
	}
};

class Solution_2 {
public:
	int minJump(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		int cur = 0, jump = 0, next = 0;
		for (int i = 0; i != nums.size(); ++i)
		{
			if (cur < i)
			{
				++jump;
				cur = next;
			}
			next = std::max(i + nums[i], next);
		}
		return jump;
	}
};

// O(N^2)
class Solution_1 {
public:
	int minJump(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int n = nums.size();
		vector<int> dp(n, numeric_limits<int>::max());
		dp[0] = 0;
		for (int i = 0; i != nums.size(); ++i)
		{
			for (int j = 1; i >= j; ++j)
			{
				if (nums[i - j] >= j)
					dp[i] = std::min(dp[i], 1 + dp[i - j]);
			}
		}
		return dp[n - 1];
	}
};

int main()
{
	Solution s;
	vector<int> arr{ 3, 2, 3, 1, 1, 4 };
	cout << s.minJump(arr) << endl;
	return 0;
}