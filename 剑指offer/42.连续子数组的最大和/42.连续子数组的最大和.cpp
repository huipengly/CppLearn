#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		vector<int> dp(array.size(), 0);
		for (int i = 0; i != array.size(); ++i)
		{
			if (i == 0 || dp[i - 1] < 0)
				dp[i] = array[i];
			else
				dp[i] = dp[i - 1] + array[i];
		}
		return *max_element(dp.begin(), dp.end());
	}
};