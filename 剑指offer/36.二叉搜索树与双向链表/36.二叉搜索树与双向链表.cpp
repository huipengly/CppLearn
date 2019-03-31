#include <iostream>
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
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr || (pRootOfTree->left == nullptr && pRootOfTree->right == nullptr))
			return pRootOfTree;

		TreeNode *left = Convert(pRootOfTree->left);
		TreeNode *right = Convert(pRootOfTree->right);

		auto *ptr = left;
		while (ptr != nullptr && ptr->right != nullptr)
			ptr = ptr->right;

		if (ptr == nullptr)
		{
			left = pRootOfTree;
		}
		else
		{
			ptr->right = pRootOfTree;
			pRootOfTree->left = ptr;
			pRootOfTree->right = right;
		}
		ptr = pRootOfTree;

		if (right != nullptr)
		{
			right->left = ptr;
		}
		return left;
	}
};

int main()
{
	TreeNode *head = new TreeNode(10);
	head->left = new TreeNode(6);
	head->right = new TreeNode(14);
	head->left->left = new TreeNode(4);
	//head->left->right = new TreeNode(8);
	//head->right->left = new TreeNode(12);
	head->right->right = new TreeNode(16);
	Solution s;
	auto *ret = s.Convert(head);
	while (ret != nullptr)
	{
		cout << ret->val << endl;
		ret = ret->right;
	}
	return 0;
}