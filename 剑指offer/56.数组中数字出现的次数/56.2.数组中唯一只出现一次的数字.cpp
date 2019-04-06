#include <cassert>
#include <vector>
using namespace std;

int find_number_only_appering_once(const vector<int> &arr)
{
	vector<int> data(32, 0);
	for (auto n : arr)
	{
		int aux = 1;
		for (int i = 31; i >= 0; --i)
		{
			if (n & aux)
				++data[i];
			aux <<= 1;
		}
	}

	int ret = 0;
	for (int i = 0; i != 32; ++i)
	{
		ret <<= 1;
		if (data[i] % 3)
			++ret;
	}

	return ret;
}

int main()
{
	assert(find_number_only_appering_once({ 1, 1, 1, 2, 3, 3, 3, 4, 4, 4, 10, 10 ,10 }) == 2);
	assert(find_number_only_appering_once({ 1, 1, 1}) == 0);
	return 0;
}