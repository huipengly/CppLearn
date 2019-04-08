
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* ret = nullptr;
		while (root != nullptr)
		{
			if (root->val > p->val && root->val > q->val)
				root = root->left;
			else if (root->val < p->val && root->val < q->val)
				root = root->right;
			else
			{
				ret = root;
				break;
			}
		}
		return ret;
	}
};