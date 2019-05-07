#include <vector>
#include <stack>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> findTwoErrorNodeInBST(TreeNode* head)
{
	if (head == nullptr)
		return {};

	stack<TreeNode*> stack;
	vector<TreeNode*> err(2, nullptr);
	TreeNode* pre = nullptr;
	while (!stack.empty() || head != nullptr)
	{
		if (head != nullptr)
		{
			stack.push(head);
			pre = head;
			head = head->left;
		}
		else
		{
			head = stack.top();
			stack.pop();
			if (pre != nullptr && pre->val < head->val)
			{
				err[0] = err[0] == nullptr ? pre : err[0];
				err[1] = head;
			}
			pre = head;
			head = head->right;
		}
	}
	return err;
}

vector<TreeNode*> findTwoErrorNodeParents(TreeNode* head, const vector<TreeNode*>& err)
{
	if (head == nullptr)
		return {};
	stack<TreeNode*> stack;
	vector<TreeNode*> parents(2, nullptr);
	while (!stack.empty() || head != nullptr)
	{
		if (head != nullptr)
		{
			stack.push(head);
			head = head->left;
		}
		else
		{
			head = stack.top();
			stack.pop();
			if (head->left == err[0] || head->right == err[0])
				parents[0] = err[0];
			if (head->left == err[1] || head->right == err[1])
				parents[1] = err[1];
			head = head->right;
		}
	}
	return parents;
}

void recoverTree(TreeNode* head)
{
	if (head == nullptr)
		return;
	auto err = findTwoErrorNodeInBST(head);
	auto parents = findTwoErrorNodeParents(head, err);
	// ½»»»Ã»Ð´
}