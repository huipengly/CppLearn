#include <vector>
using namespace std;

int onceNum(const vector<int>& arr, int k)
{
	vector<int> eO(32, 0);
	for (int cur : arr)
	{
		int bitmask = 1;
		for (int i = 31; i >= 0; --i)
		{
			if ((cur & bitmask) != 0)
				++eO[i];
			bitmask <<= 1;
		}
	}
	int res = 0;
	for (int i = 0; i != 32; ++i)
	{
		res <<= 1;
		res += eO[i] % k;
	}
	return res;
}