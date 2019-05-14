#include <vector>
using namespace std;

// 排序完之后没必要像书上一样进行完美洗牌，直接从第一个数开始，两两交换就行。
class Solution2 {
public:
	void wiggleSort(vector<int>& nums) {
		heapSort(nums);
		for (int i = 2; i < nums.size(); i += 2)
		{
			swap(nums[i - 1], nums[i]);
		}
	}
private:
	// heap sort 自己实现
	template <typename T>
	void sink(vector<T> & a, int k, int N)
	{
		while (2 * k + 1 <= N)
		{
			int j = 2 * k + 1;
			if (j < N && a[j] < a[j + 1])		// j和j+1是k的两个子节点，找出其中最大的一个
				++j;
			if (a[k] > a[j])
				break;
			swap(a[k], a[j]);
			k = j;
		}
	}
	template <typename T>
	void heapSort(vector<T> & a)
	{
		int N = a.size() - 1;
		for (int k = (N - 1) / 2; k >= 0; --k)
			sink(a, k, N);
		while (N > 0)
		{
			swap(a[0], a[N--]);
			sink(a, 0, N);
		}
	}
};

// 书上的方法 time: O(nlogn) space: O(n)
class Solution1 {
public:
	void wiggleSort(vector<int>& nums) {
		heapSort(nums);
		if (nums.size() % 2 == 0)
		{
			shuffle(nums, 0, nums.size() - 1);
			for (int i = 0; i < nums.size(); i += 2)
			{
				swap(nums[i], nums[i + 1]);
			}
		}
		else
			shuffle(nums, 1, nums.size() - 1);
	}
private:
	void reverse(vector<int>& arr, int L, int R)
	{
		while (L < R)
			swap(arr[L++], arr[R--]);
	}

	void rotate(vector<int>& arr, int L, int M, int R)
	{
		reverse(arr, L, M);
		reverse(arr, M + 1, R);
		reverse(arr, L, R);
	}

	int modifyIndex(int i, int len)
	{
		return (2 * i) % (len + 1);
	}

	void cycle(vector<int> & arr, int start, int len, int k)
	{
		for (int i = 0, trigger = 1; i < k; ++i, trigger *= 3)
		{
			int preValue = arr[start + trigger - 1];
			int cur = modifyIndex(trigger, len);		// 当前位置应该填充点的索引
			while (cur != trigger)
			{
				swap(preValue, arr[start + cur - 1]);
				cur = modifyIndex(cur, len);
			}
			arr[start + cur - 1] = preValue;
		}
	}

	void shuffle(vector<int> & arr, int L, int R)
	{
		while (R - L > 0)	// R和L相等的情况不用考虑了，只有一个元素，不用洗牌
		{
			int len = R - L + 1;
			int base = 3, k = 1;
			while (base <= (len + 1) / 3)
			{
				base *= 3;
				++k;
			}
			int half = (base - 1) / 2;
			int mid = L + (R - L) / 2;
			rotate(arr, L + half, mid, mid + half);
			cycle(arr, L, base - 1, k);
			L = L + base - 1;
		}
	}
	// heap sort 自己实现
	template <typename T>
	void sink(vector<T>& a, int k, int N)
	{
		while (2 * k + 1 <= N)
		{
			int j = 2 * k + 1;
			if (j < N && a[j] < a[j + 1])		// j和j+1是k的两个子节点，找出其中最大的一个
				++j;
			if (a[k] > a[j])
				break;
			swap(a[k], a[j]);
			k = j;
		}
	}
	template <typename T>
	void heapSort(vector<T> & a)
	{
		int N = a.size() - 1;
		for (int k = (N - 1) / 2; k >= 0; --k)
			sink(a, k, N);
		while (N > 0)
		{
			swap(a[0], a[N--]);
			sink(a, 0, N);
		}
	}
};