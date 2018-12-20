#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

std::random_device rd;			// 用来播种
default_random_engine e(rd());	// 随机数引擎
// uniform_int_distribution<int> u(0, 10);	// 产生一个[0, 10]的随机整数分布
// uniform_real_distribution<double> u(0, 10);	// 产生一个[0, 10)的随机实数分布
// int rand = u(e);	//产生随机数

void BubbleSort(vector<int> &a)
{
	auto N = a.size();
	if (a.empty())
		return;
	for (int i = N - 1; i > 0; --i) 
	{
		for (int j = 0; j < i; ++j) 
		{
			if (a[j] > a[j + 1])
				std::swap(a[j], a[j + 1]);
		}
	}
}

void SelectSort(vector<int> &a)
{
	auto N = a.size();
	for (int i = 0; i < N; ++i)
	{
		int min = i;
		for (int j = i + 1; j < N; ++j)
		{
			min = a[j] < a[min] ? j : min;
		}
		std::swap(a[i], a[min]);
	}
}

void InsertSort(vector<int> &a)
{
	auto N = a.size();
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j > 0 && a[j] < a[j - 1]; --j)	// for有两个条件，j未到头且j还比左侧小。或者把判断小于放在for里，但是要加入break
		{
			std::swap(a[j], a[j - 1]);
		}
	}
}

void ShellSort(vector<int> &a)
{
	auto N = a.size();
	int h = 1;
	while (h < N / 3) h = 3 * h + 1;
	while (h > 0)
	{
		for (int i = h; i < N; ++i)
		{
			for (int j = i; j >= h && a[j] < a[j - h]; j -= h)
			{
				std::swap(a[j], a[j - h]);
			}
		}
		h /= 3;
	}
}

// 递归方式merge sort
vector<int> aux;

void Merge(vector<int> &a, int lo, int mid, int hi)
{
	int i = lo, j = mid + 1;

	for (int k = i; k <= hi; ++k)
		aux[k] = a[k];

	for (int k = lo; k <= hi; ++k)
	{
		if (i > mid)				a[k] = aux[j++];
		else if (j > hi)			a[k] = aux[i++];
		else if (aux[i] < aux[j]) a[k] = aux[i++];
		else						a[k] = aux[j++];
	}
}

void MergeSort(vector<int> &a, int lo, int hi)
{	
	if (lo >= hi)
		return;
	auto mid = lo + (hi - lo) / 2;
	MergeSort(a, lo, mid);
	MergeSort(a, mid + 1, hi);
	Merge(a, lo, mid, hi);
}

void MergeSort(vector<int> &a)
{
	aux.resize(a.size());
	MergeSort(a, 0, a.size() - 1);
}

// 非递归，自底向上merge sort
void MergeSort2(vector<int> &a)
{
	int N = a.size();
	aux.resize(N);
	for (int sz = 1; sz < N; sz += sz)
	{
		for (int lo = 0; lo < N - sz; lo += sz + sz)
		{
			Merge(a, lo, lo + sz - 1, min(lo + sz + sz - 1, N - 1));		// 不能超过数组最大值
		}
	}
}

// 快速排序
int Partition(vector<int> &a, int lo, int hi)
{
	int v = a[lo];
	int i = lo, j = hi + 1;
	while (true)
	{
		while (a[++i] < v)
			if (i == hi)
				break;
		while (a[--j] > v)
			if (j == lo)
				break;
		if (i >= j)
			break;
		std::swap(a[i], a[j]);
	}
	std::swap(a[lo], a[j]);
	return j;
}

void QuickSort(vector<int> &a, int lo, int hi)
{
	if (lo >= hi) 
		return;

	int j = Partition(a, lo, hi);
	QuickSort(a, lo, j - 1);
	QuickSort(a, j + 1, hi);
}

void QuickSort(vector<int> &a)
{
	shuffle(a.begin(), a.end(), e);
	QuickSort(a, 0, a.size() - 1);
}

// 3-way Quick Sort

vector<int> Partition3Way(vector<int> &a, int lo, int hi)
{
	int v = a[lo];
	int lt = lo, i = lo + 1, gt = hi;
	while (i <= gt)
	{
		if (a[i] < v)
			std::swap(a[lt++], a[i++]);
		else if (a[i] > v)
			std::swap(a[gt--], a[i]);
		else
			i++;
	}
	return vector<int>{lt, gt};
}

void QuickSort3Way(vector<int> &a, int lo, int hi)
{
	if (lo >= hi)
		return;

	vector<int> p = Partition3Way(a, lo, hi);
	int lt = p.front(), gt = p.back();
	QuickSort(a, lo, lt - 1);
	QuickSort(a, gt + 1, hi);
}

void QuickSort3Way(vector<int> &a)
{
	shuffle(a.begin(), a.end(), e);
	QuickSort3Way(a, 0, a.size() - 1);
}

// for test
void testMethod(vector<int> &a)
{
	QuickSort3Way(a);
}

void compareMethod(vector<int> &a)
{
	sort(a.begin(), a.end());
}

vector<int> generateRandomArray(int maxSize, int maxValue)
{
	uniform_int_distribution<unsigned> uValue(0, maxValue);
	uniform_int_distribution<unsigned> uSize(0, maxSize);
	vector<int> vec(uSize(e));
	for (auto &i : vec)
		i = uValue(e);
	return vec;
}

bool isEqual(vector<int> &lhs, vector<int> &rhs)
{
	return lhs == rhs;
}

void test()
{
	int testTime = 50000;
	int maxSize = 200;
	int maxValue = 200;
	bool succeed = true;
	for (int i = 0; i != testTime; ++i)
	{
		auto vecTest = generateRandomArray(maxSize, maxValue);
		auto vecTrue = vecTest;
		auto origin = vecTest;
		testMethod(vecTest);
		compareMethod(vecTrue);
		if (!isEqual(vecTest, vecTrue))
		{
			succeed = false;
			break;
		}
	}

	cout << (succeed ? "passed" : "BUG!") << endl;
}

int main()
{
	test();

	vector<int> a{ 110, 104, 53 };
	QuickSort(a);

    return 0;
}