#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetrical(pRoot, pRoot);
	}
private:
	bool isSymmetrical(TreeNode *lhs, TreeNode *rhs)
	{
		if (lhs == nullptr && rhs == nullptr)
			return true;
		if (lhs == nullptr || rhs == nullptr)
			return false;
		if (lhs->val != rhs->val)
			return false;

		return isSymmetrical(lhs->left, rhs->right) &&
			isSymmetrical(lhs->right, rhs->left);
	}
}

// 记录值的方式不对，除非将空白也记录进来
//class Solution {
//public:
//	bool isSymmetrical(TreeNode* pRoot)
//	{
//		vector<int> parr, sarr;
//		preorder(pRoot, parr);
//		symmetry_preorder(pRoot, sarr);
//		return equal(parr.begin(), parr.end(), sarr.begin());
//	}
//private:
//	void preorder(TreeNode *pRoot, vector<int> &order)
//	{
//		if (pRoot != nullptr)
//		{
//			order.push_back(pRoot->val);
//			preorder(pRoot->left, order);
//			preorder(pRoot->right, order);
//		}
//	}
//	void symmetry_preorder(TreeNode *pRoot, vector<int> &order)
//	{
//		if (pRoot != nullptr)
//		{
//			order.push_back(pRoot->val);
//			symmetry_preorder(pRoot->right, order);
//			symmetry_preorder(pRoot->left, order);
//		}
//	}
//};

//class Solution {
//public:
//    bool isSymmetrical(TreeNode* pRoot)
//    {
//		auto *nRoot = copyTree(pRoot);
//		Mirror(nRoot);
//		auto ret = is_same_tree(pRoot, nRoot);
//		postorderFree(nRoot);
//		return ret;
//    }
//private:
//	TreeNode *copyTree(TreeNode *pRoot)
//	{
//		TreeNode *nRoot = nullptr;
//		if (pRoot != nullptr)
//		{
//			nRoot = new TreeNode(pRoot->val);
//			nRoot->left = copyTree(pRoot->left);
//			nRoot->right = copyTree(pRoot->right);
//		}
//		return nRoot;
//	}
//	void Mirror(TreeNode *pRoot) {
//		if (pRoot == nullptr)
//			return;
//
//		swap(pRoot->left, pRoot->right);
//
//		Mirror(pRoot->left);
//		Mirror(pRoot->right);
//	}
//	bool is_same_tree(TreeNode *lhs, TreeNode *rhs)		// 这个其实也可以改非递归，用一个queue维护就行
//	{
//		if (rhs == nullptr)			// B树判断完了，就说明是子树
//			return true;
//		else if (lhs == nullptr)	// A树完了，B没完，就不是子树
//			return false;
//
//		if (lhs->val != rhs->val)	// 有不同的节点，就不是子树
//			return false;
//		else						// 当前节点相同，继续判断子节点
//			return is_same_tree(lhs->left, rhs->left) && is_same_tree(lhs->right, rhs->right);
//	}
//	void postorderFree(TreeNode* root) {
//		if (root == nullptr)
//			return;
//
//		if (root->left == nullptr && root->right == nullptr)
//		{
//			delete root;
//			return;
//		}
//
//		postorderFree(root->left);
//		postorderFree(root->right);
//		delete root;
//	}
//};

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

int main()
{
	TreeNode *head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->left->left = new TreeNode(3);
	head->right = new TreeNode(2);
	head->right->right = new TreeNode(3);

	cout << head << endl;

	Solution s;
	cout << s.isSymmetrical(head) << endl;
	_CrtDumpMemoryLeaks();
	return 0;
}