/**
 * @file Template.cpp
 * @author huipengly
 * @brief 直观打印二叉树
 * @version 0.1
 * @date 2018-12-25
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

// 双向链表结构
struct DoublyListNode {
	int val;
	shared_ptr<DoublyListNode> pre;
	shared_ptr<DoublyListNode> next;
	//ListNode *pre;
	//ListNode *next;
	DoublyListNode(int x) : val(x), pre(NULL), next(NULL) {}
};

// 二叉树节点
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 测试用
auto testMethod(vector<int> &a);
auto compareMethod(vector<int> &a);
vector<int> generateRandomArray(int maxSize, int maxValue);
template <typename T> bool isEqual(T &lhs, T &rhs);
void test();

// 打印vector
template <typename T> ostream& operator<<(ostream &os, const vector<T> &array);
ostream& operator<<(ostream &os, const ListNode *head);
// 打印二叉树
void printTree(TreeNode *head);

int main()
{
	TreeNode *head{ new TreeNode(1) };
	head->left = new TreeNode(-2222);
	head->right = new TreeNode(3);
	head->left->left = new TreeNode(INT_MIN);
	head->right->left = new TreeNode(555);
	head->right->right = new TreeNode(66666);
	head->left->left->right = new TreeNode(777);

	printTree(head);

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
ostream& operator<<(ostream &os, const vector<T> &array)
{
	for (auto &i : array)
		os << i << ", \t";
	return os;
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
	return os;
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

void printInOrder(TreeNode *head, int height, string to, int len)
{
	if (head == nullptr)
		return;
	printInOrder(head->right, height + 1, "v", len);
	string val = to + to_string(head->val) + to;
	int lenM = val.length();
	int lenL = (len - lenM) / 2;
	int lenR = len - lenM - lenL;
	val = string(lenL, ' ') + val + string(lenL, ' ');
	cout << string(height * len, ' ') + val << endl;
	printInOrder(head->left, height + 1, "^", len);
}

// 右中左遍历，然后输出，格式对齐，每一个元素17位，不足则补全空格
void printTree(TreeNode *head)
{
	cout << "Binary Tree:" << endl;
	printInOrder(head, 0, "H", 17);
	cout << endl;
}