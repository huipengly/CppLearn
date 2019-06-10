#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0, right = numbers.size() - 1;
		vector<int> result;
		while (left < right)
		{
			if (numbers[left] + numbers[right] < target)
				++left;
			else if (numbers[left] + numbers[right] > target)
				--right;
			else 
			{
				if (left == 0 || numbers[left - 1] != numbers[left])
				{
					result.push_back(left + 1);
					result.push_back(right + 1);
				}
				++left;
				--right;
			}
		}
		return result;
	}
};