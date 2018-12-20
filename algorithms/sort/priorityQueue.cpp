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

template <typename T> class MaxPQ
{
public:
	MaxPQ() : N(0) { pq.resize(5); }
	void push(T v);
	bool empty() { return N == 0; }
	int size() { return N; }
	T delMax();

private:
	vector<T> pq;		// 存储堆，从0位开始存
	int N;				// N指向队列末端之后一个元素
	void sink(int k);
	void swim(int k);
};

template <typename T> void MaxPQ<T>::push(T v)
{
	pq[N] = v;
	swim(N++);
	if (N > pq.size() - 1)
		pq.resize(2 * pq.size());
}

template <typename T> T MaxPQ<T>::delMax()
{
	T max = pq[0];
	pq[0] = pq[--N];
	sink(0);
	return max;
}

template <typename T> void MaxPQ<T>::sink(int k)
{
	while (2 * k + 1 < N)
	{
		int j = 2 * k + 1;
		if (j < N && pq[j] < pq[j + 1])		// 先判断两个子节点哪个大，和大的比较
			j++;
		if (pq[k] > pq[j]) break;			// 比两个子节点都大，终止
		std::swap(pq[k], pq[j]);
		k = j;
	}
}

template <typename T> void MaxPQ<T>::swim(int k)
{
	while (k > 0 && (pq[k] > pq[(k - 1) / 2]))		// 如果while里只有一个if，可将if判断放到while的判断里
	{
		swap(pq[k], pq[(k - 1) / 2]);
		k = (k - 1) / 2;
	}
}

 // for test
vector<int> testMethod(vector<int> &a)
{
	MaxPQ<int> pq;
	vector<int> ret;
	for (auto i : a)
	{
		pq.push(i);
	}
	while (!pq.empty())
	{
		ret.push_back(pq.delMax());
	}
	return ret;
}

vector<int> compareMethod(vector<int> &a)
{
	priority_queue<int> pq;
	vector<int> ret;
	for (auto i : a)
	{
		pq.push(i);
	}
	while (!pq.empty())
	{
		ret.push_back(pq.top());
		pq.pop();
	}
	return ret;
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
	int maxSize = 20;
	int maxValue = 200;
	bool succeed = true;
	for (int i = 0; i != testTime; ++i)
	{
		//auto vecTest = vector<int>{ 198, 128, 97 };
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
    return 0;
}
