/**
 * @file Template.cpp
 * @author huipengly
 * @brief 链表划分
 * @version 0.1
 * @date 2018-12-24
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
#include <memory>

using namespace std;

std::random_device rd;			// 用来播种
default_random_engine e(rd());	// 随机数引擎
// uniform_int_distribution<int> u(0, 10);	// 产生一个[0, 10]的随机整数分布
// uniform_real_distribution<double> u(0, 10);	// 产生一个[0, 10)的随机实数分布
// int rand = u(e);	//产生随机数

// shared_ptr<int> pint = make_shared<int>();   // 智能指针&申请内存

// 链表结构
struct ListNode {
    int val;
    //shared_ptr<ListNode> next;		// 自动回收内存
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//// 双向链表结构
// struct DoublyListNode {
//     int val;
// 	shared_ptr<DoublyListNode> pre;
//     shared_ptr<DoublyListNode> next;
// 	//ListNode *pre;
// 	//ListNode *next;
// 	DoublyListNode(int x) : val(x), pre(NULL), next(NULL) {}
// };

// 测试用
auto testMethod(vector<int> &a);
auto compareMethod(vector<int> &a);
vector<int> generateRandomArray(int maxSize, int maxValue);
template <typename T> bool isEqual(T &lhs, T &rhs);
void test();

// 打印二维vector
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &matrix);

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode *lessHead(new ListNode(-1)), *equalHead(new ListNode(-1)), *moreHead(new ListNode(-1));
		auto *less{ lessHead }, *equal{ equalHead }, *more{ moreHead };

		auto *curr = head;
		while (curr != nullptr)
		{
			if (curr->val < x)
			{
				less->next = curr;
				less = less->next;
			}
			else if (curr->val > x)
			{
				more->next = curr;
				more = more->next;
			}
			else
			{
				equal->next = curr;
				equal = equal->next;
			}
			auto temp_curr_next = curr->next;
			curr->next = nullptr;
			curr = temp_curr_next;
		}

		// 拼接三个链表
		if (lessHead->next != nullptr)
		{
			if (equalHead->next != nullptr)
			{
				less->next = equalHead->next;
				equal->next = moreHead->next;
			}
			else if (moreHead->next != nullptr)
				less->next = moreHead->next;
			return lessHead->next;
		}
		else if (equalHead->next != nullptr)
		{
			equalHead->next = moreHead->next;
			return equalHead->next;
		}
		else
			return moreHead->next;
	}
};

int main()
{
	ListNode *n1{ new ListNode(1) }, *n2{ new ListNode(4) }, *n3{ new ListNode(3) }, *n4{ new ListNode(2) }, *n5{ new ListNode(5) }, *n6{ new ListNode(2) };
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	Solution s;
	auto *ret = s.partition(n1, 3);
    return 0;
}

// 以下为测试用代码
auto testMethod(vector<int> &a)
{
	// 测试方法
}

auto compareMethod(vector<int> &a)
{
	// 对的方法
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
	int maxSize = 20;
	int maxValue = 200;
	bool succeed = true;
	for (int i = 0; i != testTime; ++i)
	{
		auto TestData = generateRandomArray(maxSize, maxValue);
		auto TrueData = TestData;
		auto OriginData = TestData;

#define NO_RETURN_VALUE
//#define HAS_RETURN_VALUE

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

template <typename T>
ostream& operator<<(ostream &os, const vector<vector<T>> &matrix)
{
	if (matrix.empty())
		return os;
	auto rowSize = matrix.size();			// 行大小
	auto colSize = matrix[0].size();		// 列大小
	for (int i = 0; i != rowSize; ++i)
	{
		for (int j = 0; j != colSize; ++j)
		{
			os << matrix[i][j] << ", \t";
		}
		os << "\n";
	}
}