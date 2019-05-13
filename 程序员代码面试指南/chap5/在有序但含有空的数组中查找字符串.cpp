#include <vector>
#include <string>
#include <iostream>
using namespace std;
int getIndexInArrayIncludeNull(const vector<string>& strs, const string& str)
{
	int res = -1;
	int lo = 0, hi = strs.size() - 1, mid = 0;
	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		int index = mid;

		// 首先向左边界找到非零的索引，如果没有，则lo设置mid + 1
		while (index > lo && strs[index].empty())
			--index;
		if (index == lo)
			lo = mid + 1;
		else
		{
			mid = index;

			if (strs[mid] > str)
				hi = mid - 1;
			else if (strs[mid] < str)
				lo = mid + 1;
			else
			{
				res = mid;
				hi = mid - 1;
			}
		}
	}
	return res;
}

int main()
{
	cout << getIndexInArrayIncludeNull({ "", "a", "", "a", "", "b", "", "c" }, "a") << endl;
	cout << getIndexInArrayIncludeNull({ "", "a", "", "a", "", "b", "", "c" }, "") << endl;
	cout << getIndexInArrayIncludeNull({ "", "a", "", "a", "", "b", "", "c" }, "d") << endl;
	return 0;
}