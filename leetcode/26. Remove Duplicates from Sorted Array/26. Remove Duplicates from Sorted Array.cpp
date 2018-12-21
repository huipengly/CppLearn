#include <vector>
using std::vector;

class Solution1 {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int count = 1, num = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] != num)
			{
				num = nums[i];
				std::swap(nums[count], nums[i]);
				++count;
			}
		}
		return count;
	}
};

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int i = 0;
		for (int j = 1; j != nums.size(); ++j)
		{
			if (nums[i] != nums[j])
			{
				++i;
				nums[i] = nums[j];
			}
		}
		return i + 1;
	}
};

int main()
{
	Solution s;
	vector<int> nums{ 1, 1, 2 };
	auto ret = s.removeDuplicates(nums);

	return 0;
}