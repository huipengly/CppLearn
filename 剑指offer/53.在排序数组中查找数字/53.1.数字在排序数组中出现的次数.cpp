#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		auto first = firstK(data, k);
		if (first == -1)
			return 0;
		auto last = lastK(data, k);

		return last - first + 1;
	}
private:
	int firstK(const vector<int> &data, int val)
	{
		int lo = 0, hi = data.size() - 1, mid;
		bool got_val = false;
		while (lo <= hi)
		{
			mid = lo + (hi - lo) / 2;
			if (data[mid] < val)
			{
				lo = mid + 1;
			}
			else if (data[mid] > val)
			{
				hi = mid - 1;
			}
			else if (mid == 0 || data[mid - 1] != val)
			{
				return mid;
			}
			else
			{
				hi = mid - 1;
			}
		}
		return -1;
	}
	int lastK(const vector<int> &data, int val)
	{
		int lo = 0, hi = data.size() - 1, mid;
		bool got_val = false;
		while (lo <= hi)
		{
			mid = lo + (hi - lo) / 2;
			if (data[mid] < val)
			{
				lo = mid + 1;
			}
			else if (data[mid] > val)
			{
				hi = mid - 1;
			}
			else if (mid == data.size() - 1 || data[mid + 1] != val)
			{
				return mid;
			}
			else
			{
				lo = mid + 1;
			}
		}
		return -1;
	}
};

// STL方法
//class Solution {
//public:
//	int GetNumberOfK(vector<int> data, int k) {
//		auto range = equal_range(data.begin(), data.end(), k);
//		return range.second - range.first;
//	}
//};

int main()
{
	Solution s;
	assert(s.GetNumberOfK({ 1, 2, 3, 3, 3, 3, 4, 5 }, 3) == 4);
	assert(s.GetNumberOfK({ 1, 2, 3, 3, 3, 3, 4, 5 }, 5) == 1);
	assert(s.GetNumberOfK({ 1, 2, 3, 3, 3, 3, 4, 5 }, 4) == 1);
	assert(s.GetNumberOfK({ 1, 2, 3, 3, 3, 3, 4, 5 }, 6) == 0);
	assert(s.GetNumberOfK({ 1, 2, 3, 3, 3, 3, 4, 5 }, 0) == 0);
	return 0;
}