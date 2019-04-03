#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

// 生成有序丑数
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index <= 0)
			return 0;		//错误的
		vector<int> ugly_numbers{ 1 };
		ugly_numbers.reserve(index);
		vector<int>::iterator T2, T3, T5;
		T2 = T3 = T5 = ugly_numbers.begin();
		while (ugly_numbers.size() < index)
		{
			ugly_numbers.push_back(min(min(*T2 * 2, *T3 * 3), *T5 * 5));

			while (*T2 * 2 <= ugly_numbers.back())
				++T2;
			while (*T3 * 3 <= ugly_numbers.back())
				++T3;
			while (*T5 * 5 <= ugly_numbers.back())
				++T5;
		}

		return ugly_numbers.back();
	}
};

// 暴力搜索
//class Solution {
//public:
//	int GetUglyNumber_Solution(int index) {
//		if (index <= 0)
//			return -1;		//错误的
//		int count = 1;
//		int number = 1;
//		while (index != count)
//		{
//			++number;
//			if (is_ugly(number))
//				++count;
//		}
//		return number;
//	}
//private:
//	int factor[3] = { 2, 3, 5 };
//	bool is_ugly(int number)
//	{
//		for (int f : factor)
//			while (number % f == 0)
//				number /= f;
//		return number == 1;
//	}
//};

int main()
{
	Solution s;
	//assert(s.is_ugly(6) == true);
	//assert(s.is_ugly(8) == true);
	//assert(s.is_ugly(14) == false);
	//assert(s.GetUglyNumber_Solution(9) == 10);
	s.GetUglyNumber_Solution(1);
	return 0;
}