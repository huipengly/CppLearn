struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		height = mostLevelLeft(root, 0);
		return countNodes(root, 1);
	}
private:
	int height;
	int countNodes(TreeNode* root, int level)
	{
		if (level > height)
			return 0;
		int rightHeight = mostLevelLeft(root->right, level);
		int counter = 0;
		if (rightHeight == height)		// 左边为完全二叉树
			counter += (1 << (height - level)) + countNodes(root->right, level + 1);
		else							// 右边为完全二叉树
			counter += countNodes(root->left, level + 1) + (1 << (height - level - 1));
		return counter;
	}
	int mostLevelLeft(TreeNode* root, int level)
	{
		while (root != nullptr)
		{
			++level;
			root = root->left;
		}
		return level;
	}
};