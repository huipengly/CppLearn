#include <vector>
using std::vector;
#include <algorithm>
using std::max;

// ֻҪ֮ǰ���Ӵ���Ϊ������ô�ټ���һλ�Ϳ϶����ں���һλ

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = 0, max_num = -1e10;
		for (auto num : nums)
		{
			sum = num + (sum > 0 ? sum : 0);
			max_num = max(max_num, sum);
		}
		return max_num;
	}
};

int main()
{
	Solution s;
	vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
	auto ret = s.maxSubArray(nums);
	return 0;
}