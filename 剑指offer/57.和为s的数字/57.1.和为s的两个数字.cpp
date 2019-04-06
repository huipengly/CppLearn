#include <vector>
using namespace std;
// O(n)
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		if (array.empty())
			return {};
		auto it1 = array.cbegin(), it2 = array.cend() - 1;
		while (it1 < it2)
		{
			int val = *it1 + *it2;
			if (val > sum)
				--it2;
			else if (val < sum)
				++it1;
			else
				return { *it1, *it2 };
		}
		return {};
	}
};

// O(nlogn)
//class Solution {
//public:
//	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
//		for (int i = 0; i != array.size(); ++i)
//		{
//			int index = binary_search(array, i, array.size() - 1, sum - array[i]);
//			if (index >= 0)
//				return { array[i], array[index]};
//		}
//		return {};
//	}
//private:
//	int binary_search(const vector<int> &arr, int lo, int hi, int val)
//	{
//		while (lo <= hi)
//		{
//			int mid = lo + (hi - lo) / 2;
//			if (arr[mid] < val)
//				lo = mid + 1;
//			else if (arr[mid] > val)
//				hi = mid - 1;
//			else
//				return mid;
//		}
//		return -1;
//	}
//};

int main()
{

	return 0;
}