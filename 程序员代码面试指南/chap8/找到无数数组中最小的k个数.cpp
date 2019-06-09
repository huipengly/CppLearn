#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 使用自带的pq
vector<int> getMinKNumberByHeap1(const vector<int>& arr, int k)
{
	if (arr.size() <= k)
		return arr;
	priority_queue<int> pq;
	for (int i = 0; i != k; ++i)
		pq.push(arr[i]);
	for (int i = k; i != arr.size(); ++i)
	{
		if (arr[i] < pq.top())
		{
			pq.pop();
			pq.push(arr[i]);
		}
	}
	vector<int> res(k);
	for (int i = 0; i != k; ++i)
	{
		res[i] = pq.top();
		pq.pop();
	}
	return res;
}

// 自己实现pq
void swim(vector<int>& arr, int k)
{
	while (k > 0 && arr[(k - 1) / 2] < arr[k])
	{
		std::swap(arr[(k - 1) / 2], arr[k]);
		k = (k - 1) / 2;
	}
}

void insert(vector<int>& arr, int num)
{
	arr.push_back(num);
	swim(arr, arr.size() - 1);
}

void sink(vector<int>& arr, int k)
{
	while ((2 * k + 1) < arr.size())		// 确定子节点没有越界
	{
		int j = 2 * k + 1;
		if (j < arr.size() - 1 && arr[j] < arr[j + 1])	// 判断是否为最后一个节点，如果不是，就有右子节点。如果右边大，则++j
			++j;
		if (arr[j] > arr[k])				// 如果当前节点比子节点最大的小，就下沉
			std::swap(arr[j], arr[k]);
		k = j;
	}
}

vector<int> getMinKNumberByHeap2(const vector<int>& arr, int k)
{
	if (arr.size() <= k)
		return arr;
	vector<int> pq;
	for (int i = 0; i != k; ++i)
		insert(pq, arr[i]);
	for (int i = k; i != arr.size(); ++i)
	{
		if (arr[i] < pq[0])
		{
			pq[0] = arr[i];
			sink(pq, 0);
		}
	}
	return pq;
}

int main()
{
	auto res = getMinKNumberByHeap2({ 1, 3, 5, 7, 9, 2, 4, 6, 10 }, 4);
	for (int i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}