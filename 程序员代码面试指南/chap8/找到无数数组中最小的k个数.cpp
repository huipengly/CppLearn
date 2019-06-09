#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// ʹ���Դ���pq
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

// �Լ�ʵ��pq
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
	while ((2 * k + 1) < arr.size())		// ȷ���ӽڵ�û��Խ��
	{
		int j = 2 * k + 1;
		if (j < arr.size() - 1 && arr[j] < arr[j + 1])	// �ж��Ƿ�Ϊ���һ���ڵ㣬������ǣ��������ӽڵ㡣����ұߴ���++j
			++j;
		if (arr[j] > arr[k])				// �����ǰ�ڵ���ӽڵ�����С�����³�
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