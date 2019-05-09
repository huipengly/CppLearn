#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return process(root).isBalanced;
	}
private:
	struct BalanceInfo
	{
		bool isBalanced;
		int depth;
		BalanceInfo() : isBalanced(false), depth(0) {}
		BalanceInfo(bool isBalanced, int depth) : isBalanced(isBalanced), depth(depth) {}
	};
	BalanceInfo process(TreeNode* root)
	{
		if (root == nullptr)
			return BalanceInfo(true, 0);

		auto leftInfo = process(root->left);
		auto rightInfo = process(root->right);

		int depth = std::max(leftInfo.depth, rightInfo.depth) + 1;
		int balance = leftInfo.isBalanced && rightInfo.isBalanced && (abs(leftInfo.depth - rightInfo.depth) < 2);

		return BalanceInfo(balance, depth);
	}
};
