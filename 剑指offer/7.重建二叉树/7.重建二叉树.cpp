/**
 * @file Template.cpp
 * @author huipengly
 * @brief 写笔试题目的c++模板
 * @version 0.1
 * @date 2018-12-25
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
#include <sstream>
#include <cmath>

using namespace std;

// 加速流读写
static const int _ = []() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

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

// 打印用
template <typename T>
ostream& operator<<(ostream &os, const vector<T> &array);			// 打印vector
template <typename T>
ostream& operator<<(ostream &os, const vector<vector<T>> &matrix);	// 打印二维vector
ostream& operator<<(ostream &os, const ListNode *head);				// 打印链表
ostream &operator<<(ostream &os, const TreeNode *head);				// 打印二叉树

// 功能性函数
queue<string> splitString(const string &str, char c);				// 分割字符串
TreeNode *makeCBT(int nodeNum);										// 生成拥有n个节点的完全二叉树
void postorderFree(TreeNode* root);									// 后序遍历法释放二叉树内存


/********************下面写代码********************/

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty())
			return nullptr;

		TreeNode *root = new TreeNode(pre.front());
		auto root_it = find(vin.begin(), vin.end(), root->val);
		auto index = root_it - vin.begin();

		root->left = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.begin() + index + 1), vector<int>(vin.begin(), root_it));
		root->right = reConstructBinaryTree(vector<int>(pre.begin() + index + 1, pre.end()), vector<int>(root_it + 1, vin.end()));

		return root;
	}
};

/********************上面写代码********************/


int main()
{
	Solution s;
	auto* ret = s.reConstructBinaryTree({ 1, 2, 4, 7, 3, 5, 6, 8 }, { 4, 7, 2, 1, 5, 3, 8, 6 });
	cout << ret;
	return 0;
}

// 以下为测试用代码
auto testMethod(vector<int> &a)
{
	// 测试方法
}

auto compareMethod(vector<int> &a)
{
	// 正确方法
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
	for (int i = 0; i != array.size() - 1; ++i)
		os << array[i] << "\t,";
	os << array.back();
	return os;
}

template <typename T>
ostream& operator<<(ostream &os, const vector<vector<T>> &matrix)
{
	for (int i = 0; i != matrix.size(); ++i)
	{
		for (int j = 0; j != matrix[i].size() - 1; ++j)
		{
			os << matrix[i][j] << ",\t";
		}
		cout << matrix[i].back() << "\n";
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

void printInOrder(const TreeNode *head, int height, string to, int len, ostream &os)
{
	if (head == nullptr)
		return;
	printInOrder(head->right, height + 1, "v", len, os);
	string val = to + to_string(head->val) + to;
	int lenM = val.length();
	int lenL = (len - lenM) / 2;
	int lenR = len - lenM - lenL;
	val = string(lenL, ' ') + val + string(lenL, ' ');
	os << string(height * len, ' ') + val << endl;
	printInOrder(head->left, height + 1, "^", len, os);
}

void printTree(const TreeNode *head, ostream &os)
{
	os << "Binary Tree:" << endl;
	printInOrder(head, 0, "H", 17, os);
	os << endl;
}

ostream &operator<<(ostream &os, const TreeNode *head)
{
	printTree(head, os);
	return os;
}

queue<string> splitString(const string &str, char c)
{
	istringstream streamStr(str);
	string temp;
	queue<string> queue;
	while (getline(streamStr, temp, c))
		queue.push(temp);
	return queue;
}

TreeNode *makeCBT(int nodeNum)
{
	if (nodeNum == 0)
		return nullptr;
	TreeNode *head = new TreeNode(1);
	queue<TreeNode *> queue;
	queue.push(head);
	int i = 2;
	while (i <= nodeNum)
	{
		auto *front = queue.front();
		queue.pop();
		front->left = new TreeNode(i++);
		queue.push(front->left);
		if (i <= nodeNum)
		{
			front->right = new TreeNode(i++);
			queue.push(front->right);
		}
	}
	return head;
}

void postorderFree(TreeNode* root)
{
	if (root == nullptr)
		return;

	if (root->left == nullptr && root->right == nullptr)
	{
		delete root;
		return;
	}

	postorderFree(root->left);
	postorderFree(root->right);
	delete root;
}