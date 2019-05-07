#include <stack>
#include <vector>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	void recoverTree(TreeNode* root) {
		auto arr = findTwoErrorNodeInBST(root);
		std::swap(arr[0]->val, arr[1]->val);
	}
private:
	vector<TreeNode*> findTwoErrorNodeInBST(TreeNode* head)
	{
		if (head == nullptr)
			return {};

		stack<TreeNode*> stack;
		vector<TreeNode*> err(2, nullptr);
		TreeNode * pre = nullptr;
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
				if (pre != nullptr && pre->val > head->val)
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
};

int main()
{
	TreeNode* head = new TreeNode(1);
	head->left = new TreeNode(3);
	head->left->right = new TreeNode(2);
	Solution s;
	s.recoverTree(head);
	return 0;
}