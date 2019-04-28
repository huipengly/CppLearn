#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int max = 1;
		unordered_map<int, int> map;
		for (int i = 0; i != nums.size(); ++i)
		{
			if (map.find(nums[i]) == map.end())
			{
				map[nums[i]] = 1;
				if (map.find(nums[i] - 1) != map.end())
					max = std::max(max, merge(map, nums[i] - 1, nums[i]));
				if (map.find(nums[i] + 1) != map.end())
					max = std::max(max, merge(map, nums[i], nums[i] + 1));
			}
		}
		return max;
	}
private:
	int merge(unordered_map<int, int>& map, int less, int more)
	{
		int left = less - map[less] + 1;
		int right = more + map[more] - 1;
		int lenth = right - left + 1;
		map[left] = lenth;
		map[right] = lenth;
		return lenth;
	}
};

int main()
{
	Solution s;
	vector<int> arr{ 0,3,7,2,5,8,4,6,0,1 };
	cout << s.longestConsecutive(arr) << endl;
	return 0;
}