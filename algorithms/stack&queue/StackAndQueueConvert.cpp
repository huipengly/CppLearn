/**
 * @file StackAndQueueConvert.cpp
 * @author huipengly
 * @brief 队列实现栈/栈实现队列
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

// 测试用
auto testMethod(vector<int> &a);
auto compareMethod(vector<int> &a);
vector<int> generateRandomArray(int maxSize, int maxValue);
template <typename T> bool isEqual(T &lhs, T &rhs);
void test();

template <typename T>
class StackUseQueue
{
public:
	void push(T t);
	T pop();
	bool empty() { return queue_.empty(); }

private:
	queue<T> queue_;
};

template<typename T>
void StackUseQueue<T>::push(T t)
{
	queue_.push(t);
}

template<typename T>
T StackUseQueue<T>::pop()
{
	for (int i = queue_.size(); i != 1; --i)
	{
		auto top = queue_.front();
		queue_.pop();
		queue_.push(top);
	}
	auto ret = queue_.front();
	queue_.pop();
	return ret;
}

template <typename T>
class QueueUseStack
{
public:
	void push(T t);
	T pop();
	bool empty() { return inStack.empty() && outStack.empty(); }

private:
	stack<T> inStack, outStack;
};

template<typename T>
void QueueUseStack<T>::push(T t)
{
	inStack.push(t);
}

template<typename T>
T QueueUseStack<T>::pop()
{
	if (outStack.empty())
	{
		while (!inStack.empty())
		{
			outStack.push(inStack.top());
			inStack.pop();
		}
	}
	auto ret = outStack.top();
	outStack.pop();
	return ret;
}

int main()
{
	test();
    return 0;
}

// 以下为测试用代码
auto testMethod(vector<int> &a)
{
	// 测试方法
	QueueUseStack<int> mystack;
	for (auto i : a)
		mystack.push(i);
	vector<int> ret;
	while (!mystack.empty())
	{
		ret.push_back(mystack.pop());
	}
	return ret;
}

auto compareMethod(vector<int> &a)
{
	// 对的方法
	queue<int> mystack;
	for (auto i : a)
		mystack.push(i);
	vector<int> ret;
	while (!mystack.empty())
	{
		ret.push_back(mystack.front());
		mystack.pop();
	}
	return ret;
}

// 产生随机大小，数目的数组
vector<int> generateRandomArray(int maxSize, int maxValue)
{
	uniform_int_distribution<unsigned> uValue(0, maxValue);
	uniform_int_distribution<unsigned> uSize(0, maxSize);
	vector<int> vec(uSize(e));
	for (auto &i : vec)
		i = uValue(e);
	return vec;
}

// 判断结果是否相等
template <typename T>
bool isEqual(T &lhs, T &rhs)
{
	return lhs == rhs;
}

void test()
{
	int testTime = 50000;
	int maxSize = 10;
	int maxValue = 200;
	bool succeed = true;
	for (int i = 0; i != testTime; ++i)
	{
		auto TestData = generateRandomArray(maxSize, maxValue);
		auto TrueData = TestData;
		auto OriginData = TestData;

//#define NO_RETURN_VALUE
#define HAS_RETURN_VALUE

#ifdef NO_RETURN_VALUE
		// 无返回类型的判断
		testMethod(TestData);
		compareMethod(TrueData);
		if (!isEqual(TestData, TrueData))
		{
			succeed = false;
			break;
		}
#endif

#ifdef HAS_RETURN_VALUE
		// 有返回类型的判断
		auto TestResult = testMethod(TestData);
		auto CompareResult = compareMethod(TrueData);
		if (!isEqual(TestResult, CompareResult))
		{
			succeed = false;
			break;
		}
#endif
	}

	cout << (succeed ? "passed" : "BUG!") << endl;
}