#include <vector>
using std::vector;
#include <algorithm>
using std::sort; using std::max;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size() < 2)
			return intervals;
		sort(intervals.begin(), intervals.end(), [](const Interval &i1, const Interval &i2) { return i1.start < i2.start; });
		vector<Interval> merged;
		for (auto interval : intervals)
		{
			if (merged.empty() || merged.back().end < interval.start)
			{
				merged.push_back(interval);
			}
			else
			{
				merged.back().end = max(merged.back().end, interval.end);
			}
		}
		return merged;
	}
};

int main()
{
	Solution s;
	//vector<Interval> intervals{ Interval(1, 4), Interval(4, 5) };
	vector<Interval> intervals{ Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18) };
	s.merge(intervals);
	return 0;
}