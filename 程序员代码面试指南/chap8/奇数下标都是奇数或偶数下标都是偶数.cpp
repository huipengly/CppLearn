#include <vector>
using namespace std;

void modify(vector<int>& arr)
{
	int even = 0, odd = 1, end = arr.size() - 1;
	while (even <= end && odd <= end)
	{
		if ((arr[end] & 1) == 1)
		{
			std::swap(arr[end], arr[odd]);
			odd += 2;
		}
		else
		{
			std::swap(arr[end], arr[even]);
			even += 2;
		}
	}
}