#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
	void Insert(int num)
	{
		if (count % 2) // 奇数
		{
			if (!min_pq.empty() && num > min_pq.top())
			{
				max_pq.push(min_pq.top());
				min_pq.pop();
				min_pq.push(num);
			}
			else
			{
				max_pq.push(num);
			}
		}
		else	// 偶数
		{
			if (!max_pq.empty() && num < max_pq.top())
			{
				min_pq.push(max_pq.top());
				max_pq.pop();
				max_pq.push(num);
			}
			else
			{
				min_pq.push(num);
			}
		}
		++count;
	}

	double GetMedian()
	{
		if (count % 2)
		{
			return min_pq.top();
		}
		else
		{
			int n_max = max_pq.empty() ? 0 : max_pq.top();
			int n_min = min_pq.empty() ? 0 : min_pq.top();
			return (n_min + n_max) / 2.0;
		}
	}
private:
	priority_queue<int> max_pq;
	priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
	int count = 0;
};

int main()
{
	Solution s;
	s.Insert(1);
	cout << s.GetMedian() << endl;
	s.Insert(2);
	cout << s.GetMedian() << endl;
	s.Insert(3);
	cout << s.GetMedian() << endl;
	return 0;
}