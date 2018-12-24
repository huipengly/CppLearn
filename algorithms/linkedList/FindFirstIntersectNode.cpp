/**
 * @file Template.cpp
 * @author huipengly
 * @brief 写笔试题目的c++模板
 * @version 0.1
 * @date 2018-12-20
 * 
 * @note 包含了常用的库文件，随机数引擎，测试程序
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
	ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

// 链表结构，使用智能指针
struct ListNodeUseSharedPtr {
   int val;
   shared_ptr<ListNode> next;		// 自动回收内存
   ListNodeUseSharedPtr(int x) : val(x), next(NULL) {}
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
ostream& operator<<(ostream &os, const ListNode *head);

ListNode *detectCycle(ListNode *head) {
	auto *slow = head, *fast = head;
	while (slow != nullptr && fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			fast = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}
	return false;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	auto *pA{ headA }, *pB{ headB };

	while (pA != pB)
	{
		if (pA != nullptr)
			pA = pA->next;
		else
			pA = headB;

		if (pB != nullptr)
			pB = pB->next;
		else
			pB = headA;
	}

	return pA;
}

ListNode *FindFirstIntersectNode(ListNode *headA, ListNode *headB)
{
	auto *loop1 = detectCycle(headA);
	auto *loop2 = detectCycle(headB);
	ListNode *ret = nullptr;

	if (loop1 == nullptr && loop2 == nullptr)
	{
		ret = getIntersectionNode(headA, headB);
	}
	else if (loop1 != nullptr && loop2 != nullptr)
	{
		if (loop1 == loop2)				// 情况1：环前相交
		{
			auto *tempNext = loop1->next;
			loop1->next = nullptr;		// 切断环，变为相交线
			ret = getIntersectionNode(headA, headB);
			loop1->next = tempNext;
		}
		else
		{
			auto *curr = loop1->next;
			while (curr != loop1)
			{
				if (curr == loop2)		// 找到loop1前，先遇到了loop2，情况3：交点在环内
				{
					ret = loop1;
					break;
				}
				curr = curr->next;
			}
		}
	}

	return ret;
}

int main()
{
	ListNode *n1{ new ListNode(1) }, *n2{ new ListNode(2) }, *n3{ new ListNode(3) }, *n4{ new ListNode(4) }, *n5{ new ListNode(5) }, *n6{ new ListNode(6) };

	//// 两个无环不相交
	//n1->next = n2;
	//n3->next = n4;
	//cout << FindFirstIntersectNode(n1, n3);
	//cout << endl;

	//// 两个无环相交
	//n1->next = n2;
	//n2->next = n3;
	//n3->next = n4;
	//cout << FindFirstIntersectNode(n1, n3);
	//cout << endl;

	//// 两个都有环不相交
	n1->next = n2;
	n2->next = n3;
	n3->next = n2;
	n4->next = n5;
	n5->next = n6;
	n6->next = n5;
	cout << FindFirstIntersectNode(n1, n4);
	cout << endl;

	//// 两个都有环，交点在环前
	//n1->next = n2;
	//n2->next = n5;
	//n5->next = n6;
	//n3->next = n4;
	//n4->next = n5;
	//n6->next = n5;
	////cout << "两个都有环，交点在环前: ";
	//cout << FindFirstIntersectNode(n1, n3)->val;
	//cout << endl;

	//// 两个都有环，交点在环里
	//n1->next = n2;
	//n2->next = n5;
	//n5->next = n4;
	//n4->next = n2;
	//n3->next = n4;

	//n6->next = nullptr;
	////cout << "两个都有环，交点在环里：";
	//cout << FindFirstIntersectNode(n1, n3)->val;
	//cout << endl;

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

ostream &operator<<(ostream & os, const ListNode * head)
{
	auto *curr = head;
	while (curr != nullptr)
	{
		os << curr->val << " ";
		curr = curr->next;
	}
	return os;
}