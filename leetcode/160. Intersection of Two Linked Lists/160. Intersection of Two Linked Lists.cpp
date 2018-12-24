/**
 * @file Template.cpp
 * @author huipengly
 * @brief 无环单链表交叉判断
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

// 哈希表存储某个链表，查找另一个链表里有没有
// time: O(m+n) extra space: O(m) or O(n)
class Solution1 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_set<ListNode *> set;

		auto *currA = headA;
		auto *currB = headB;
		while (currA != nullptr)
		{
			set.insert(currA);
			currA = currA->next;
		}
		while (currB != nullptr)
		{
			if (set.count(currB))
				return currB;
			currB = currB->next;
		}
		return nullptr;
	}
};

// 判断长度，从距离终点等长的地方出发，如果有相同的，则为相交
class Solution2 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

		int LengthA = 0, LengthB = 0;
		auto *currA{ headA }, *currB{ headB };

		while (currA != nullptr)
		{
			currA = currA->next;
			++LengthA;
		}

		while (currB != nullptr)
		{
			currB = currB->next;
			++LengthB;
		}

		currA = headA;
		currB = headB;

		while (LengthA > LengthB)
		{
			--LengthA;
			currA = currA->next;
		}

		while (LengthA < LengthB)
		{
			--LengthB;
			currB = currB->next;
		}

		while (currA != nullptr)
		{
			if (currA == currB)
			{
				return currA;
			}
			currA = currA->next;
			currB = currB->next;
		}
		return nullptr;
	}
};

// 两个指针，分别从A,B链表头出发，如果走到尾，则从另一个链表头出发。两个指针相遇时，要么在两个不相交链表的尾部，要么在相交节点的相交点。
// 分情况讨论，即可得到原理
class Solution3 {
public:
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
};

int main()
{
	Solution1 s;
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