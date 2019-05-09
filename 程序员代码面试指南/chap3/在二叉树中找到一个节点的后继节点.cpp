struct TreeNodeWithParent
{
	int val;
	TreeNodeWithParent* left;
	TreeNodeWithParent* right;
	TreeNodeWithParent* parent;
	TreeNodeWithParent(int val) : val(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

TreeNodeWithParent* inorderSuccessorInBST(TreeNodeWithParent* node)
{
	if (node == nullptr)
		return nullptr;

	// 如果node右子树不为空，则返回右子树最左
	if (node->right != nullptr)
	{
		auto* cur = node->right;
		while (cur->left != nullptr)
			cur = cur->left;
		return cur;
	}

	// 如果右子树为空
	auto* parent = node->parent;

	// 如果parent为空，不进入循环，直接返回空
	// 如果parent的左子树为node，那么parent就是下一个，而且不进入循环，直接返回parent
	// 如果parent的右子树为node，那么令node为parent，循环搜索一个左子树为node的parent，返回这个parent
	while (parent != nullptr && parent->right == node)
	{
		node = parent;
		parent = node->parent;
	}

	return parent;
}