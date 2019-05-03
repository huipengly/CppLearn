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
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr)
			return pRootOfTree;

		auto* left = Convert(pRootOfTree->left);
		auto* right = Convert(pRootOfTree->right);
		TreeNode* head = nullptr, * tail = nullptr;
		if (left != nullptr)
		{
			head = left;
			tail = left;
			while (tail->right != nullptr)
				tail = tail->right;
		}

		pRootOfTree->left = tail;
		if (tail != nullptr)
		{
			tail->right = pRootOfTree;
			tail = pRootOfTree;
		}
		else
			head = pRootOfTree;

		pRootOfTree->right = right;
		if (right != nullptr)
			right->left = pRootOfTree;
		return head;
	}
};

int main()
{
	TreeNode* head = new TreeNode(10);
	head->left = new TreeNode(6);
	head->left->left = new TreeNode(4);
	head->left->right = new TreeNode(8);
	head->right = new TreeNode(14);
	head->right->left = new TreeNode(12);
	head->right->right = new TreeNode(16);

	Solution s;
	auto* ret = s.Convert(head);
	return 0;
}