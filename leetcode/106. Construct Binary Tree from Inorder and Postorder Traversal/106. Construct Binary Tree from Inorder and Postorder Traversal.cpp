#include <string>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.size() != inorder.size())
			return nullptr;
		unordered_map<int, int> map;
		for (int i = 0; i != inorder.size(); ++i)
			map[inorder[i]] = i;
		return buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, map);
	}
private:
	TreeNode* buildTree(const vector<int>& postorder, int pl, int pr,
		const vector<int>& inorder, int il, int ir, const unordered_map<int, int>& map)
	{
		if (pl > pr)
			return nullptr;

		auto* head = new TreeNode(postorder[pr]);
		int i = map.at(postorder[pr]);
		head->right = buildTree(postorder, pr - (ir - i - 1) - 1, pr - 1, inorder, i + 1, ir, map);			
		head->left = buildTree(postorder, pl, pr - (ir - i - 1) - 2, inorder, il, i - 1, map);
		return head;
	}
};