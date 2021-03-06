/**
 * @file Template.cpp
 * @author huipengly
 * @brief 后继节点
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
	TreeNode *parent;
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

TreeNode *getLeftMost(TreeNode *node)
{
	if (node == nullptr)
		return node;

	while (node->left != nullptr)
		node = node->left;

	return node;
}

TreeNode *getLeftParent(TreeNode *node)
{

	return node->parent;
}

TreeNode *InorderSuccessorInBst(TreeNode *node)
{
	if (node == nullptr)
		return node;

	if (node->right != nullptr)
		return getLeftMost(node->right);
	else	// 得到当前节点是父节点的左子节点
	{
		while (node->parent != nullptr && node->parent->left != node)
		{
			node = node->parent;
		}
		return node->parent;
	}
}

int main()
{
	TreeNode *head = new TreeNode(6);
	head->parent = nullptr;
	head->left = new TreeNode(3);
	head->left->parent = head;
	head->left->left = new TreeNode(1);
	head->left->left->parent = head->left;
	head->left->left->right = new TreeNode(2);
	head->left->left->right->parent = head->left->left;
	head->left->right = new TreeNode(4);
	head->left->right->parent = head->left;
	head->left->right->right = new TreeNode(5);
	head->left->right->right->parent = head->left->right;
	head->right = new TreeNode(9);
	head->right->parent = head;
	head->right->left = new TreeNode(8);
	head->right->left->parent = head->right;
	head->right->left->left = new TreeNode(7);
	head->right->left->left->parent = head->right->left;
	head->right->right = new TreeNode(10);
	head->right->right->parent = head->right;

	printTree(head);

	TreeNode *test = head->left->left;
	cout << to_string(test->val) + " next: " + to_string(InorderSuccessorInBst(test)->val) << endl;
	test = head->left->left->right;
	cout << to_string(test->val) + " next: " + to_string(InorderSuccessorInBst(test)->val) << endl;
	test = head->left;
	cout << to_string(test->val) + " next: " + to_string(InorderSuccessorInBst(test)->val) << endl;
	test = head->left->right;
	cout << to_string(test->val) + " next: " + to_string(InorderSuccessorInBst(test)->val) << endl;
	test = head->left->right->right;
	cout << to_string(test->val) + " next: " + to_string(InorderSuccessorInBst(test)->val) << endl;
	test = head;
	cout << to_string(test->val) + " next: " + to_string(InorderSuccessorInBst(test)->val) << endl;
	test = head->right->left->left;
	cout << to_string(test->val) + " next: " + to_string(InorderSuccessorInBst(test)->val) << endl;
	test = head->right->left;
	cout << to_string(test->val) + " next: " + to_string(InorderSuccessorInBst(test)->val) << endl;
	test = head->right;
	cout << to_string(test->val) + " next: " + to_string(InorderSuccessorInBst(test)->val) << endl;
	test = head->right->right; // 10's next is null
	auto ret = InorderSuccessorInBst(test);
	cout << to_string(test->val) + " next: " + (InorderSuccessorInBst(test) == nullptr ? "null" : "not null") << endl;
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

void printTree(TreeNode *head)
{
	cout << "Binary Tree:" << endl;
	printInOrder(head, 0, "H", 17);
	cout << endl;
}