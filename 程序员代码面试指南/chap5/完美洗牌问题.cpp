#include <vector>
#include <iostream>
using namespace std;

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

void cycle(vector<int>& arr, int start, int len, int k)
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

void shuffle(vector<int>& arr, int L, int R)
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

void shuffle(vector<int>& arr)
{
	return shuffle(arr, 0, arr.size() - 1);
}

void shuffle_extra_space(vector<int>& arr)
{
	int len = arr.size();
	int half = len / 2;
	int start = 0;
	vector<int> aux;
	aux.reserve(len);
	while (half != len)
	{
		aux.push_back(arr[half++]);
		aux.push_back(arr[start++]);
	}
	arr = aux;
}

int main()
{
	vector<int> arr{ 1, 2, 3, 4, 5, 6 };
	shuffle_extra_space(arr);
	for (auto i : arr)
		cout << i << endl;
	return 0;
}