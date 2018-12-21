/**
 * @file Template.cpp
 * @author huipengly
 * @brief 反转单向链表
 * @version 0.1
 * @date 2018-12-20
 * 
 * @note 两个指针，一个指向前一个节点，一个指向当前节点，每次将当前节点的next指向前一个节点。直到当前节点为空，返回前一个节点
 * 递归方法：假设当前除了头节点都已经反转，然后递归
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

// 测试用
auto testMethod(vector<int> &a);
auto compareMethod(vector<int> &a);
vector<int> generateRandomArray(int maxSize, int maxValue);
template <typename T> bool isEqual(T &lhs, T &rhs);
void test();

// 打印二维vector
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &matrix);

class Solution2 {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *pre = NULL;
		ListNode *curr = head;
		while (curr != NULL)
		{
			auto temp = curr->next;
			curr->next = pre;
			pre = curr;
			curr = temp;
		}
		return pre;
	}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		auto rhead = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return rhead;
	}
};

int main()
{
	Solution s;
	ListNode *n1{ new ListNode(1) }, *n2{ new ListNode(2) }, *n3{ new ListNode(3) }, *n4{ new ListNode(4) }, *n5{ new ListNode(5) };
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	auto ret = s.reverseList(n1);
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