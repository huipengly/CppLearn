#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> ret;
		deque<int> deq{ 1, 2 };
		int lo = 1, hi = 2, val = 3;
		while (lo != hi)
		{
			if (val < sum)
			{
				val += ++hi;
				deq.push_back(hi);
			}
			else if (val > sum)
			{
				val -= lo++;
				deq.pop_front();
			}
			else
			{
				ret.push_back(vector<int>(deq.begin(), deq.end()));
				val += ++hi;
				deq.push_back(hi);
				val -= lo++;
				deq.pop_front();
			}
		}
		return ret;
	}
};

int main()
{
	Solution s;
	auto ret = s.FindContinuousSequence(15);
	return 0;
}