// 贪心算法交换，但是证明没看懂
// https://leetcode.com/problems/couples-holding-hands/discuss/113369/Formal-proof-of-the-optimality-of-greedy-algorithm

#include <vector>
using std::vector;
#include <algorithm>
using std::swap; using std::find_if;

class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		int min_swap = 0;
		for (int i = 0; i != row.size(); i += 2)
		{
			if (row[i] / 2 != row[i + 1] / 2)	// 两个不是couple
			{
				// 找到couple，并交换
				auto c1_it = row.begin() + i;
				auto c2_it = find_if(c1_it + 1, row.end(), [&row, &i](int c) { return row[i] / 2 == c / 2; });
				swap(row[i + 1], *c2_it);
				++min_swap;
			}
		}
		return min_swap;
	}
};

int main()
{
	Solution s;
	vector<int> row{ 0, 2, 1, 3 };
	auto ret = s.minSwapsCouples(row);
	return 0;
}