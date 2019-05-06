#include <string>
#include <iomanip>
#include <algorithm>
#include <iostream>
using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int largestBSTSubtree(TreeNode* root) {
		if (root == nullptr)
			return 0;
		return process(root).maxBSTSize;
	}
	TreeNode* largestBSTSubtreeHead(TreeNode* root) {
		if (root == nullptr)
			return 0;
		return process(root).maxBSTHead;
	}
private:
	struct ReturnType
	{
		TreeNode* maxBSTHead;
		int maxBSTSize;
		int min;
		int max;

		ReturnType(TreeNode* maxBSTHead, int maxBSTSize, int min, int max)
			: maxBSTHead(maxBSTHead), maxBSTSize(maxBSTSize), min(min), max(max) {}
	};
	ReturnType process(TreeNode* root)
	{
		if (root == nullptr)
			return ReturnType(nullptr, 0, INT_MAX, INT_MIN);
		auto lData = process(root->left);
		auto rData = process(root->right);

		int min = std::min(root->val, std::min(lData.min, rData.min));
		int max = std::max(root->val, std::max(lData.max, rData.max));
		int maxBSTSize = std::max(lData.maxBSTSize, rData.maxBSTSize);
		TreeNode* maxBSTHead = lData.maxBSTSize > rData.maxBSTSize ? lData.maxBSTHead : rData.maxBSTHead;
		if (root->left == lData.maxBSTHead && root->right == rData.maxBSTHead
			&& root->val > lData.max && root->val < rData.min)
		{
			maxBSTSize = lData.maxBSTSize + rData.maxBSTSize + 1;
			maxBSTHead = root;
		}
		return ReturnType(maxBSTHead, maxBSTSize, min, max);
	}
};

// 打印二叉树
void printInOrder(const TreeNode* head, int len, char to, int height, ostream& os)
{
	if (head == nullptr)
		return;

	printInOrder(head->right, len + 1, 'v', height, os);
	std::string val = to + to_string(head->val) + to;
	os << setw(height * (len + 1)) << val << endl;
	printInOrder(head->left, len + 1, '^', height, os);
}

void printTree(const TreeNode * head, ostream & os)
{
	os << "Binary Tree:" << endl;
	printInOrder(head, 0, 'H', 17, os);
	os << endl;
}

ostream& operator<<(ostream & os, const TreeNode * head)
{
	printTree(head, os);
	return os;
}
// 打印二叉树

int main()
{
	Solution s;
	TreeNode* head = new TreeNode(6);
	head->left = new TreeNode(1);
	head->left->left = new TreeNode(0);
	head->left->right = new TreeNode(3);

	head->right = new TreeNode(12);
	head->right->left = new TreeNode(10);
	head->right->left->left = new TreeNode(4);
	head->right->left->left->left = new TreeNode(2);
	head->right->left->left->right = new TreeNode(5);
	head->right->left->right = new TreeNode(14);
	head->right->left->right->left = new TreeNode(11);
	head->right->left->right->right = new TreeNode(15);
	head->right->right = new TreeNode(13);
	head->right->right->left = new TreeNode(20);
	head->right->right->right = new TreeNode(16);

	cout << head << endl << endl;
	cout << s.largestBSTSubtreeHead(head) << endl;
	cout << s.largestBSTSubtree(head) << endl;

	return 0;
}