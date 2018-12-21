#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.empty())
		{
			return 0;
		}
		sort(citations.rbegin(), citations.rend());
		int i;
		for (i = 0; i != citations.size(); ++i)
		{
			if (i >= citations[i])
			{
				return i;
			}
			if (citations[i] == i) break;		// 如果相等的话，
		}
		return i;
	}
};

int main()
{
	Solution s;
	vector<int> vec{3,0,6,1,5 };
	auto a = s.hIndex(vec);
	return 0;
}