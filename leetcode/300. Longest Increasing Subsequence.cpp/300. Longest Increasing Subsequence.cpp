#include <algorithm>
#include <vector>
using namespace std;

// dp + binary_search time: O(NlogN) space: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        if (N < 2)
            return N;
        vector<int> dp(N);
        vector<int> ends(N);     // ends[i]，表示索引i长度的子串中，末尾最小的元素值。
        dp[0] = 1;
        ends[0] = nums[0];
        int right = 0;
        int lo = 0, hi = 0, mid = 0;
        for (int i = 1; i != N; ++i)
        {
            lo = 0;
            hi = right;
            while (lo <= hi)
            {
                mid = lo + (hi - lo) / 2;
                if (ends[mid] < nums[i])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            right = max(right, lo);
            ends[lo] = nums[i];
            dp[i] = lo + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// dp time: O(N^2) space: O(N)
class Solution_dp {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        if (N < 2)
            return N;
        vector<int> dp(N, 1);
        for (int i = 0; i != N; ++i)
        {
            for (int j = 0; j != i; ++j)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return (*max_element(dp.begin(), dp.end()));
    }
};

// 暴力递归
class Solution_brute_force {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int N = nums.size();
        int longest = 0;
        for (int i = 0; i != N; ++i)
            longest = max(longest, lengthOfLIS(nums, i));
        return longest;
    }

private:
    int lengthOfLIS(vector<int> &nums, int index)
    {
        if (index == 0)
            return 1;
        int longest = 0;
        for (int i = 0; i != index; ++i)
        {
            if (nums[i] < nums[index]) {
                longest = max(longest, lengthOfLIS(nums, i));
            }
        }
        return longest + 1;
    }
};

int main()
{
    vector<int> arr{-2, -1};
    Solution s;
    auto ret = s.lengthOfLIS(arr);
    return 0;
}