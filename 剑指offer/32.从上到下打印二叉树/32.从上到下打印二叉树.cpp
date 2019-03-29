#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
// DFS
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> ret;
		if (root == nullptr)
			return ret;
		queue<TreeNode *> node_queue;
		node_queue.push(root);
		while (!node_queue.empty())
		{
			auto *node = node_queue.front();
			node_queue.pop();
			ret.push_back(node->val);
			if (node->left != nullptr) node_queue.push(node->left);
			if (node->right != nullptr) node_queue.push(node->right);
		}
		return ret;
	}
};