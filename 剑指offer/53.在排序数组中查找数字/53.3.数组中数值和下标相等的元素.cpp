#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int equal_to_index(const vector<int> &arr)
{
	int lo = 0, hi = arr.size() - 1, mid;
	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		if (arr[mid] < mid)
		{
			lo = mid + 1;
		}
		else if (arr[mid] > mid)
		{
			hi = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	assert(equal_to_index({ -3, -1, 1, 3, 5 }) == 3);
	return 0;
}