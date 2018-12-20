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

int main()
{

    return 0;
}

//// for test
//void testMethod(vector<int> &a)
//{
//	QuickSort(a);
//}
//
//void compareMethod(vector<int> &a)
//{
//	sort(a.begin(), a.end());
//}
//
//vector<int> generateRandomArray(int maxSize, int maxValue)
//{
//	uniform_int_distribution<unsigned> uValue(0, maxValue);
//	uniform_int_distribution<unsigned> uSize(0, maxSize);
//	vector<int> vec(uSize(e));
//	for (auto &i : vec)
//		i = uValue(e);
//	return vec;
//}
//
//bool isEqual(vector<int> &lhs, vector<int> &rhs)
//{
//	return lhs == rhs;
//}
//
//void test()
//{
//	int testTime = 50000;
//	int maxSize = 20;
//	int maxValue = 200;
//	bool succeed = true;
//	for (int i = 0; i != testTime; ++i)
//	{
//		auto vecTest = generateRandomArray(maxSize, maxValue);
//		auto vecTrue = vecTest;
//		auto origin = vecTest;
//		testMethod(vecTest);
//		compareMethod(vecTrue);
//		if (!isEqual(vecTest, vecTrue))
//		{
//			succeed = false;
//			break;
//		}
//	}
//
//	cout << (succeed ? "passed" : "BUG!") << endl;
//}