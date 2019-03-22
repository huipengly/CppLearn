#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		// 方法3
		if (rotateArray.empty())
			return 0;

		if (rotateArray.front() < rotateArray.back())
			return rotateArray.front();

		int lo = 0, hi = rotateArray.size() - 1, mid;
		while (lo <= hi)
		{
			mid = lo + (hi - lo) / 2;
			if (rotateArray[mid] > rotateArray[lo])
				lo = mid;
			else if (rotateArray[mid] < rotateArray[hi])
				hi = mid;
			else
				return *min_element(rotateArray.rbegin(), rotateArray.rend());
		}

		return rotateArray[mid];

		// 方法2
		//for (int i = 0; i != rotateArray.size() - 1; ++i)
		//{
		//	if (rotateArray[i] > rotateArray[i + 1])
		//		return rotateArray[i + 1];
		//}
		//return rotateArray.front();

		// 方法1
		//return *min_element(rotateArray.rbegin(), rotateArray.rend());
	}
};

int main()
{
	Solution s;
	cout << s.minNumberInRotateArray({ 6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,9359,9719,9895,9896,9913,9962,154,293,334,492,1323,1479,1539,1727,1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,5142,5437,5448,5668,5706,5725,6300,6335 }) << endl;
	return 0;
}