struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		return (s != nullptr) && (check(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));
	}
private:
	bool check(TreeNode* s, TreeNode* t) {
		if (t == nullptr)
			return true;
		if (s == nullptr)
			return false;

		return (s->val == t->val) && check(s->left, t->left) && check(s->right, t->right);
	}
};

int main()
{
	Solution s;
	TreeNode* head = new TreeNode(3);
	head->left = new TreeNode(4);
	head->left->left = new TreeNode(1);
	head->right = new TreeNode(5);
	head->right->left = new TreeNode(2);
	TreeNode* t = new TreeNode(3);
	t->left = new TreeNode(1);
	t->right = new TreeNode(2);
	auto ret = s.isSubtree(head, t);
	return 0;
}