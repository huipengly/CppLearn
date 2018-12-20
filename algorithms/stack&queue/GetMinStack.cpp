/**
 * @file Template.cpp
 * @author huipengly
 * @brief 可返回最小值栈
 * @version 0.1
 * @date 2018-12-20
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <queue>
#include <stack>

using namespace std;

std::random_device rd;			// 用来播种
default_random_engine e(rd());	// 随机数引擎
// uniform_int_distribution<int> u(0, 10);	// 产生一个[0, 10]的随机整数分布
// uniform_real_distribution<double> u(0, 10);	// 产生一个[0, 10)的随机实数分布
// int rand = u(e);	//产生随机数

template <typename T>
class GetMinStack
{
public:
	void push(T t);
	T pop();
	T popMin();
	bool empty() { return standStack_.empty(); }

private:
	stack<T> standStack_;
	stack<T> minStack_;
	T min = INT_MAX;
};

template <typename T>
void GetMinStack<T>::push(T t)
{
	standStack_.push(t);
	min = min < t ? min : t;
	minStack_.push(min);
}

template<typename T>
T GetMinStack<T>::pop()
{
	auto ret = standStack_.top();
	standStack_.pop();
	minStack_.pop();
	return ret;
}

template<typename T>
T GetMinStack<T>::popMin()
{
	auto ret = minStack_.top();
	standStack_.pop();
	minStack_.pop();
	return ret;
}

// for test
auto testMethod(vector<int> &a)
{
	GetMinStack<int> minStack;
	for (auto i : a)
		minStack.push(i);
	vector<int> ret;
	while (!minStack.empty())
		ret.push_back(minStack.popMin());
	return ret;
}

auto compareMethod(vector<int> &a)
{
	vector<int> istack;
	for (auto i : a)
		istack.push_back(i);
	vector<int> ret;
	while (!istack.empty())
	{
		ret.push_back(*min_element(istack.begin(), istack.end()));
		istack.pop_back();
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

template <typename T>
bool isEqual(T &lhs, T &rhs)
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
		//testMethod(vecTest);
		//compareMethod(vecTrue);
		auto TestResult = testMethod(vecTest);
		auto CompareResult = compareMethod(vecTrue);
		if (!isEqual(TestResult, CompareResult))
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

