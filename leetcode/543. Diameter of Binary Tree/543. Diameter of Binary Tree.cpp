#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		return process(root).diameter;
	}
private:
	struct ReturnType
	{
		int diameter;
		int depth;
	};
	ReturnType process(TreeNode* root) {
		if (root == nullptr)
			return {0, 0};

		auto lData = process(root->left);
		auto rData = process(root->right);
		return { std::max(std::max(lData.diameter, rData.diameter), lData.depth + rData.depth),
				std::max(lData.depth, rData.depth) + 1 };
	}
};