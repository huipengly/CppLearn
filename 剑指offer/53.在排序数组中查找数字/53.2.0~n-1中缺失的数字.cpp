#include <cassert>
#include <vector>
using namespace std;

// 类似第一个k
int miss_number(const vector<int> &arr)
{
	int N = arr.size() + 1;
	int lo = 0, hi = N - 2, mid;
	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		if (arr[mid] < mid)
		{
			return -1;	// 不可能小于索引的
		}
		else if (arr[mid] == mid)
		{
			lo = mid + 1;
		}
		else if (mid == 0 || arr[mid - 1] == mid - 1)	// 剩下的都是大于索引的
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

int main()
{
	assert(miss_number({ 0, 1, 2, 3, 4, 6 }) == 5);
	assert(miss_number({ 0, 1, 2, 3, 4, 5 }) == -1);
	assert(miss_number({ 0, 1, 1, 3, 4, 5 }) == -1);
	return 0;
}