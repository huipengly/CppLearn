/**
 * @file Template.cpp
 * @author huipengly
 * @brief 使用数组实现堆栈、队列
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
#include <ctime>
#include <queue>
#include <stack>

using namespace std;

std::random_device rd;			// 用来播种
default_random_engine e(rd());	// 随机数引擎
// uniform_int_distribution<int> u(0, 10);	// 产生一个[0, 10]的随机整数分布
// uniform_real_distribution<double> u(0, 10);	// 产生一个[0, 10)的随机实数分布
// int rand = u(e);	//产生随机数

class ArrayStack
{
public:
	ArrayStack() : index_(0) {}
	void push(int i);
	int top();
	void pop();
	bool empty() { return index_ == 0; }

private:
	int array[10];
	int index_;
};

void ArrayStack::push(int i)
{
	if (index_ == 10)
		throw std::overflow_error("out of range.");
	array[index_++] = i;
}

int ArrayStack::top()
{
	if (index_ == 0)
		throw std::overflow_error("stack is empty.");
	return array[index_ - 1];
}

void ArrayStack::pop()
{
	if (index_ == 0)
		throw std::overflow_error("stack is empty.");
	--index_;
}

class ArrayQueue
{
public:
	ArrayQueue() : start_(0), end_(0), size_(0) {}
	void push(int i);
	int top();
	void pop();
	bool empty() { return size_ == 0; }

private:
	int array[10];
	int start_, end_;	// start在指向第一个元素，end指向最后一个元素之后
	int size_;
};

void ArrayQueue::push(int i)
{
	if (size_ == 10)
		throw std::overflow_error("out of range.");
	array[end_++] = i;
	++size_;
	if (end_ == 10)
		end_ = 0;
}

int ArrayQueue::top()
{
	if (size_ == 0)
		throw std::overflow_error("queue is empty.");
	return array[start_];
}

void ArrayQueue::pop()
{
	if (size_ == 0)
		throw std::overflow_error("queue is empty.");
	++start_;
	--size_;
	if (start_ == 10)
		start_ = 0;
}


// for test
auto testMethod(vector<int> &a)
{
	ArrayQueue iqueue;
	vector<int> ret;
	for (auto i : a)
		iqueue.push(i);
	while (!iqueue.empty())
	{
		ret.push_back(iqueue.top());
		iqueue.pop();
	}
	return ret;
}

auto compareMethod(vector<int> &a)
{
	queue<int> iqueue;
	vector<int> ret;
	for (auto i : a)
		iqueue.push(i);
	while (!iqueue.empty())
	{
		ret.push_back(iqueue.front());
		iqueue.pop();
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
	int maxSize = 5;
	int maxValue = 200;
	bool succeed = true;
	for (int i = 0; i != testTime; ++i)
	{
		auto vecTest = generateRandomArray(maxSize, maxValue);
		auto vecTrue = vecTest;
		auto origin = vecTest;
		auto resultTest = 	 testMethod(vecTest);
		auto resultCompare = compareMethod(vecTrue);
		if (!isEqual(resultTest, resultCompare))
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
