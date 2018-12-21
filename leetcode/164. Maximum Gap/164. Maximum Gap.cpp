#include <vector>
using std::vector;
#include <algorithm>
using std::sort; using std::max; using std::max_element;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() <= 1)
		{
			return 0;
		}
		int maxVal = *max_element(nums.cbegin(), nums.cend());
		int exp = 1;
		const int radix = 10;

		// radix 排序32位十进制数
		while (maxVal / exp > 0)
		{
			int count[radix + 1] = { 0 };
			vector<int> aux(nums.size());

			for (auto num : nums)
				++count[num / exp % 10 + 1];

			for (int i = 0; i != radix; ++i)
				count[i + 1] += count[i];

			for (auto num : nums)
				aux[count[num / exp % 10]++] = num;

			nums = aux;
			exp *= 10;
		}

		int maxGap = 0;
		for (int i = 0; i != nums.size() - 1; ++i)
		{
			maxGap = max(nums[i + 1] - nums[i], maxGap);
		}
		return maxGap;
	}
};

int main()
{
	Solution s;
	vector<int> ivec{ 3, 6, 9, 1 };
	s.maximumGap(ivec);
	return 0;
}