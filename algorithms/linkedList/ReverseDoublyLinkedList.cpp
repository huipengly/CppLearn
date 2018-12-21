/**
 * @file Template.cpp
 * @author huipengly
 * @brief 反转双向链表
 * @version 0.1
 * @date 2018-12-20
 * 
 * @note 交换节点的pre和next
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

//// 链表结构
//struct ListNode {
//    int val;
//    shared_ptr<ListNode> next;
//	//ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

//// 双向链表结构
struct DoublyListNode {
    int val;
	shared_ptr<DoublyListNode> pre;
    shared_ptr<DoublyListNode> next;
	//ListNode *pre;
	//ListNode *next;
	DoublyListNode(int x) : val(x), pre(NULL), next(NULL) {}
};

// 测试用
auto testMethod(vector<int> &a);
auto compareMethod(vector<int> &a);
vector<int> generateRandomArray(int maxSize, int maxValue);
template <typename T> bool isEqual(T &lhs, T &rhs);
void test();

// 打印二维vector
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &matrix);

shared_ptr<DoublyListNode> ReverseDoublyLinkedList(shared_ptr<DoublyListNode> head)
{
	if (head == NULL)
		return head;
	while (head->next != NULL)
	{
		std::swap(head->pre, head->next);
		head = head->pre;
	}
	std::swap(head->pre, head->next);
	return head;
}

int main()
{
	//test();
	shared_ptr<DoublyListNode> n1{ make_shared<DoublyListNode>(1) }, 
		n2{ make_shared<DoublyListNode>(2) }, 
		n3{ make_shared<DoublyListNode>(3) }, 
		n4{ make_shared<DoublyListNode>(4) },
		n5{ make_shared<DoublyListNode>(5) };

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	n5->pre = n4;
	n4->pre = n3;
	n3->pre = n2;
	n2->pre = n1;

	auto ret = ReverseDoublyLinkedList(NULL);

	while (ret != NULL)
	{
		cout << ret->val << ", ";
		ret = ret->next;
	}

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