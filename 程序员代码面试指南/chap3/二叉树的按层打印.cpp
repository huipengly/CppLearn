#include <queue>
#include <iostream>
#include <vector>
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		if (pRoot == nullptr)
			return {};
		TreeNode* last = pRoot, * nLast = nullptr, * node = nullptr;
		queue<TreeNode*> queue;
		queue.push(pRoot);
		vector<vector<int>> ret;
		vector<int> level;
		while (!queue.empty())
		{
			node = queue.front();
			queue.pop();
			level.push_back(node->val);
			if (node->left != nullptr)
			{
				queue.push(node->left);
				nLast = node->left;
			}
			if (node->right != nullptr)
			{
				queue.push(node->right);
				nLast = node->right;
			}

			if (node == last)
			{
				ret.push_back(std::move(level));
				last = nLast;
			}
		}
		return ret;
	}

};

int main()
{
	Solution s;
	TreeNode* head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->right = new TreeNode(3);
	auto ret = s.Print(head);
	for (auto& level : ret)
	{
		for (auto& i : level)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}