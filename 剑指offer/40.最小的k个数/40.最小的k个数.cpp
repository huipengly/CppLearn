#include <random>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 最大优先队列
//class Solution {
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//		if (input.empty() || k == 0)
//			return {};
//		if (input.size() < k)
//			return {};
//		if (input.size() == k)
//			return input;
//		priority_queue<int> pq;
//		for (auto i : input)
//		{
//			if (pq.size() < k)
//				pq.push(i);
//			else if (i < pq.top())
//			{
//				pq.pop();
//				pq.push(i);
//			}
//		}
//
//		vector<int> ret;
//		ret.reserve(k);
//		while (!pq.empty())
//		{
//			ret.push_back(pq.top());
//			pq.pop();
//		}
//		return ret;
//	}
//};


// partition方法没写出来，思路理解了。stl的partition用的不好
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (input.empty() || k == 0)
			return {};
		if (input.size() < k)
			return {};
		if (input.size() == k)
			return input;

		vector<int>::iterator nth;
		nth_element(input.begin(), input.begin() + k - 1, input.end());
		vector<int> ret;
		ret.reserve(k);
		for (auto i = 0; i != k; ++i)
			ret.push_back(input[i]);

		return ret;
	}
};

//class Solution {
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//		if (input.empty() || k == 0)
//			return {};
//		if (input.size() < k)
//			return {};
//		if (input.size() == k)
//			return input;
//		sort(input.begin(), input.end());
//		vector<int> ret;
//		ret.reserve(k);
//		for (int i = 0; i != k; ++i)
//			ret.push_back(input[i]);
//		return ret;
//	}
//};

int main()
{
	Solution s;
	auto ret = s.GetLeastNumbers_Solution({ 4,5,1,6,2,7,3,8 }, 4);
	return 0;
}