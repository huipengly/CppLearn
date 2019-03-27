#include <iostream>
#include <string>
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
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr)
			return;

		swap(pRoot->left, pRoot->right);

		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};

//class Solution {
//public:
//	void Mirror(TreeNode *pRoot) {
//		pRoot = MirrorTree(pRoot);
//	}
//private:
//	TreeNode *MirrorTree(TreeNode *pRoot)
//	{
//		if (pRoot == nullptr)
//			return pRoot;
//
//      这个就耦合了交换和镜像，拆开之后就特别简单，而且不需要返回头节点
//		auto *ltemp = MirrorTree(pRoot->right);
//		pRoot->right = MirrorTree(pRoot->left);
//		pRoot->left = ltemp;
//		return pRoot;
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
	head->right = new TreeNode(3);

	cout << head << endl;

	Solution s;
	s.Mirror(head);
	cout << head << endl;

	return 0;
}