#include <queue>
#include <iostream>
#include <vector>
#include <deque>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == nullptr)
			return {};
		deque<TreeNode*> deque;
		deque.push_back(root);
		TreeNode* last = root, * nLast = root, * node = nullptr;
		bool fromLeft = true;
		vector<vector<int>> ret;
		vector<int> level;
		while (!deque.empty())
		{
			if (fromLeft)
			{
				node = deque.front();
				deque.pop_front();
				level.push_back(node->val);
				if (node->left != nullptr)
				{
					deque.push_back(node->left);
					if (last == nLast)
						nLast = node->left;
				}
				if (node->right != nullptr)
				{
					deque.push_back(node->right);
					if (last == nLast)
						nLast = node->right;
				}

				if (node == last)
				{
					ret.push_back(std::move(level));
					fromLeft = false;
					last = nLast;
				}
			}
			else
			{
				node = deque.back();
				deque.pop_back();
				level.push_back(node->val);
				if (node->right != nullptr)
				{
					deque.push_front(node->right);
					if (last == nLast)
						nLast = node->right;
				}
				if (node->left != nullptr)
				{
					deque.push_front(node->left);
					if (last == nLast)
						nLast = node->left;
				}

				if (node == last)
				{
					ret.push_back(std::move(level));
					fromLeft = true;
					last = nLast;
				}
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
	head->left->left = new TreeNode(4);
	head->left->right = new TreeNode(5);
	head->right = new TreeNode(3);
	head->right->right = new TreeNode(6);
	auto ret = s.zigzagLevelOrder(head);
	for (auto& level : ret)
	{
		for (auto& i : level)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}