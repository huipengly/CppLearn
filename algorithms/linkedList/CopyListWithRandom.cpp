/**
 * @file CopyListWithRandom.cpp
 * @author huipengly
 * @brief 复制含有随机指针节点的链表
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

// 随机链表
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}

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

class Solution1 {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		// 使用map来记录新节点和旧节点
		unordered_map<RandomListNode *, RandomListNode *> nodeMap;

		auto *curr = head;
		auto *newHead = new RandomListNode(-1);
		auto *newCurr = newHead;
		while (curr != nullptr)			// 第一遍拷贝，拷贝顺序链表
		{
			newCurr->next = new RandomListNode(curr->label);
			newCurr = newCurr->next;
			nodeMap[curr] = newCurr;
			curr = curr->next;
		}
		curr = head;
		newCurr = newHead->next;
		while (curr != nullptr)
		{
			newCurr->random = nodeMap[curr->random];
			newCurr = newCurr->next;
			curr = curr->next;
		}
		return newHead->next;
	}
};

class Solution2 {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == nullptr)
			return head;

		// 第一遍拷贝，将拷贝的节点放到原节点后面
		auto *curr = head;
		while (curr != nullptr)
		{
			auto Node = new RandomListNode(curr->label);
			Node->next = curr->next;
			curr->next = Node;
			curr = Node->next;
		}

		// 第二遍拷贝，将新节点的random解决
		curr = head;
		while (curr != nullptr)
		{
			if (curr->random != nullptr)		// random可能为空
				curr->next->random = curr->random->next;
			curr = curr->next->next;
		}

		// 第三遍，将两个链表分离
		auto *originHead = new RandomListNode(-1);
		auto *copyHead = new RandomListNode(-1);
		curr = head;
		auto originCurr = originHead;
		auto copyCurr = copyHead;
		while (curr != nullptr)
		{
			originCurr->next = curr;
			copyCurr->next = curr->next;
			curr = curr->next->next;
			originCurr = originCurr->next;
			copyCurr = copyCurr->next;
		}
		originCurr->next = nullptr;
		copyCurr->next = nullptr;
		head = originHead->next;

		auto *ret = copyHead->next;
		delete originHead, copyHead;

		return ret;
	}
};

int main()
{
	RandomListNode *r1{ new RandomListNode(1) }, *r2{ new RandomListNode(2) }, *r3{ new RandomListNode(3) }, *r4{ new RandomListNode(4) };
	//r1->next = r2;
	//r2->next = r3;
	//r3->next = r4;
	//r1->random = r3;
	//r2->random = r1;
	//r3->random = r4;
	//r4->random = r3;

	Solution2 s;

	auto *ret = s.copyRandomList(r1);
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