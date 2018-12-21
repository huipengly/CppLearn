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
		int low = 0, mid = citations.size() / 2, high = citations.size();
		auto size = citations.size();
		while (low < high)
		{
			if (mid >= citations[size - 1 - mid])
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}
			mid = (low + high) / 2;
		}

		return low;
	}
};

int main()
{
	Solution s;
	vector<int> vec{ 0, 0 };
	auto a = s.hIndex(vec);
	return 0;
}