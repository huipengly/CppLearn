#include <iostream>
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
		bool reverse = false;
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
				print(nodes, reverse);
				nodes.clear();
				reverse = !reverse;
				current = next;
				next = 0;
			}
		}
		return ret;
	}
private:
	vector<vector<int>> ret;
	void print(vector<int> &arr, bool reverse)
	{
		vector<int> result;
		if (reverse)
		{
			for (auto it = arr.crbegin(); it != arr.crend(); ++it)
				result.push_back(*it);
		}
		else
		{
			for (auto it = arr.cbegin(); it != arr.cend(); ++it)
				result.push_back(*it);
		}
		ret.push_back(result);
	}
};

int main()
{
	TreeNode *head = new TreeNode(1);
	head->left = new TreeNode(2);
	//head->left->left = new TreeNode(3);
	//head->left->left->left = new TreeNode(4);
	//head->left->left->right = new TreeNode(4);
	head->right = new TreeNode(3);
	head->left->left = new TreeNode(4);
	head->left->right = new TreeNode(5);
	head->right->left = new TreeNode(6);
	head->right->right = new TreeNode(7);
	Solution s;
	s.PrintFromTopToBottom(head);
	return 0;
}