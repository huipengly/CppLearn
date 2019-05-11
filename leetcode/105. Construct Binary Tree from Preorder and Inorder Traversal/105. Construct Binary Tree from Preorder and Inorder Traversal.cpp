#include <string>
#include <iomanip>
#include <iostream>
#include <unordered_map>
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
	TreeNode* buildTree(const vector<int>& preorder,const vector<int>& inorder) {
		if (preorder.size() != inorder.size())
			return nullptr;
		unordered_map<int, int> map;
		for (int i = 0; i != inorder.size(); ++i)
			map[inorder[i]] = i;
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, map);
	}
private:
	TreeNode* buildTree(const vector<int>& preorder, int pl, int pr,
		const vector<int>& inorder, int il, int ir, const unordered_map<int, int>& map)
	{
		if (pl > pr)
			return nullptr;

		auto* head = new TreeNode(preorder[pl]);
		int i = map.at(preorder[pl]);
		// i为中节点在中序排列的索引，ir - i就是右子树节点个数
		head->right = buildTree(preorder, pr - (ir - i - 1), pr, inorder, i + 1, ir, map);			
		head->left = buildTree(preorder, pl + 1, pr - (ir - i - 1) - 1, inorder, il, i - 1, map);
		return head;
	}
};

// 打印二叉树
void printInOrder(const TreeNode* head, int len, char to, int height, ostream& os)
{
	if (head == nullptr)
		return;

	printInOrder(head->right, len + 1, 'v', height, os);
	std::string val = to + to_string(head->val) + to;
	os << setw(height * (len + 1)) << val << endl;
	printInOrder(head->left, len + 1, '^', height, os);
}

void printTree(const TreeNode * head, ostream & os)
{
	os << "Binary Tree:" << endl;
	printInOrder(head, 0, 'H', 17, os);
	os << endl;
}

ostream& operator<<(ostream & os, const TreeNode * head)
{
	printTree(head, os);
	return os;
}
// 打印二叉树

int main()
{
	Solution s;
	cout << s.buildTree({ 3, 9, 20, 15, 7 }, { 9, 3, 15, 20, 7 }) << endl;

	return 0;
}