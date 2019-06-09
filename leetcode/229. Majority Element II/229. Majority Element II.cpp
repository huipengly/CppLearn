#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

// 对于n/3这种特例，可以直接定义变量，不用map
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int candidate1 = 0, times1 = 0, candidate2 = 1, times2 = 0;
		for (int num : nums)
		{
			if (candidate1 == num)
				++times1;
			else if (candidate2 == num)
				++times2;
			else if (times1 == 0)
			{
				candidate1 = num;
				times1 = 1;
			}
			else if (times2 == 0)
			{
				candidate2 = num;
				times2 = 1;
			}
			else
			{
				--times1;
				--times2;
			}
		}
		times1 = 0;
		times2 = 0;
		for (int num : nums)
		{
			if (num == candidate1)
				++times1;
			if (num == candidate2)
				++times2;
		}
		vector<int> res;
		if (times1 > nums.size() / 3)
			res.push_back(candidate1);
		if (times2 > nums.size() / 3)
			res.push_back(candidate2);
		return res;
	}
};