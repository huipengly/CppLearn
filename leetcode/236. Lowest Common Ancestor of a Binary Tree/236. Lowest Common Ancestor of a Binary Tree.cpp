#include <algorithm>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode *> path1, path2;
		if (!path(root, p, path1))
			return nullptr;
		if (!path(root, q, path2))
			return nullptr;
		path1.push_back(p); path2.push_back(q);

		return last_common_node(path1, path2);
	}
private:
	bool path(TreeNode *root, TreeNode *node, vector<TreeNode *> &paths)
	{
		if (root == nullptr)
			return false;
		if (root == node)
			return true;

		paths.push_back(root);
		if (path(root->left, node, paths))
			return true;
		if (path(root->right, node, paths))
			return true;

		paths.pop_back();
		return false;
	}
	TreeNode *last_common_node(vector<TreeNode *> &path1, vector<TreeNode *> &path2)
	{
		if (path1.size() > path2.size())
			swap(path1, path2);
		for (int i = 0; i != path1.size(); ++i)
		{
			if (path1[i]->val != path2[i]->val)
				return path1[i - 1];
		}
		return path1.back();
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	Solution s;
	auto ret = s.lowestCommonAncestor(root, root->left, root);
	return 0;
}