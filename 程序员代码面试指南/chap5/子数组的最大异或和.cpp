#include <algorithm>
#include <vector>
using namespace std;

int maxXorSubarray1(const vector<int>& arr)
{
	if (arr.empty())
		return 0;
	vector<int> eor(arr.size, 0);
	int max = INT_MIN;
	eor[0] = arr[0];
	for (int i = 1; i != arr.size; ++i)
		eor[i] = eor[i - 1] ^ arr[i];
	for (int j = 0; j != arr.size(); ++j)
	{
		for (int i = 0; i <= j; ++i)
		{
			max = std::max(max, i == 0 ? eor[i] : eor[j] ^ eor[i - 1]); 
		}
	}
	return max;
}

