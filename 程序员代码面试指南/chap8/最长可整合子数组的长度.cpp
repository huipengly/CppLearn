#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// 牛客测试
// https://www.nowcoder.com/questionTerminal/0da19cbd75ed45dcaa59261c9d15a5d6

class Solution {
public:
	/**
	 *	在数组中求长度最大的可整合子数组长度
	 *	arr：输入数组
	 *	返回：最大的可整合子数组的长度
	 */
	// 牛客这里蜜汁多了个int len参数
	int getMaxLength1(vector<int> arr, int) {
		int max = 0;
		for (int i = 0; i != arr.size(); ++i)
		{
			for (int j = i; j != arr.size(); ++j)
			{
				if (isInterged(vector<int>(arr.begin() + i, arr.begin() + j + 1)))
				{
					max = std::max(max, j - i + 1);
				}
			}
		}
		return max;
	}

	int getMaxLength2(vector<int> arr, int) {
		int max = 0, min = 0, len = 0;
		unordered_set<int> set;
		for (int i = 0; i != arr.size(); ++i)
		{
			min = INT_MAX;
			max = INT_MIN;
			for (int j = i; j != arr.size(); ++j)
			{
				if (set.find(arr[j]) != set.end())
					break;
				set.insert(arr[j]);
				min = std::min(min, arr[j]);
				max = std::max(max, arr[j]);
				if (max - min == j - i)
					len = std::max(len, j - i + 1);
			}
			set.clear();
		}
		return len;
	}
private:
	bool isInterged(vector<int> arr)
	{
		sort(arr.begin(), arr.end());
		for (int i = 1; i != arr.size(); ++i)
		{
			if (arr[i] - arr[i - 1] != 1)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	s.getMaxLength1({ 5, 5, 3, 2, 6, 4, 3 }, 0);
	return 0;
}