#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <ctime>
#include <queue>

using namespace std;

std::random_device rd;			// 用来播种
default_random_engine e(rd());	// 随机数引擎
// uniform_int_distribution<int> u(0, 10);	// 产生一个[0, 10]的随机整数分布
// uniform_real_distribution<double> u(0, 10);	// 产生一个[0, 10)的随机实数分布
// int rand = u(e);	//产生随机数

int sum;

void mergeSum(vector<int> &a, int lo, int mid, int hi)
{
	for (int i = mid + 1; i <= hi; ++i)
	{
		for (int j = lo; j <= mid; ++j)
		{
			if (a[j] >= a[i])
				continue;
			else
				sum += a[j];
		}
	}
}

void smallSum(vector<int> &a, int lo, int hi)
{
	auto mid = lo + (hi - lo) / 2;
	if (lo >= hi)
		return;
	smallSum(a, lo, mid);
	smallSum(a, mid + 1, hi);
	mergeSum(a, lo, mid, hi);
}

int smallSum(vector<int> &a)
{
	sum = 0;
	smallSum(a, 0, a.size() - 1);
	return sum;
}

int smallSum2(vector<int> &a)
{
	int sum = 0;
	if (a.empty())
		return sum;
	for (int i = 1; i != a.size(); ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (a[j] < a[i])
				sum += a[j];
		}
	}
	return sum;
}

vector<int> aux;

void merge(vector<int> &a, int lo, int mid, int hi)
{
	int i = lo, j = mid + 1;			// 这里要是mid+1
	for (int k = lo; k <= hi; ++k)
		aux[k] = a[k];

	for (int k = lo; k <= hi; ++k)
	{
		if (i > mid)			
			a[k] = aux[j++];
		else if (j > hi)		
			a[k] = aux[i++];
		else if (aux[i] > aux[j])		// 这个地方要比辅助数组，因为原数组会被改变
			a[k] = aux[j++];
		else					
			a[k] = aux[i++];
	}
}


void mergeSort(vector<int> &a, int lo, int hi)
{
	auto mid = lo + (hi - lo) / 2;
	if (lo >= hi)
		return;
	mergeSort(a, lo, mid);
	mergeSort(a, mid + 1, hi);
	merge(a, lo, mid, hi);
}

void mergeSort(vector<int> &a)
{
	aux.resize(a.size());
	mergeSort(a, 0, a.size() - 1);
}

// for test
auto testMethod(vector<int> &a)
{
	return smallSum(a);
}

auto compareMethod(vector<int> &a)
{
	return smallSum2(a);
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

bool isEqual(int lhs, int rhs)
{
	return lhs == rhs;
}

void test()
{
	int testTime = 50000;
	int maxSize = 20;
	int maxValue = 200;
	bool succeed = true;
	for (int i = 0; i != testTime; ++i)
	{
		auto vecTest = generateRandomArray(maxSize, maxValue);
		auto vecTrue = vecTest;
		auto origin = vecTest;
		auto testResult = testMethod(vecTest);
		auto compareResult = compareMethod(vecTrue);
		if (!isEqual(testResult, compareResult))
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
	vector<int> ivec{ 1, 3, 4, 2, 5 };
	cout << smallSum2(ivec) << endl;
    return 0;
}