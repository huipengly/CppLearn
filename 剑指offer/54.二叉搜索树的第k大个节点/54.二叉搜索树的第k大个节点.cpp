#include <cassert>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

// 中序遍历
class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == nullptr)
			return nullptr;

		TreeNode *ret = nullptr;
		if (pRoot->left != nullptr)
		{
			ret = KthNode(pRoot->left, k);
			if (ret != nullptr)
				return ret;
		}
		if (++counter == k)
		{
			return pRoot;
		}
		if (pRoot->right != nullptr)
		{
			ret = KthNode(pRoot->right, k);
			if (ret != nullptr)
				return ret;
		}
		return ret;
	}
private:
	int counter = 0;
};

int main()
{
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(7);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(8);
	Solution s;
	assert(s.KthNode(root, 3) == root->left->right);
	return 0;
}