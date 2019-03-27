#include <queue>
using std::queue;

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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;
		// 找A中和B头节点相同的节点
		std::queue<TreeNode *> queue;
		queue.push(pRoot1);
		bool ret = false;
		while (!queue.empty() && !ret)
		{
			auto *node = queue.front();
			if (node->val == pRoot2->val)
				ret = is_same_tree(node, pRoot2);	// 判断从这个节点开始，B是不是子树

			// 继续遍历，如果说ret是真，之后就不会进while。
			queue.pop();
			if (node->left != nullptr) queue.push(node->left);
			if (node->right != nullptr) queue.push(node->right);
		}

		return ret;
	}
private:
	bool is_same_tree(TreeNode *lhs, TreeNode *rhs)		// 这个其实也可以改非递归，用一个queue维护就行
	{
		if (rhs == nullptr)			// B树判断完了，就说明是子树
			return true;
		else if (lhs == nullptr)	// A树完了，B没完，就不是子树
			return false;

		if (lhs->val != rhs->val)	// 有不同的节点，就不是子树
			return false;
		else						// 当前节点相同，继续判断子节点
			return is_same_tree(lhs->left, rhs->left) && is_same_tree(lhs->right, rhs->right);
	}
};
