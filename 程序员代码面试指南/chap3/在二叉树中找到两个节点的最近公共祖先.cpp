struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode* lowestAncestor(TreeNode* head, TreeNode* o1, TreeNode* o2)
{
	if (head == nullptr || head == o1 || head == o2)
		return head;

	auto* left = lowestAncestor(head->left, o1, o2);
	auto* right = lowestAncestor(head->right, o1, o2);

	if (left != nullptr && right != nullptr)
		return head;

	return left != nullptr ? left : right;
}