#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>
using namespace std;
// partition
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
			return 0;

		std::random_device rd;
		std::mt19937 g(rd());
		shuffle(numbers.begin(), numbers.end(), g);
		vector<int>::iterator it = numbers.begin();
		vector<int>::iterator end = numbers.end();
		int half = numbers.size() / 2;
		while (it - numbers.begin() != half)
		{
			auto val = *it;
			it = partition(it, end, [val](int n) { return n < val; });
			if (it - numbers.begin() > half)
			{
				end = it - 1;
				it = numbers.begin();
			}
			else if (it - numbers.begin() < half)
			{
				++it;
			}
		}

		int count = 0;
		for (auto num : numbers)
		{
			if (num == *it)
				++count;
		}

		return count > (numbers.size() / 2) ? *it : 0;
	}
};

// 空间换时间
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		if (numbers.empty())
//			return 0;
//		unordered_map<int, int> map;
//		for (auto number : numbers)
//		{
//			if (map.find(number) == map.end())
//				map[number] = 1;
//			else
//				++map[number];
//		}
//
//		for (auto &pair : map)
//		{
//			if (pair.second > (numbers.size() / 2))
//				return pair.first;
//		}
//		return 0;
//	}
//};

// O(n*logn)
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		if (numbers.empty())
//			return 0;
//		sort(numbers.begin(), numbers.end());
//		int max_length = 0;
//		int max_index = 0;
//		int count = 1;
//		for (int i = 1; i != numbers.size(); ++i)
//		{
//			if (numbers[i] == numbers[i - 1])
//			{
//				++count;
//			}
//			else
//			{
//				if (count > max_length)
//				{
//					max_length = count;
//					max_index = i - 1;
//				}
//				count = 1;
//			}
//		}
//		if (count > max_length)
//		{
//			max_length = count;
//			max_index = numbers.size() - 1;
//		}
//
//		return max_length > (numbers.size() / 2) ? numbers[max_index] : 0;
//	}
//};

int main()
{
	Solution s;
	auto ret = s.MoreThanHalfNum_Solution({ 1,2,3,2,2,2,5,4,2 });
	return 0;
}