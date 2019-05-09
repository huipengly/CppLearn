#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		if (preorder.empty())
			return nullptr;
		return bstFromPreorder(preorder, 0, preorder.size() - 1);
	}
private:
	TreeNode* bstFromPreorder(vector<int>& preorder, int start, int end)
	{
		if (start > end)
			return nullptr;

		int less = 0, more = end + 1;		// 这里end+1很重要，如果more不更新，那么要让右子树为null，所以more要比end大
		for (int i = start + 1; i <= end; ++i)
		{
			if (preorder[i] < preorder[start])
				less = i;
			else
				more = more == end + 1 ? i : more;
		}
		TreeNode* head = new TreeNode(preorder[start]);
		head->left = bstFromPreorder(preorder, start + 1, less);
		head->right = bstFromPreorder(preorder, more, end);
		
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
	vector<int> preorder{ 8,5,1,7,10,12 };
	cout << s.bstFromPreorder(preorder) << endl;
	return 0;
}