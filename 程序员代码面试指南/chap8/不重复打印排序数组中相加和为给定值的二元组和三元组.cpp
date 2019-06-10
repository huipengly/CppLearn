#include <vector>
#include "不重复打印排序数组中相加和为给定值的二元组和三元组.h"
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(const vector<int>& numbers, int target)
	{
		return twoSum(numbers, target, 0, numbers.size() - 1);
	}
	vector<int> twoSum(const vector<int>& numbers, int target, int left, int right) {
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

	vector<int> threeSum(const vector<int>& numbers, int target)
	{
		vector<int> result;
		for (int i = 0; i != numbers.size() - 2; ++i)
		{
			if (i == 0 || numbers[i - 1] != numbers[i])
			{
				auto ret = twoSum(numbers, target - numbers[i], i + 1, numbers.size() - 1);
				if (!ret.empty())
				{
					for (int j = 0; j != ret.size(); ++j)
					{
						if (j % 2 == 0)
							result.push_back(i + 1);
						result.push_back(ret[j]);
					}
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> arr = { -8, -4, -3, 0, 1, 2, 4, 5, 8, 9 };
	auto ret1 = s.twoSum(arr, 10);
	auto ret2 = s.threeSum(arr, 10);
	cout << "two sum result" << endl;
	for (int i = 0; i < ret1.size(); i += 2)
	{
		cout << arr[ret1[i] - 1] << "," << arr[ret1[i + 1] - 1] << endl;
	}
	cout << "three sum result" << endl;
	for (int i = 0; i < ret2.size(); i += 3)
	{
		cout << arr[ret2[i] - 1] << "," << arr[ret2[i + 1] - 1] << "," << arr[ret2[i + 2] - 1] << endl;
	}
	return 0;
}
