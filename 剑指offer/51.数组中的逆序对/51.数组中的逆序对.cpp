#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.empty())
			return 0;
		aux = vector<int>(data.size(), 0);
		return InversePairs(data, 0, data.size() - 1);
	}
private:
	vector<int> aux;
	int InversePairs(vector<int> &data, int start, int end) {
		auto length = end - start + 1;
		if (length == 2)
		{
			if (data[start] > data[end])
			{
				std::swap(data[start], data[end]);
				return 1;
			}
			else
				return 0;
		}

		int count = 0;
		int mid = start + length / 2;
		count += InversePairs(data, start, mid - 1);
		count += InversePairs(data, mid, end);
		int p1 = mid - 1, p2 = end;
		auto auxi = end;
		while (p1 >= start && p2 >= mid)
		{
			if (data[p1] > data[p2])
			{
				count += p2 - mid + 1;
				aux[auxi--] = data[p1--];
			}
			else
			{
				aux[auxi--] = data[p2--];
			}
		}

		while (p1 >= start)
		{
			aux[auxi--] = data[p1--];
		}

		while (p2 >= mid)
		{
			aux[auxi--] = data[p2--];
		}

		for (int i = start; i != end + 1; ++i)
		{
			data[start] = aux[start];
		}

		return count;
	}
};

// O(n^2)的方法
//class Solution {
//public:
//	int InversePairs(vector<int> data) {
//		int count = 0;
//		for (int i = 0; i != data.size(); ++i)
//		{
//			int value = data[i];
//			count += count_if(data.begin() + i, data.end(), [&value](int n) { return n < value; });
//		}
//		return count;
//	}
//};

int main()
{
	Solution s;
	assert(s.InversePairs({ 1,2,3,4,5,6,7,0 }) == 7);
	return 0;
}