#include <deque>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		if (num.size() < size || num.empty() || size == 0)
			return {};
		vector<int> max;
		deque<int> dq;
		for (int i = 0; i != size; ++i)
		{
			while (!dq.empty() && num[dq.back()] <= num[i])
				dq.pop_back();
			dq.push_back(i);
		}
		for (int i = size; i != num.size(); ++i)
		{
			max.push_back(num[dq.front()]);
			while (!dq.empty() && num[dq.back()] <= num[i])
				dq.pop_back();
			while (!dq.empty() && (i - dq.front()) >= size)
				dq.pop_front();
			dq.push_back(i);
		}
		max.push_back(num[dq.front()]);
		return max;
	}
};

int main()
{
	Solution s;
	vector<int> num{ 2, 3, 4, 2, 6, 2, 5, 1 };
	auto ret = s.maxInWindows(num, 3);
	return 0;
}