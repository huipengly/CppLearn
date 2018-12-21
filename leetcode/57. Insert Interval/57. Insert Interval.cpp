#include <vector>
using std::vector;
#include <algorithm>
using std::sort; using std::max; using std::min;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		auto compare = [](const Interval &intv1, const Interval &intv2)
		{ return intv1.end < intv2.start; };
		auto range = equal_range(intervals.begin(), intervals.end(), newInterval, compare);
		auto itr1 = range.first, itr2 = range.second;
		if (itr1 == itr2) {
			intervals.insert(itr1, newInterval);
		}
		else {
			itr2--;
			itr2->start = min(newInterval.start, itr1->start);
			itr2->end = max(newInterval.end, itr2->end);
			intervals.erase(itr1, itr2);
		}
		return intervals;
	}
};

int main()
{
	Solution s;
	//vector<Interval> intervals{ {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}, {18, 19} };
	vector<Interval> intervals{ {0, 1}, {2, 3}, {4, 5}, {6, 7}};
	Interval newInterval{ 1, 8 };
	auto v = s.insert(intervals, newInterval);
	return 0;
}