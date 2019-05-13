#include <string>
#include <unordered_set>
using namespace std;

// 堆排序 time: O(nlogn) space:o(1)
class Solution {
public:
	bool isUnique(string& str) {
		heapSort(str);
		for (int i = 1; i != str.size(); ++i)
			if (str[i] == str[i - 1])
				return false;
		return true;
	}
private:
	void sink(string& str, int k, int N)
	{
		while (2 * k + 1 <= N)
		{
			int j = 2 * k + 1;
			if (j < N && str[j] < str[j + 1])		// j和j+1是k的两个子节点，找出其中最大的一个
				++j;
			if (str[k] > str[j])
				break;
			swap(str[k], str[j]);
			k = j;
		}
	}
	void heapSort(string& str)
	{
		int N = str.size() - 1;
		for (int k = (N - 1) / 2; k >= 0; --k)
			sink(str, k, N);
		while (N > 0)
		{
			swap(str[0], str[N--]);
			sink(str, 0, N);
		}
	}
};


class SolutionMap {
public:
	/*
	 * @param str: A string
	 * @return: a boolean
	 */
	bool isUnique(string& str) {
		// write your code here
		unordered_set<char> set;		// 这里可以用str初始化一个set，然后比较str和set大小。写起来快，但是速度固定为O(n)
		for (auto c : str)
		{
			if (set.find(c) == set.end())
				set.insert(c);
			else
				return false;
		}
		return true;
	}
};