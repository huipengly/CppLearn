/**
 * @file 145. Binary Tree Postorder Traversal.cpp
 * @author huipengly
 * @brief 二叉树前序、中序、后序遍历
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
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &matrix);
ostream& operator<<(ostream &os, const ListNode *head);

// 递归先序遍历
class Solution1 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if (root == nullptr)
			return order;
		order.push_back(root->val);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
		return order;
	}
	vector<int> inorderTraversal(TreeNode* root) {
		if (root == nullptr)
			return order;
		inorderTraversal(root->left);
		order.push_back(root->val);
		inorderTraversal(root->right);
		return order;
	}
	vector<int> postorderTraversal(TreeNode* root) {
		if (root == nullptr)
			return order;
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		order.push_back(root->val);
		return order;
	}
private:
	vector<int> order;
};

// 非递归，使用栈
class Solution2 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> order;
		if (root == nullptr)
			return order;
		stack<TreeNode*> stack;

		stack.push(root);
		while (!stack.empty())
		{
			root = stack.top();
			order.push_back(root->val);
			stack.pop();
			if (root->right != nullptr)
				stack.push(root->right);
			if (root->left != nullptr)
				stack.push(root->left);
		}
		return order;
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> order;
		stack<TreeNode *> stack;
		auto *curr = root;

		while (!stack.empty() || curr != nullptr)
		{
			// 当前节点不为空，则将所有左节点入栈
			while (curr != nullptr)
			{
				stack.push(curr);
				curr = curr->left;
			}

			// 出栈，打印节点，并将当前节点指向出栈节点的右节点
			curr = stack.top();
			stack.pop();
			order.push_back(curr->val);
			curr = curr->right;
		}

		return order;
	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> reverseOrder;
		if (root == nullptr)
			return reverseOrder;
		stack<TreeNode*> stack;

		stack.push(root);
		while (!stack.empty())
		{
			root = stack.top();
			reverseOrder.push_back(root->val);
			stack.pop();
			if (root->left != nullptr)
				stack.push(root->left);
			if (root->right != nullptr)
				stack.push(root->right);
		}
		return vector<int>(reverseOrder.rbegin(), reverseOrder.rend());
	}
};

int main()
{
	TreeNode *t1{ new TreeNode(1) }, *t2{ new TreeNode(2) }, *t3{ new TreeNode(4) };
	t1->right = t2;
	t2->left = t3;

	Solution2 s;
	cout << s.postorderTraversal(t1);
	cout << endl;
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