// map零值初始化问题 https://www.zhihu.com/question/45196767

#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <vector>
using std::vector;
#include <map>
using std::map;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> map1;
		vector<int> result;
		for (auto i : nums1)
		{
			//if (map1.count(i) == 0)
			//{
			//	map1[i] = 0;
			//}
			++map1[i];
		}
		for (auto i : nums2)
		{
			//if (map1.count(i) == 0)
			//{
			//	map1[i] = 0;
			//}
			if (map1[i]-- > 0)
			{
				result.push_back(i);
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> v1{ 1, 2, 2, 1 }, v2{ 2, 2 };
	for (auto i : s.intersect(v1, v2))
	{
		cout << i << endl;
	}
	return 0;
}