#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//void printInOrder(TreeNode* head, char to, int len)
//{
//	if (head == nullptr)
//		return;
//
//	printInOrder(head->right, 'v', len + 1);
//	std::string val = to + to_string(head->val) + to;
//	cout << setw(17 * (len + 1)) << val << endl;
//	printInOrder(head->left, '^', len + 1);
//}

// 修改为右对齐，使用了c++的特性
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

int main()
{
	TreeNode* head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->left->right = new TreeNode(4);
	head->left->right->left = new TreeNode(7);
	head->left->right->right = new TreeNode(8);
	head->left->right->right->right = new TreeNode(10002511);
	head->left->right->right->right->left = new TreeNode(13);
	head->left->right->right->right->right = new TreeNode(14);

	head->right = new TreeNode(3);
	head->right->left = new TreeNode(5);
	head->right->right = new TreeNode(6);
	head->right->left->left = new TreeNode(9);
	head->right->left->right = new TreeNode(10);
	head->right->left->left->left = new TreeNode(12);
	head->right->left->left->left->left = new TreeNode(15);
	head->right->left->left->left->right = new TreeNode(16);

	cout << head << endl;
	return 0;
}