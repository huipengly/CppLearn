#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int maxLenth2(const vector<int>& arr, int k)
{
	unordered_map<int, int> map;
	map[0] = -1;
	int len = 0, sum = 0;
	for (int i = 0; i != arr.size(); ++i)
	{
		sum += arr[i];
		if (map.find(sum - k) != map.end())
		{
			len = std::max(i - map[sum - k], len);
		}

		if (map.find(sum) == map.end())
		{
			map[sum] = i;
		}
	}
	return len;
}

int maxLenth3(const vector<int>& arr)	// 正数和负数个数相等
{
	auto narr = arr;
	for (auto& i : narr)
	{
		if (i > 0)
			i = 1;
		else if (i < 0)
			i = -1;
	}
	return maxLenth2(narr, 0);
}

int maxLenth4(const vector<int>& arr)	// 0,1个数相等
{
	auto narr = arr;
	for (auto& i : narr)
	{
		if (i == 0)
			i = -1;
	}
	return maxLenth2(narr, 0);
}


int main()
{
	cout << maxLenth2({ 1, 2, -1, 3 }, 2) << endl;
	cout << maxLenth3({ 1, 2, -1, 3 }) << endl;
	cout << maxLenth4({ 1, 0, 1, 1, 1, 1 }) << endl;
	return 0;
}