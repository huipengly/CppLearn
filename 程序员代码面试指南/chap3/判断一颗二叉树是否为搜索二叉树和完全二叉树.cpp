#include <stack>
#include <queue>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

bool isValidBST(TreeNode* root) {
	if (root == nullptr)
		return true;

	TreeNode* pre = nullptr;
	stack<TreeNode*> stack;
	while (!stack.empty() || root != nullptr)
	{
		if (root != nullptr)
		{
			stack.push(root);
			root = root->left;
		}
		else
		{
			root = stack.top();
			stack.pop();
			if (pre != nullptr && root->val <= pre->val)
				return false;
			pre = root;
			root = root->right;
		}
	}
	return true;
}

bool isCompleteTree(TreeNode* root) {
	if (root == nullptr)
		return true;

	bool leafNode = false;
	TreeNode* node = nullptr;
	queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty())
	{
		node = queue.front();
		queue.pop();
		if (leafNode && (node->left != nullptr || node->right != nullptr))
		{
			return false;
		}
		else
		{
			if (node->right != nullptr && node->left == nullptr)
				return false;

			if (node->left != nullptr)
				queue.push(node->left);
			else
				leafNode = true;

			if (node->right != nullptr)
				queue.push(node->right);
			else
				leafNode = true;
		}
	}
	return true;
}