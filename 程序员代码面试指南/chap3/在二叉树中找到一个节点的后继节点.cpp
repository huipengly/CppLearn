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

	// ���node��������Ϊ�գ��򷵻�����������
	if (node->right != nullptr)
	{
		auto* cur = node->right;
		while (cur->left != nullptr)
			cur = cur->left;
		return cur;
	}

	// ���������Ϊ��
	auto* parent = node->parent;

	// ���parentΪ�գ�������ѭ����ֱ�ӷ��ؿ�
	// ���parent��������Ϊnode����ôparent������һ�������Ҳ�����ѭ����ֱ�ӷ���parent
	// ���parent��������Ϊnode����ô��nodeΪparent��ѭ������һ��������Ϊnode��parent���������parent
	while (parent != nullptr && parent->right == node)
	{
		node = parent;
		parent = node->parent;
	}

	return parent;
}