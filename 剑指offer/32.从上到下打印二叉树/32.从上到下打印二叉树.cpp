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
	vector<vector<int> > Print(TreeNode* pRoot) {
		if (pRoot == nullptr)
			return {};
		queue<TreeNode *> node_queue;
		int current = 1, next = 0;
		vector<int> nodes;
		node_queue.push(pRoot);
		while (!node_queue.empty())
		{
			auto *node = node_queue.front();
			node_queue.pop();
			nodes.push_back(node->val);
			--current;
			if (node->left != nullptr)
			{
				++next;
				node_queue.push(node->left);
			}
			if (node->right != nullptr)
			{
				++next;
				node_queue.push(node->right);
			}
			if (current == 0)
			{
				print(nodes);
				nodes.clear();
				current = next;
				next = 0;
			}
		}
		return ret;
	}
private:
	vector<vector<int>> ret;
	void print(vector<int> &arr)
	{
		vector<int> result;
		for (auto it = arr.cbegin(); it != arr.cend(); ++it)
			result.push_back(*it);
		ret.push_back(result);
	}
};