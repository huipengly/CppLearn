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

int maxGap(vector<int> &a)
{
	if (a.empty() || a.size() < 2)
		return 0;

	int N = a.size();
	int maxNum = *max_element(a.begin(), a.end());
	int minNum = *min_element(a.begin(), a.end());

	if (maxNum == minNum)
		return 0;

	vector<bool> hasNum(N + 1, false);
	vector<int> mins(N + 1, INT_MAX);
	vector<int> maxs(N + 1, INT_MIN);

	for (auto num : a)
	{
		int index = (num - minNum) * N / (maxNum - minNum); // 计算在第几个桶
		hasNum[index] = true;
		maxs[index] = std::max(num, maxs[index]);
		mins[index] = std::min(num, mins[index]);
	}

	int ret = 0;
	int lastMax = maxs[0];
	for (int i = 1; i < N + 1; ++i)
	{
		if (hasNum[i])					// 比较非空桶最小和前一个非空桶最大
		{
			ret = std::max(ret, mins[i] - lastMax);
			lastMax = maxs[i];
		}
	}
	return ret;
}


// for test
auto testMethod(vector<int> &a)
{
	return maxGap(a);
}

auto compareMethod(vector<int> &a)
{
	if (a.empty() || a.size() < 2)
		return 0;
	sort(a.begin(), a.end());
	int max = INT_MIN;
	for (int i = 1; i != a.size(); ++i)
	{
		max = std::max(max, a[i] - a[i - 1]);
	}
	return max;
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
	int maxSize = 5;
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
	vector<int> ivec{ 167, 118, 41 };
	cout << maxGap(ivec) << endl;
	return 0;
}
