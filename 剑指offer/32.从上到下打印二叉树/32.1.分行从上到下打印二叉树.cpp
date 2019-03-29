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
	void PrintFromTopToBottom(TreeNode* root) {
		if (root == nullptr)
			return;
		queue<TreeNode *> node_queue;
		int current = 1, next = 0;
		node_queue.push(root);
		while (!node_queue.empty())
		{
			auto *node = node_queue.front();
			node_queue.pop();
			cout << node->val;
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
				cout << endl;
				current = next;
				next = 0;
			}
			else
			{
				cout << " ";
			}
		}
	}
};

int main()
{
	TreeNode *head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->left->left = new TreeNode(3);
	head->left->left->left = new TreeNode(4);
	head->left->left->right = new TreeNode(4);
	//head->right = new TreeNode(3);
	//head->left->left = new TreeNode(4);
	//head->left->right = new TreeNode(5);
	//head->right->left = new TreeNode(6);
	//head->right->right = new TreeNode(7);
	Solution s;
	s.PrintFromTopToBottom(head);
	return 0;
}